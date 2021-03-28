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

#define WINDOWS
//#define LINUX
#include "../GlowDecompiler/public_api.h"
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include "ledstrip_driver.h"
#include "timer_handler.h"
#include "string_handler.h"
#if defined(WINDOWS)
#include <windows.h>
#elif defined(LINUX)
#include <unistd.h>
#endif

uint8_t *ptrSramBufferStart;

enum AnimationFlag
{
	Stop = 0,
	RunInit = 1,
	Run = 2
};
static volatile enum AnimationFlag animationFlag;	// volatile keyword is critical.

int main(int argc, char **argv)
{
	struct stat sb;
	printf("Simulator started...\n");

	if (argc != 4)
	{
		printf("Expected 3 args (binFilepath, htmlFilepath, stopFilepath).");
		return 1;
	}
	binFilepath = argv[1];
	htmlFilepath = argv[2];
	char *stopFilepath = argv[3];

	ReadBinaryFile();

	animationFlag = RunInit;

	//SetLedstripTestColor(1, 2, 3, 4);

	while (true)
	{
        if (animationFlag == RunInit)
        {
	        InitAnimation(false);

			ClockInit();
			animationFlag = Run;
        }
        else if (animationFlag == Run)
		{
			// Pause until next tick:
			WaitForIntervalElapse();

            RunAnimation(false);

			// Send sync signal to vscode on stdout;
			printf(".");
			fflush(stdout);
        }

		// Check for stop/resume files:
		if (animationFlag == Run && stat(stopFilepath, &sb) == 0)
		{
			animationFlag = Stop;
		}
		else if (animationFlag == Stop)
		{
			#if defined(WINDOWS)
			Sleep(100);
			#elif defined(LINUX)
			usleep(100 * 1000);
			#endif
			
			if (stat(stopFilepath, &sb) != 0)
			{
				animationFlag = Run;
			}
		}
    }
}
