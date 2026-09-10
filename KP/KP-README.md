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

### KPAD — 4x4 Matrix Keypad (`KPAD.h` / `KPAD.c` / `KPAD_cfg.h`)
Row/column scanning driver for a 4x4 matrix keypad.

- `KPAD_voidInit` — configures rows as pulled-up inputs, columns as outputs
- `KPAD_u8GetKeyPressed` — scans columns one at a time and returns the pressed
  key's character (from the `Kpad_mat` layout) or `255` if no key is pressed

Row/column pin assignments live in `KPAD_cfg.h`.

---
eRTOSConfig.h`, `RTOS/task.h`) to be present in the project.
