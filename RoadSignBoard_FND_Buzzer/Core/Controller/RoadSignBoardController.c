#include "RoadSignBoardController.h"


void RoadSignBoard_Init() {
	RoadSignBoard_SetState(IDLE);
	RoadSignBoard_SetSpeedTime(100);
	RoadSignBoard_SetSpeedState(0);
	BUZZER_Init(&htim2, TIM_CHANNEL_1);
}

void RoadSignBoardController(void) {
	switch(RoadSignBoard_GetState()) {
		case IDLE:
			RoadSignBoard_Idle_State();
			break;
		case LEFT_SIGN:
			RoadSignBoard_Left_State();
			break;
		case RIGHT_SIGN:
			RoadSignBoard_Right_State();
			break;
		case TWOWAY_SIGN:
			RoadSignBoard_TwoWay_State();
			break;
		case BLINK_SIGN:
			RoadSignBoard_Blink_State();
			break;
		case LEFT_BLINK:
			RoadSignBoard_LeftBlink_State();
			break;
		case RIGHT_BLINK:
			RoadSignBoard_RightBlink_State();
			break;
		case BOTH_BLINK:
			RoadSignBoard_BothBlink_State();
			break;
	}
}

// 함수 포인터 이용한 이벤트 핸들링 함수
void RoadSignBoard_ExcuteHandler(void (*pfLED_DirectionSign) (void)) {
	static uint32_t prevTime = 0;

	// timeTick 이용하여 300ms마다 Delay없이 깜빡임
	if (HAL_GetTick() - prevTime > RoadSignBoard_GetSpeedTime()) {
		prevTime = HAL_GetTick();
		pfLED_DirectionSign(); // Callback function (LED Shift)

		if(pfLED_DirectionSign == LED_LeftBlink ||
			pfLED_DirectionSign == LED_RightBlink ||
			pfLED_DirectionSign == LED_BothBlink)
			BUZZER_ClickSound();
	}
}

void RoadSignBoard_Idle_State() {
	RoadSignBoard_ExcuteHandler(LED_AllOff);
	RoadSignBoard_EventHandler(LEFT_SIGN);
}

void RoadSignBoard_Left_State() {
	RoadSignBoard_ExcuteHandler(LED_LeftSign);
	RoadSignBoard_EventHandler(RIGHT_SIGN);
}

void RoadSignBoard_Right_State() {
	RoadSignBoard_ExcuteHandler(LED_RightSign);
	RoadSignBoard_EventHandler(TWOWAY_SIGN);
}

void RoadSignBoard_TwoWay_State() {
	RoadSignBoard_ExcuteHandler(LED_TwoWaySign);
	RoadSignBoard_EventHandler(BLINK_SIGN);
}

void RoadSignBoard_Blink_State() {
	RoadSignBoard_ExcuteHandler(LED_AllBlink);
	RoadSignBoard_EventHandler(LEFT_BLINK);
}

void RoadSignBoard_LeftBlink_State() {
	RoadSignBoard_ExcuteHandler(LED_LeftBlink);
	RoadSignBoard_EventHandler(RIGHT_BLINK);
}

void RoadSignBoard_RightBlink_State() {
	RoadSignBoard_ExcuteHandler(LED_RightBlink);
	RoadSignBoard_EventHandler(BOTH_BLINK);
}

void RoadSignBoard_BothBlink_State() {
	RoadSignBoard_ExcuteHandler(LED_BothBlink);
	RoadSignBoard_EventHandler(IDLE);
}
