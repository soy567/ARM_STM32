/*
 * led.c
 *
 *  Created on: Dec 29, 2021
 *      Author: kccistc
 */
#include "led.h"


// 배열 이용하여 한번에 8개의 GPIO포트 정의
GPIO_TypeDef *LED_GPIO[8] = {
		GPIOB, GPIOB, GPIOB, GPIOB,
		GPIOC, GPIOC, GPIOC, GPIOC
};

// 배열 이용하여 한번에 8개의 GPIO핀 정의
uint16_t LED_GPIO_PIN[8] = {
		GPIO_PIN_12, GPIO_PIN_13, GPIO_PIN_14, GPIO_PIN_15,
		GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3
};

uint8_t ledState;


void LED_SetledState(uint8_t state) {
	ledState = state;
}

uint8_t LED_GetledState(void){
	return ledState;
}

void LED_WriteData(uint8_t data) {
	// 반복문 이용하여 위에서 정의한 8개의 핀 순회하며 데이터 입력
	for(int i = 0; i < 8; i++)
		HAL_GPIO_WritePin(LED_GPIO[i], LED_GPIO_PIN[i], data & (1<<i));
}


void LED_AllOff() {
	LED_WriteData(0x00);
}

void LED_LeftSign() {
	// LED 켜질 패턴 미리 설정하여 배열 순회하며 LED 패턴대로 반복 점멸
	uint8_t ledPattern[] = {0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0xff,
				0x00, 0xff, 0x00, 0xff};
	uint8_t pattern = LED_GetledState();
	LED_WriteData(ledPattern[pattern]);
	pattern = (pattern + 1) % (sizeof(ledPattern) / sizeof(uint8_t)); // 모듈러 연산 이용
	LED_SetledState(pattern);
}

void LED_RightSign() {
	uint8_t ledPattern[] = {0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff,
					0x00, 0xff, 0x00, 0xff};
	uint8_t pattern = LED_GetledState();
	LED_WriteData(ledPattern[pattern]);
	pattern = (pattern + 1) % (sizeof(ledPattern) / sizeof(uint8_t)); // 모듈러 연산 이용
	LED_SetledState(pattern);
}

void LED_TwoWaySign() {
	uint8_t ledPattern[] = {0x00, 0x18, 0x3c, 0x7e, 0xff, 0x00, 0xff, 0x00, 0xff};
	uint8_t pattern = LED_GetledState();
	LED_WriteData(ledPattern[pattern]);
	pattern = (pattern + 1) % (sizeof(ledPattern) / sizeof(uint8_t)); // 모듈러 연산 이용
	LED_SetledState(pattern);
}

void LED_AllBlink() {
	if (ledState == 0) {
		ledState = 0xff;
	} else {
		ledState = 0;
	}
	LED_WriteData(ledState);
}
