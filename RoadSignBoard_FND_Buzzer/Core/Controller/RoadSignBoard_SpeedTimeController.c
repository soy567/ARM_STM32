/*
 * RoadSignBoard_SpeedTimeController.c
 *
 *  Created on: Dec 30, 2021
 *      Author: kccistc
 */
#include "RoadSignBoard_SpeedTimeController.h"


uint16_t roadSignBoardSpeedTime;
uint8_t speedState = 0;

void RoadSignBoard_SetSpeedState(uint8_t state) {
	speedState = state;
}

uint8_t RoadSignBoard_GetSpeedState(void) {
	return speedState;
}

void RoadSignBoard_SetSpeedTime(uint16_t speedTime) {
	roadSignBoardSpeedTime = speedTime;
}

uint16_t RoadSignBoard_GetSpeedTime() {
	return roadSignBoardSpeedTime;
}

void RoadSignBoard_ChangeSpeedTime() {
	// 0.1s -> 0.2s -> 0.3s -> 0.4s -> 0.5s
	uint16_t speedTime[] = {100, 200, 300, 400, 500};
	uint8_t state = RoadSignBoard_GetSpeedState();

	state = (state + 1) % (sizeof(speedTime) / sizeof(uint16_t));
	RoadSignBoard_SetSpeedState(state);

	roadSignBoardSpeedTime = speedTime[speedState];
}
