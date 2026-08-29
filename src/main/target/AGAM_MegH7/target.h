/*
 * This file is part of INAV Project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Alternatively, the contents of this file may be used under the terms
 * of the GNU General Public License Version 3, as described below:
 *
 * This file is free software: you may copy, redistribute and/or modify
 * it under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * This file is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see http://www.gnu.org/licenses/.
 */

#pragma once

#define TARGET_BOARD_IDENTIFIER "AGM7"

#define USBD_PRODUCT_STRING     "Agam MegH7"

#define USE_TARGET_CONFIG

// *************** LEDs ****************************
#define LED0                    PE4     // blue
#define LED1                    PE3     // red

// *************** Beeper **************************
#define BEEPER                  PA15
#define BEEPER_INVERTED
#define BEEPER_PWM_FREQUENCY    2500

// *************** UARTs ***************************
#define USE_VCP

#define USE_UART1                       // GPS
#define UART1_TX_PIN            PA9
#define UART1_RX_PIN            PA10

#define USE_UART2                       // DIGI VTX
#define UART2_TX_PIN            PD5
#define UART2_RX_PIN            PD6

#define USE_UART3                       // spare
#define UART3_TX_PIN            PD8
#define UART3_RX_PIN            PD9

#define USE_UART4                       // spare
#define UART4_TX_PIN            PB9
#define UART4_RX_PIN            PB8

#define USE_UART6                       // RC input
#define UART6_TX_PIN            PC6
#define UART6_RX_PIN            PC7

#define USE_UART7                       // TELEM
#define UART7_TX_PIN            PE8
#define UART7_RX_PIN            PE7

#define USE_UART8                       // ESC telemetry
#define UART8_TX_PIN            PE1
#define UART8_RX_PIN            PE0

#define SERIAL_PORT_COUNT       8

// *************** SPI *****************************
#define USE_SPI

#define USE_SPI_DEVICE_1                // dataflash
#define SPI1_SCK_PIN            PA5
#define SPI1_MISO_PIN           PA6
#define SPI1_MOSI_PIN           PD7

#define USE_SPI_DEVICE_2                // IMU
#define SPI2_SCK_PIN            PB13
#define SPI2_MISO_PIN           PB14
#define SPI2_MOSI_PIN           PB15

#define USE_SPI_DEVICE_3                // OSD
#define SPI3_SCK_PIN            PB3
#define SPI3_MISO_PIN           PB4
#define SPI3_MOSI_PIN           PB5

#define USE_SPI_DEVICE_4                // SPI4 external connector
#define SPI4_SCK_PIN            PE12
#define SPI4_MISO_PIN           PE13
#define SPI4_MOSI_PIN           PE14

// *************** IMU *****************************
#define USE_IMU_ICM45686
#define IMU_ICM45686_ALIGN      CW90_DEG_FLIP
#define ICM45686_SPI_BUS        BUS_SPI2
#define ICM45686_CS_PIN         PD11

// *************** OSD *****************************
#define USE_MAX7456
#define MAX7456_SPI_BUS         BUS_SPI3
#define MAX7456_CS_PIN          PD10

// *************** I2C *****************************
#define USE_I2C

#define USE_I2C_DEVICE_1                // GPS connector, SD1/SC1 pads
#define I2C1_SCL                PB6
#define I2C1_SDA                PB7

#define USE_I2C_DEVICE_2                // on-board barometer
#define I2C2_SCL                PB10
#define I2C2_SDA                PB11

#define USE_I2C_DEVICE_4                // I2C4 connector, SD4/SC4 pads
#define I2C4_SCL                PD12
#define I2C4_SDA                PD13

// *************** Baro/Mag ************************
#define USE_BARO
#define USE_BARO_BMP388
#define USE_BARO_BMP390
#define USE_BARO_SPL06
#define BARO_I2C_BUS            BUS_I2C2

// no on-board compass, probe the external bus for all supported types
#define USE_MAG
#define USE_MAG_ALL
#define MAG_I2C_BUS             BUS_I2C1

#define TEMPERATURE_I2C_BUS     BUS_I2C1
#define PITOT_I2C_BUS           BUS_I2C1

#define USE_RANGEFINDER
#define RANGEFINDER_I2C_BUS     BUS_I2C1

// *************** Onboard storage *****************
#define USE_SDCARD
#define USE_SDCARD_SDIO
#define SDCARD_SDIO_DEVICE      SDIODEV_1
#define SDCARD_SDIO_4BIT
#define ENABLE_BLACKBOX_LOGGING_ON_SDCARD_BY_DEFAULT

// W25Q128 dataflash. This is an assembly option and is not populated on
// every board, so the SD card stays the default blackbox device.
#define USE_FLASHFS
#define USE_FLASH_M25P16
#define M25P16_SPI_BUS          BUS_SPI1
#define M25P16_CS_PIN           PE11

// *************** ADC *****************************
#define USE_ADC
#define ADC_INSTANCE                ADC1

#define ADC_CHANNEL_1_PIN           PC0     // battery voltage
#define ADC_CHANNEL_2_PIN           PC1     // battery current
#define ADC_CHANNEL_3_PIN           PC5     // RSSI
#define ADC_CHANNEL_4_PIN           PC4     // ADC-EXT1, marked A1
#define ADC_CHANNEL_5_PIN           PA4     // ADC-EXT2, marked A2

#define VBAT_ADC_CHANNEL            ADC_CHN_1
#define CURRENT_METER_ADC_CHANNEL   ADC_CHN_2
#define RSSI_ADC_CHANNEL            ADC_CHN_3
#define AIRSPEED_ADC_CHANNEL        ADC_CHN_4

#define VBAT_SCALE_DEFAULT          1100
#define CURRENT_METER_SCALE         250

// *************** PINIO ***************************
// PINIO1 gates the 10V rail to the DIGI VTX connector through a high-side
// switch. config.c binds it to USER1 and leaves it permanently on.
#define USE_PINIO
#define USE_PINIOBOX
#define PINIO1_PIN                  PE5
#define PINIO2_PIN                  PE15
#define PINIO3_PIN                  PE6
#define PINIO4_PIN                  PA7     // camera control pad, marked CC

// *************** LED strip ***********************
#define USE_LED_STRIP
#define WS2811_PIN                  PA8

// *************** Outputs *************************
// M8 is on PD15/TIM4_CH4, which has no per-channel DMAMUX request on the
// H743. USE_DSHOT_DMAR repoints it at the TIM4_UP burst request so the
// output keeps a valid DMA path, at the cost of one shared burst stream
// per timer.
#define USE_DSHOT
#define USE_DSHOT_DMAR
#define USE_ESC_SENSOR
#define USE_SERIAL_4WAY_BLHELI_INTERFACE

#define MAX_PWM_OUTPUT_PORTS        8

// *************** Defaults ************************
#define DEFAULT_FEATURES        (FEATURE_OSD | FEATURE_TELEMETRY | FEATURE_CURRENT_METER | FEATURE_VBAT | FEATURE_TX_PROF_SEL | FEATURE_BLACKBOX)

#define DEFAULT_RX_TYPE         RX_TYPE_SERIAL
#define SERIALRX_PROVIDER       SERIALRX_CRSF
#define SERIALRX_UART           SERIAL_PORT_USART6

#define TARGET_IO_PORTA         (0xffff & ~(BIT(13) | BIT(14)))
#define TARGET_IO_PORTB         0xffff
#define TARGET_IO_PORTC         0xffff
#define TARGET_IO_PORTD         0xffff
#define TARGET_IO_PORTE         0xffff
