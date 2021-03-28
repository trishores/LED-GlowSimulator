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
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include "ledstrip_driver.h"
#include "string_handler.h"
#include "../GlowDecompiler/decode_metadata.h"

extern char *htmlString[];

void ReadBinaryFile()
{
	// Open binary file:
	FILE *stream = fopen(binFilepath, "rb");
	if (stream == NULL)
	{
		printf("Error opening bin file.");
		return;
	}
	// Read from file:
	fseek(stream, 0, SEEK_END);
	long length = ftell(stream);
	fseek(stream, 0, SEEK_SET);
	ptrSramBufferStart = malloc(length);	// freed on read error or program exit.
	if (ptrSramBufferStart == NULL)
	{
		fprintf(stderr, "Simulator memory allocation failed, exiting.\n");
		exit(1);
	}
	size_t newLen = fread(ptrSramBufferStart, 1, length, stream); 
	if (newLen != length) 
	{
		fprintf(stderr, "Simulator binary read error, exiting.\n");
		free(ptrSramBufferStart);
		exit(1);
	}
	fclose(stream);
}

#define GENERATE_GIF_FRAMES_
#ifdef GENERATE_GIF_FRAMES
char htmlFilePathIndexed[100];
#endif
void WriteHtmlFile()
{
#ifdef GENERATE_GIF_FRAMES
	static int counter = 0;
	htmlFilePathIndexed[0] = '\0';
	strcat(htmlFilePathIndexed, "D:\\FiveFifty\\ledmaker.org\\Images\\svg\\");
	char intBuf[5];
	intBuf[0] = '\0';
	_itoa(++counter, intBuf, 10);
	strcat(htmlFilePathIndexed, intBuf);
	strcat(htmlFilePathIndexed, ".svg");
	if (counter < 377) return; if (counter > 496) exit(0);	// number of frames in one animation cycle.
#endif

	// Open html file:
#ifdef GENERATE_GIF_FRAMES
	FILE *stream = fopen(htmlFilePathIndexed, "w");
#else
	FILE *stream = fopen(htmlFilepath, "w");
#endif
	if (stream == NULL)
	{
		printf("Error opening html file.");
		return;
	}

	// Write to file:
	uint16_t i = 0;
	fprintf(stream, "%s", htmlString[0]);
	for (uint16_t i = 0; i < LED_COUNT; i++)
	{
		fprintf(stream, htmlString[i + 1],
			simLedstrip[i].red, simLedstrip[i].green, simLedstrip[i].blue, simLedstrip[i].alpha);
	}
	fprintf(stream, "%s", htmlString[LED_COUNT + 1]);

	fclose(stream);
}