# Board - [Agam MegH7](https://www.agamrobotics.com/agammegh7)

The Agam MegH7 is an STM32H743 flight controller with an ICM-45686 IMU, a
BMP390 barometer, an AT7456E analog OSD, a microSD slot and eight motor
outputs.

## Sensors

| Sensor  | Part           | Bus                          |
|---------|----------------|------------------------------|
| IMU     | ICM-45686      | SPI2                         |
| Barometer | BMP390 (SPL06 also probed) | I2C2             |
| Compass | none on board  | probed on I2C1               |
| OSD     | AT7456E (MAX7456-compatible) | SPI3           |

There is no on-board compass. Connect an external one to the GPS plug or the
`SD1`/`SC1` pads, both of which are I2C1.

## I2C

Two I2C buses are broken out:

| Bus  | Available on                                 |
|------|----------------------------------------------|
| I2C1 | the GPS connector, and the `SD1` / `SC1` pads |
| I2C4 | the I2C4 connector, and the `SD4` / `SC4` pads |

I2C2 carries the on-board barometer and is not broken out. Compass, pitot,
rangefinder and temperature sensors default to I2C1.

## Serial ports

| INAV port | UART  | Connector / pads      |
|-----------|-------|-----------------------|
| 1         | UART1 | GPS                   |
| 2         | UART2 | DIGI VTX              |
| 3         | UART3 | `T3` / `R3` pads      |
| 4         | UART4 | `T4` / `R4` pads      |
| 5         | UART6 | RX (serial RC input)  |
| 6         | UART7 | TELEM                 |
| 7         | UART8 | ESC telemetry         |

Serial RC input defaults to UART6 with CRSF.

## Outputs

Eight motor outputs plus an addressable LED strip pad:

| Output | Pin  | Timer     |
|--------|------|-----------|
| M1     | PB0  | TIM3_CH3  |
| M2     | PB1  | TIM3_CH4  |
| M3     | PA0  | TIM5_CH1  |
| M4     | PA1  | TIM5_CH2  |
| M5     | PA2  | TIM5_CH3  |
| M6     | PA3  | TIM5_CH4  |
| M7     | PD14 | TIM4_CH3  |
| M8     | PD15 | TIM4_CH4  |
| LED    | PA8  | TIM1_CH1  |

M8 sits on TIM4_CH4, which has no per-channel DMAMUX request on the H743, so
this target is built with `USE_DSHOT_DMAR`. All DShot-capable outputs
therefore share one burst DMA stream per timer.

## Blackbox

Logging defaults to the microSD card, which is fitted on every board.

Some boards are also populated with a 16MB W25Q128 SPI dataflash. Where it is
present, select it with `blackbox_device = SPIFLASH`.

## PINIO

| PINIO | Pin  | Function                                            |
|-------|------|-----------------------------------------------------|
| 1     | PE5  | 10V rail to the DIGI VTX connector (on by default)   |
| 2     | PE15 | spare                                                |
| 3     | PE6  | spare                                                |
| 4     | PA7  | camera control pad, marked `CC`                      |

PINIO1 is bound to USER1 and held on, so the VTX is powered without needing
an RC switch assigned. Turn it off by reassigning USER1 to a switch.

## Analog inputs

`A1` (PC4) and `A2` (PA4) are spare analog pads that connect directly to the
processor with no divider, so 3.3V maximum. `A1` is the default airspeed
channel.
