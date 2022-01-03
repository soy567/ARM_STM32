#include "RoadSignBoard_EventController.h"


uint8_t roadSignBoardState;

void RoadSignBoard_SetState(uint8_t state) {
	roadSignBoardState = state;
}

uint8_t RoadSignBoard_GetState() {
	return roadSignBoardState;
}

void RoadSignBoard_EventHandler(uint8_t state) {
	if(BUTTON_GetState(&hButton_Mode)) {
		RoadSignBoard_SetState(state);
		LED_SetledState(0);
		FND_ShowMode(state);
	}
	if(BUTTON_GetState(&hButton_SpeedTime)) {
		RoadSignBoard_ChangeSpeedTime();
		FND_ShowSpeed(RoadSignBoard_GetSpeedState());
	}
}

