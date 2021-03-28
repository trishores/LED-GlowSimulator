/*
 *  Copyright 2018-2021 ledmaker.org
 *
 *  This file is part of Glow Simulator.
 *
 *  Glow Simulator is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published
 *  by the Free Software Foundation, either version 3 of the License,
 *  or any later version.
 *
 *  Glow Simulator is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Glow Simulator. If not, see https://www.gnu.org/licenses/.
 */

#ifndef LEDSTRIP_DRIVER_H_
#define LEDSTRIP_DRIVER_H_

#define INNER_LED_COUNT 4
#define OUTER_LED_COUNT 8
#define SIDE_LED_COUNT 8
#define NB_CONFIG_BYTES_PER_LED 4		// 4 configuration bytes per led: red, green, blue, bright.
#define TOTAL_LED_CONFIG_BUF_SZ (MAX_LED_COUNT * NB_CONFIG_BYTES_PER_LED)

typedef struct
{
	uint8_t red;
	uint8_t green;
	uint8_t blue;
	float alpha;
} SimLed;
extern SimLed simLedstrip[LED_COUNT];

#endif /* LEDSTRIP_DRIVER_H_ */