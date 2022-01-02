/*
 * led.h
 *
 *  Created on: Dec 28, 2021
 *      Author: kccistc
 */

#ifndef DRIVER_LED_H_
#define DRIVER_LED_H_

// 사용할 핀 키워드로 미리 지정 -> 제어문에서 직접 핀 지정하는 하드코딩 방지
#define LED_GPIO	GPIOC
#define LED_GPIO_PIN	GPIO_PIN_3

#include "main.h"
#include "../Driver/led.h"
#include "../Driver/button.h"

void LED_On(void);
void LED_Off(void);
void LED_WriteData(uint8_t data);


#endif /* DRIVER_LED_H_ */
