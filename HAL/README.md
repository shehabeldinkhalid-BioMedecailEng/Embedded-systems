# AVR Embedded Drivers — ATmega32

A layered AVR driver stack (UTIL / MCAL / HAL) built for the ATmega32, following
the standard AUTOSAR-style layering taught in the AMIT Embedded Systems Diploma:
`UTIL` (generic helpers) → `MCAL` (microcontroller peripherals) → `HAL`
(external hardware modules) → `APP` (application/main).

## Project Structure

```
UTIL/
  std_types.h        Standard fixed-width type aliases
  bit_math.h          Bit manipulation macros
MCAL/
  register_def.h      Direct register address mapping for ATmega32
  DIO/                 Digital I/O driver
    dio.h / dio.c
  ADC/                 Analog-to-Digital Converter driver
    ADC_int.h / ADC_prog.c
  EXTI/                External interrupt driver
    EXTI.h / EXTI.c
  GIE/                 Global interrupt enable/disable
    GIE_.h / GIE.c
HAL/
  CLCD/                Character LCD driver (4-bit / 8-bit)
    CLCD_int.h / CLCD_prog.c / CLCD_cofig.h
  KPAD/                4x4 Keypad driver
    KPAD.h / KPAD.c / KPAD_cfg.h
APP/
  CMAIN.c              FreeRTOS multitasking demo (3 LED tasks)
  main.c               Bare-metal Timer0 overflow LED blink (reference/legacy)
```

---

## UTIL Layer

### `std_types.h`
Defines portable fixed-width type aliases used across every layer:
`u8/u16/u32/u64` (unsigned), `s8/s16/s32/s64` (signed), `f32/f64` (float).

### `bit_math.h`
Generic register bit-manipulation macros used everywhere in MCAL/HAL:

| Macro | Effect |
|---|---|
| `SET_BIT(reg,bit)` | Sets a bit to 1 |
| `CLR_BIT(reg,bit)` | Clears a bit to 0 |
| `TOG_BIT(reg,bit)` | Toggles a bit |
| `GET_BIT(reg,bit)` | Reads a bit's value |

---

## MCAL Layer

### `register_def.h`
Maps ATmega32 SFR addresses (PORT/DDR/PIN for A–D, ADC registers, external
interrupt registers, Timer0 registers) to volatile pointers so the drivers
above never hard-code raw addresses.

### DIO — Digital I/O (`dio.h` / `dio.c`)
Pin- and port-level digital I/O control.

- `DIO_voidSetPinDir` / `DIO_voidSetPortDir` — configure direction (input/output)
- `DIO_voidSetPinVal` / `DIO_voidSetPortVal` — drive a pin/port high or low
- `DIO_u8GetPinVal` / `DIO_u8GetPortVal` — read a pin/port
- `DIO_togglePin` — toggle a pin
- `DIO_voidEnablePullUp` — enable internal pull-up on an input pin

Ports/pins are addressed with symbolic IDs (`DIO_PORTA`..`DIO_PORTD`,
`DIO_PIN0`..`DIO_PIN7`) rather than raw register access.

### ADC — Analog-to-Digital Converter (`ADC_int.h` / `ADC_prog.c`)
Single-conversion, polling-based ADC driver.

- `ADC_voidInit` — sets prescaler to /128, reference voltage to AVCC, enables the ADC
- `ADC_u16StartConversion(channel)` — selects a channel (`ADC_CHANNEL_0`..`7`),
  starts a conversion, polls the ADIF flag, and returns the 10-bit result

### EXTI — External Interrupts (`EXTI.h` / `EXTI.c`)
Configures INT0/INT1/INT2 sense control and enable/disable.

- `Enable_INT0/1/2`, `Disable_INT0/1/2`
- `EXTINT_voidChangeSenseControl(id, sense)` — sets trigger mode per interrupt
  line (`EXTINT_lowlevel`, `EXTINT_anychange`, `EXTINT_falling`, `EXTINT_rising`;
  INT2 only supports falling/rising)

### GIE — Global Interrupt Enable (`GIE_.h` / `GIE.c`)
Thin wrapper around the AVR `sei`/`cli` instructions.

- `GIE_voidEnableGlobalInterrupt` — executes `sei`
- `GIE_voidDisableGlobalInterrupt` — intended to execute `cli`

---

## HAL Layer

### CLCD — Character LCD (`CLCD_int.h` / `CLCD_prog.c` / `CLCD_cofig.h`)
Driver for HD44780-compatible character LCDs, supporting both 4-bit and 8-bit
modes via `CLCD_cofig.h` (`CLCD_MODE` set to `CLCD_4_BIT` or `CLCD_8_BIT`).

- `CLCD_voidInit` — runs the standard LCD init sequence for the configured mode
- `CLCD_voidSendCommand` / `CLCD_voidSendData` — low-level command/data write
- `CLCD_voidSendString` — writes a null-terminated string
- `CLCD_voidSetCursorPosition(x, y)` — moves the cursor to (column, row)
- `CLCD_voidClearDisplay` — clears the screen
- `CLCD_voidSenSpecialChar` — writes a custom character (CGRAM) at a position

Pin mapping (data port, control port, RS/RW/E pins) is configured entirely in
`CLCD_cofig.h`.

### KPAD — 4x4 Matrix Keypad (`KPAD.h` / `KPAD.c` / `KPAD_cfg.h`)
Row/column scanning driver for a 4x4 matrix keypad.

- `KPAD_voidInit` — configures rows as pulled-up inputs, columns as outputs
- `KPAD_u8GetKeyPressed` — scans columns one at a time and returns the pressed
  key's character (from the `Kpad_mat` layout) or `255` if no key is pressed

Row/column pin assignments live in `KPAD_cfg.h`.

---

## Application Layer

### `CMAIN.c`
FreeRTOS demo: creates three tasks (`TasK1` idle, `TasK2` and `TasK3` blinking
`PORTA` pins 1 and 2 at different periods using `vTaskDelay`) and starts the
scheduler.

### `main.c`
Currently fully commented out — a bare-metal reference implementation using
Timer0 overflow interrupts to blink two LEDs at different rates without an RTOS.

---

## Known Issues / TODO

- **`EXTI.c` — `Disable_INT2()`** clears `GICR_INT1` instead of `GICR_INT2` (copy-paste bug).
- **`GIE.c` — `GIE_voidDisableGlobalInterrupt()`** has an empty inline `__asm("")`
  instead of `__asm("cli")`, so it currently does nothing.
- **`dio.c` — `DIO_u8GetPortVal()`** calls `GET_BIT(PINx_REG, Copy_u8PortID)`,
  which reads a single bit at an index equal to the port ID rather than
  returning the full port value.
- **`register_def.h`** defines `TIMER_TIMSK_REG` twice (once for TIMSK, once
  reused for TIFR at a different address) — the second definition shadows the
  first, so `TIMSK`-related bit names (`OCIE0`/`TOIE0`) currently resolve to
  the TIFR address.
- Include paths are inconsistent in case (`util/` vs `UTIL/`) between `dio.c`
  and other files — fine on case-insensitive filesystems, but will break the
  build on Linux/macOS.

---

## Build Notes

- Target: ATmega32 (`register_def.h` addresses are ATmega32-specific).
- `F_CPU` is defined as `16000000UL` in files using `<util/delay.h>`.
- `CMAIN.c` requires FreeRTOS sources/headers (`RTOS/FreeRTOS.h`,
  `RTOS/FreeRTOSConfig.h`, `RTOS/task.h`) to be present in the project.
