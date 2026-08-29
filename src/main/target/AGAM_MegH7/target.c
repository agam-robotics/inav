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

#include <stdint.h>

#include "platform.h"

#include "drivers/io.h"
#include "drivers/pwm_mapping.h"
#include "drivers/timer.h"

/*
 * The ICM45686 bus device is registered by target/common_hardware.c from the
 * ICM45686_* defines in target.h, so it is deliberately not repeated here.
 */

timerHardware_t timerHardware[] = {
    DEF_TIM(TIM3, CH3, PB0,  TIM_USE_OUTPUT_AUTO, 0, 0),   // M1
    DEF_TIM(TIM3, CH4, PB1,  TIM_USE_OUTPUT_AUTO, 0, 1),   // M2

    DEF_TIM(TIM5, CH1, PA0,  TIM_USE_OUTPUT_AUTO, 0, 2),   // M3
    DEF_TIM(TIM5, CH2, PA1,  TIM_USE_OUTPUT_AUTO, 0, 3),   // M4
    DEF_TIM(TIM5, CH3, PA2,  TIM_USE_OUTPUT_AUTO, 0, 4),   // M5
    DEF_TIM(TIM5, CH4, PA3,  TIM_USE_OUTPUT_AUTO, 0, 5),   // M6

    DEF_TIM(TIM4, CH3, PD14, TIM_USE_OUTPUT_AUTO, 0, 6),   // M7
    DEF_TIM(TIM4, CH4, PD15, TIM_USE_OUTPUT_AUTO, 0, 7),   // M8 - needs USE_DSHOT_DMAR, see target.h

    DEF_TIM(TIM1, CH1, PA8,  TIM_USE_LED, 0, 9),           // LED strip

    DEF_TIM(TIM2, CH1, PA15, TIM_USE_BEEPER, 0, 0),        // buzzer
};

const int timerHardwareCount = sizeof(timerHardware) / sizeof(timerHardware[0]);
