/*
 * button.c
 *
 *  Created on: Dec 28, 2021
 *      Author: kccistc
 */
#include "button.h"

#define BUTTON_GPIO		GPIOD
#define BUTTON_GPIO_PIN 	GPIO_PIN_2



uint8_t Button_GetState() {
	static uint8_t prevState = RELEASED;
	uint8_t curState = HAL_GPIO_ReadPin(BUTTON_GPIO, BUTTON_GPIO_PIN);

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

