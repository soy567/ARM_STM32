/*
 * RoadSignBoard_SpeedTimeController.c
 *
 *  Created on: Dec 30, 2021
 *      Author: kccistc
 */
#include "RoadSignBoard_SpeedTimeController.h"


uint16_t roadSignBoardSpeedTime;

void RoadSignBoard_SetSpeedTime(uint16_t speedTime) {
	roadSignBoardSpeedTime = speedTime;
}

uint16_t RoadSignBoard_GetSpeedTime() {
	return roadSignBoardSpeedTime;
}

void RoadSignBoard_ChangeSpeedTime() {
	// 0.1s -> 0.2s -> 0.3s -> 0.4s -> 0.5s
	static uint8_t speedState = 0;
	uint16_t speedTime[] = {100, 200, 300, 400, 500};
	speedState = (speedState + 1) % (sizeof(speedTime) / sizeof(uint16_t));

	roadSignBoardSpeedTime = speedTime[speedState];
}
