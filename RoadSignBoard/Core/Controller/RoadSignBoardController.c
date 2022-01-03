/*
 * RoadSignBoardController.c
 *
 *  Created on: Dec 29, 2021
 *      Author: kccistc
 */
#include "RoadSignBoardController.h"


void RoadSignBoard_Init() {
	RoadSignBoard_SetState(IDLE);
	RoadSignBoard_SetSpeedTime(100);
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
	}
}

// 함수 포인터 이용한 이벤트 핸들링 함수
void RoadSignBoard_ExcuteHandler(void (*pfLED_DirectionSign) (void)) {
	static uint32_t prevTime = 0;

	// timeTick 이용하여 300ms마다 Delay없이 깜빡임
	if (HAL_GetTick() - prevTime > RoadSignBoard_GetSpeedTime()) {
		prevTime = HAL_GetTick();
		pfLED_DirectionSign(); // Callback function (LED Shift)
	}
}

void RoadSignBoard_Idle_State() {
	RoadSignBoard_ExcuteHandler(LED_AllOff);
	//LED_AllOff();

	RoadSignBoard_EventHandler(LEFT_SIGN);
	/*
	if(BUTTON1_GetState())
		RoadSignBoard_SetState(LEFT_SIGN);

	if(BUTTON2_GetState())
		RoadSignBoard_ChangeSpeedTime();
	*/
}

void RoadSignBoard_Left_State() {
	RoadSignBoard_ExcuteHandler(LED_LeftSign);
	/*
	if (HAL_GetTick() - prevTime > RoadSignBoard_GetSpeedTime()) {
		prevTime = HAL_GetTick();
		LED_LeftSign();
	}
	*/

	RoadSignBoard_EventHandler(RIGHT_SIGN);
	/*
	if(BUTTON1_GetState())
		RoadSignBoard_SetState(RIGHT_SIGN);

	if(BUTTON2_GetState())
		RoadSignBoard_ChangeSpeedTime();
	*/
}

void RoadSignBoard_Right_State() {
	RoadSignBoard_ExcuteHandler(LED_RightSign);
	/*
	if (HAL_GetTick() - prevTime > RoadSignBoard_GetSpeedTime()) {
		prevTime = HAL_GetTick();
		LED_RightSign();
	}
	*/

	RoadSignBoard_EventHandler(TWOWAY_SIGN);
	/*
	if(BUTTON1_GetState())
		RoadSignBoard_SetState(TWOWAY_SIGN);

	if(BUTTON2_GetState())
		RoadSignBoard_ChangeSpeedTime();
	*/
}

void RoadSignBoard_TwoWay_State() {
	RoadSignBoard_ExcuteHandler(LED_TwoWaySign);
	/*
	if (HAL_GetTick() - prevTime > RoadSignBoard_GetSpeedTime()) {
		prevTime = HAL_GetTick();
		LED_TwoWaySign();
	}
	*/

	RoadSignBoard_EventHandler(BLINK_SIGN);
	/*
	if(BUTTON1_GetState())
		RoadSignBoard_SetState(BLINK_SIGN);

	if(BUTTON2_GetState())
		RoadSignBoard_ChangeSpeedTime();
	*/
}

void RoadSignBoard_Blink_State() {
	RoadSignBoard_ExcuteHandler(LED_AllBlink);
	/*
	// timeTick 이용하여 300ms마다 Delay없이 깜빡임
	if (HAL_GetTick() - prevTime > RoadSignBoard_GetSpeedTime()) {
		prevTime = HAL_GetTick();
		LED_AllBlink();
	}
	*/

	RoadSignBoard_EventHandler(IDLE);
	/*
	if(BUTTON1_GetState()) {
		RoadSignBoard_SetState(IDLE);
		LED_SetledState(0);
	}

	if(BUTTON2_GetState())
		RoadSignBoard_ChangeSpeedTime();
	*/
}
