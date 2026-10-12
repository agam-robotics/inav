/*
 * This file is part of INAV.
 *
 * INAV is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * INAV is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with INAV.  If not, see <http://www.gnu.org/licenses/>.
 */


#pragma once

#define TARGET_BOARD_IDENTIFIER "H743"

#define USBD_PRODUCT_STRING     "AGAM_MEGH7"

#define USE_TARGET_CONFIG

#define LED0                    PE4
#define LED1                    PE3

#define BEEPER                  PA15
#define BEEPER_INVERTED
#define BEEPER_PWM_FREQUENCY    2500

// *************** IMU generic ***********************
#define USE_DUAL_GYRO
#define USE_TARGET_IMU_HARDWARE_DESCRIPTORS

// *************** SPI1 FLASH ***********************
#define USE_SPI
#define USE_SPI_DEVICE_1
#define SPI1_SCK_PIN            PA5
#define SPI1_MISO_PIN           PA6
#define SPI1_MOSI_PIN           PD7

// #define M25P16_CS_PIN PE11
// #define M25P16_SPI_BUS BUS_SPI1

// #define USE_BLACKBOX
// #define USE_FLASHFS
// #define USE_FLASH_M25P16
// #define ENABLE_BLACKBOX_LOGGING_ON_SPIFLASH_BY_DEFAULT

// *************** SPI2 IMU1  ICM42605/ICM42688P **************
#define USE_SPI_DEVICE_2
#define SPI2_SCK_PIN            PB13
#define SPI2_MISO_PIN           PB14
#define SPI2_MOSI_PIN           PB15

#define USE_IMU_ICM45686

#define GYRO_1_SPI_BUS          BUS_SPI2
#define GYRO_1_CS_PIN           PD11
#define GYRO_1_EXTI_PIN         PB2
#define GYRO_1_ALIGN            CW90_DEG

// *************** SPI3 OSD ***********************
#define USE_SPI_DEVICE_3
#define SPI3_SCK_PIN            PB3
#define SPI3_MISO_PIN           PB4
#define SPI3_MOSI_PIN           PB5

#define USE_MAX7456
#define MAX7456_SPI_BUS         BUS_SPI3
#define MAX7456_CS_PIN          PD10

// *************** SPI4 SPARE FOR EXT CONNECTOR ***********
#define USE_SPI_DEVICE_4
#define SPI4_SCK_PIN            PE12
#define SPI4_MISO_PIN           PE13
#define SPI4_MOSI_PIN           PE14


// Motor/servo DMA note: SERVO4_PIN (PD15/TIM4_CH4) has no per-channel DMAMUX
// request on this MCU; USE_DSHOT_DMAR repoints TIM4_CH4 at the TIM4_UP burst
// request so the channel keeps a valid DMA path. This makes all DSHOT-capable
// outputs use one shared burst DMA stream per timer

// #define USE_DSHOT_DMAR

// *************** I2C /Baro/Mag *********************
#define USE_I2C
#define USE_I2C_DEVICE_1
#define I2C1_SCL                PB6
#define I2C1_SDA                PB7

#define USE_I2C_DEVICE_2
#define I2C2_SCL                PB10
#define I2C2_SDA                PB11

#define USE_I2C_DEVICE_4
#define I2C4_SCL                PD12
#define I2C4_SDA                PD13

#define USE_BARO
#define BARO_I2C_BUS            BUS_I2C2
#define USE_BARO_BMP388
#define USE_BARO_BMP390

#define USE_MAG
#define MAG_I2C_BUS             BUS_I2C1
#define USE_MAG_ALL

// *************** UART *****************************
#define USE_VCP

#define USE_UART1
#define UART1_TX_PIN            PA9
#define UART1_RX_PIN            PA10

#define USE_UART2
#define UART2_TX_PIN            PD5
#define UART2_RX_PIN            PD6

#define USE_UART3
#define UART3_TX_PIN            PD8
#define UART3_RX_PIN            PD9

#define USE_UART4
#define UART4_TX_PIN            PB9
#define UART4_RX_PIN            PB8

#define USE_UART6
#define UART6_TX_PIN            PC6
#define UART6_RX_PIN            PC7

#define USE_UART7
#define UART7_TX_PIN            PE8
#define UART7_RX_PIN            PE7

#define USE_UART8
#define UART8_TX_PIN            PE1
#define UART8_RX_PIN            PE0

#define SERIAL_PORT_COUNT       8

#define DEFAULT_RX_TYPE         RX_TYPE_SERIAL
#define SERIALRX_PROVIDER       SERIALRX_CRSF
#define SERIALRX_UART           SERIAL_PORT_USART6

// *************** SDIO SD BLACKBOX*******************
#define USE_SDCARD
#define USE_SDCARD_SDIO
#define SDCARD_SDIO_DEVICE      SDIODEV_1
#define SDCARD_SDIO_4BIT

#define ENABLE_BLACKBOX_LOGGING_ON_SDCARD_BY_DEFAULT

// *************** ENABLE OPTICAL FLOW & RANGEFINDER *****************************
#define USE_RANGEFINDER
#define USE_RANGEFINDER_MSP
#define USE_OPFLOW
#define USE_OPFLOW_MSP

// *************** ADC *****************************
#define USE_ADC
#define ADC_INSTANCE                ADC1

#define ADC_CHANNEL_1_PIN           PC0  //ADC123 VBAT1
#define ADC_CHANNEL_2_PIN           PC1  //ADC123 CURR1
#define ADC_CHANNEL_3_PIN           PC5  //ADC12  RSSI
#define ADC_CHANNEL_4_PIN           PC4  //ADC12  AirS
#define ADC_CHANNEL_5_PIN           PA4  //ADC12  VB2

#define VBAT_ADC_CHANNEL            ADC_CHN_1
#define CURRENT_METER_ADC_CHANNEL   ADC_CHN_2
#define RSSI_ADC_CHANNEL            ADC_CHN_3
#define AIRSPEED_ADC_CHANNEL        ADC_CHN_4

// *************** PINIO ***************************
#define USE_PINIO
#define USE_PINIOBOX
#define PINIO1_PIN                  PE5  // VTX power switcher
#define PINIO2_PIN                  PE15  // 2xCamera switcher
#define PINIO3_PIN                  PE6

// *************** LEDSTRIP ************************
#define USE_LED_STRIP
#define WS2811_PIN                  PA8

#define DEFAULT_FEATURES            (FEATURE_OSD | FEATURE_LED_STRIP | FEATURE_TELEMETRY | FEATURE_CURRENT_METER | FEATURE_VBAT | FEATURE_TX_PROF_SEL | FEATURE_BLACKBOX)
#define CURRENT_METER_SCALE         125

#define USE_SERIAL_4WAY_BLHELI_INTERFACE

#define TARGET_IO_PORTA 0xffff
#define TARGET_IO_PORTB 0xffff
#define TARGET_IO_PORTC 0xffff
#define TARGET_IO_PORTD 0xffff
#define TARGET_IO_PORTE 0xffff

#define MAX_PWM_OUTPUT_PORTS        10
#define USE_DSHOT
#define USE_ESC_SENSOR

