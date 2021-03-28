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

#include "../GlowDecompiler/public_api.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include "string_handler.h"
#include <string.h>
#include "ledstrip_driver.h"

static uint16_t _brightnessCoeff = 25;

SimLed simLedstrip[LED_COUNT];

static uint32_t _ledStartFrame = 0x00000000;
static uint32_t _ledStopFrame  = 0xFFFFFFFF;

static void NormalizeColors(struct LedstripBuffer *ledstripBuffer)
{
	for (int ledIdx = 0; ledIdx < ledstripBuffer->numLeds; ledIdx++)
	{
		if (_brightnessCoeff == 0)
		{
			printf("Invalid brightness coefficient");
			return;
		}

		// Get max r/g/b value:
		uint8_t maxColorValue = ledstripBuffer->leds[ledIdx].red;
		if (maxColorValue < ledstripBuffer->leds[ledIdx].green) maxColorValue = ledstripBuffer->leds[ledIdx].green;
		if (maxColorValue < ledstripBuffer->leds[ledIdx].blue) maxColorValue = ledstripBuffer->leds[ledIdx].blue;
		if (maxColorValue > 0)
		{
			// Scale rgb values up:
			simLedstrip[ledIdx].red = (ledstripBuffer->leds[ledIdx].red * 255) / maxColorValue;
			simLedstrip[ledIdx].green = (ledstripBuffer->leds[ledIdx].green * 255) / maxColorValue;
			simLedstrip[ledIdx].blue = (ledstripBuffer->leds[ledIdx].blue * 255) / maxColorValue;
		}
		// Scale-up brightness value to maximize brightness range:
		float alpha = ((ledstripBuffer->leds[ledIdx].red + ledstripBuffer->leds[ledIdx].green + ledstripBuffer->leds[ledIdx].blue) * ledstripBuffer->leds[ledIdx].bright) / 
			(float)_brightnessCoeff;

		if (alpha < 0)
		{
			printf("Limit alpha %3.2f to 0\n", alpha);
			simLedstrip[ledIdx].alpha = 0;
		}
		else if (alpha > 1)
		{
			printf("Limit alpha %3.2f to 1\n", alpha);
			simLedstrip[ledIdx].alpha = 1;
		}
		else simLedstrip[ledIdx].alpha = alpha;
	}
}

void ProgramLedstrip(struct LedstripBuffer *ledstripBuffer)
{
	NormalizeColors(ledstripBuffer);

	WriteHtmlFile();

	ledstripBuffer->isDirty = false;
}

void SaveBrightnessCoefficient(uint16_t brightnessCoeff)
{
	_brightnessCoeff = brightnessCoeff;
}