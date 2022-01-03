#include "button.h"


BUTTON_HandleTypeDef hButton_Mode = {BUTTON1_GPIO, BUTTON1_GPIO_PIN, RELEASED};
BUTTON_HandleTypeDef hButton_SpeedTime = {BUTTON2_GPIO, BUTTON2_GPIO_PIN, RELEASED};

// 버튼 정보 구조체로 받아 handle 하는 함수 -> 버튼마다 따로 handling 함수 만들 필요 X
uint8_t BUTTON_GetState(BUTTON_HandleTypeDef *hButton) {

	uint8_t curState = HAL_GPIO_ReadPin(hButton->GPIOx, hButton->GPIO_Pin);

	if (hButton->prevState!= PUSHED && curState == PUSHED) {
		HAL_Delay(10);
		hButton->prevState = PUSHED;
		return FALSE;
	}
	else if (hButton->prevState == PUSHED && curState != PUSHED) {
		HAL_Delay(10);
		hButton->prevState = RELEASED;
		return TRUE;
	}
	return FALSE;
}

/*
uint8_t BUTTON1_GetState() {
	static uint8_t prevState = RELEASED;
	uint8_t curState = HAL_GPIO_ReadPin(BUTTON1_GPIO, BUTTON1_GPIO_PIN);

	if (prevState != PUSHED && curState == PUSHED) {
		HAL_Delay(10);
		prevState = PUSHED;
		return FALSE;
	}
	else if (prevState == PUSHED && curState != PUSHED) {
		HAL_Delay(10);
		prevState = RELEASED;
		return TRUE;
	}
	return FALSE;
}


uint8_t BUTTON2_GetState() {
	static uint8_t prevState = RELEASED;
	uint8_t curState = HAL_GPIO_ReadPin(BUTTON2_GPIO, BUTTON2_GPIO_PIN);

	if (prevState != PUSHED && curState == PUSHED) {
		HAL_Delay(10);
		prevState = PUSHED;
		return FALSE;
	}
	else if (prevState == PUSHED && curState != PUSHED) {
		HAL_Delay(10);
		prevState = RELEASED;
		return TRUE;
	}
	return FALSE;
}
*/
