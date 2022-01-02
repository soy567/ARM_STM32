/*
 * led.c
 *
 *  Created on: Dec 28, 2021
 *      Author: kccistc
 */
#include "led.h"


void LED_On(void) {
	HAL_GPIO_WritePin(LED_GPIO, LED_GPIO_PIN, GPIO_PIN_SET);
}

void LED_Off(void) {
	HAL_GPIO_WritePin(LED_GPIO, LED_GPIO_PIN, GPIO_PIN_RESET);
}

void LED_WriteData(uint8_t data) {

	// 배열 이용하여 한번에 8개의 GPIO포트 정의
	GPIO_TypeDef *LED2_GPIO[8] = {
			GPIOB, GPIOB, GPIOB, GPIOB,
			GPIOC, GPIOC, GPIOC, GPIOC
	};
	// 배열 이용하여 한번에 8개의 GPIO핀 정의
	uint16_t LED2_GPIO_PIN[8] = {
			GPIO_PIN_12, GPIO_PIN_13, GPIO_PIN_14, GPIO_PIN_15,
			GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3
	};

	// 반복문 이용하여 위에서 정의한 8개의 핀 순회하며 데이터 입력
	for(int i = 0; i < 8; i++)
		HAL_GPIO_WritePin(LED2_GPIO[i], LED2_GPIO_PIN[i], data & (1<<i));
}
