/*
 * LightController.c
 *
 *  Created on: Dec 28, 2021
 *      Author: kccistc
 */

#include "LightController.h"


uint8_t lightState; // 제어 상태 저장위한 변수
uint8_t ledData = 1;


void setLightState(uint8_t state) {
	lightState = state;
}

uint8_t getLightState() {
	return lightState;
}

void LightControllerInit(void){
	setLightState(LIGHT_OFF);
}

void LightController(void) {
	switch(lightState) {
		case LIGHT_ON:
			LightOnState();
			break;
		case LIGHT_OFF:
			LightOffState();
			break;
		case LEFT_SHIFT:
			leftShiftState();
			break;
		case RIGHT_SHIFT:
			rightShiftState();
			break;
	}
}

void LightOnState(void) {
	// LED_On();
	LED_WriteData(0xff);

	if(Button_GetState())
		setLightState(LEFT_SHIFT);
}

void LightOffState(void) {
	// LED_Off();
	LED_WriteData(0x00);

	if(Button_GetState())
		setLightState(LIGHT_ON);
}

void leftShiftState() {
	ledData = (ledData >> 7) | (ledData << 1);
	LED_WriteData(ledData);
	HAL_Delay(100);

	if(Button_GetState())
		setLightState(RIGHT_SHIFT);
}

void rightShiftState() {
	ledData = (ledData << 7) | (ledData >> 1);
	LED_WriteData(ledData);
	HAL_Delay(100);

	if(Button_GetState())
		setLightState(LIGHT_OFF);
}

