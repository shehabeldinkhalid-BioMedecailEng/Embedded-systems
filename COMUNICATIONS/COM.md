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
