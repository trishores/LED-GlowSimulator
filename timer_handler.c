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

#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

static uint16_t _tickIntervalMs;
static clock_t prevTicks;

void ClockInit(void)
{
	prevTicks = clock();
}

void WaitForIntervalElapse()
{
	clock_t elapsedTicks;
	unsigned long elapsedMs;

	do
	{
		elapsedTicks = clock() - prevTicks;
		elapsedMs = elapsedTicks * 1000 / CLOCKS_PER_SEC;
	} while (elapsedMs < _tickIntervalMs);
	prevTicks = clock();
	//printf("tick\n");
}

void SetTickInterval(uint16_t tickIntervalMs)
{
    _tickIntervalMs = tickIntervalMs;
}