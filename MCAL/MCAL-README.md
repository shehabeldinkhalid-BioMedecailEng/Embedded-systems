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
