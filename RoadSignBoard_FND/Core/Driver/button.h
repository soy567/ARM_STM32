/*
 * button.h
 *
 *  Created on: Dec 29, 2021
 *      Author: kccistc
 */

#ifndef DRIVER_BUTTON_H_
#define DRIVER_BUTTON_H_

#define BUTTON1_GPIO		GPIOA
#define BUTTON1_GPIO_PIN 	GPIO_PIN_4

#define BUTTON2_GPIO		GPIOD
#define BUTTON2_GPIO_PIN 	GPIO_PIN_2

#define TRUE 		1
#define FALSE		0
#define PUSHED		0
#define RELEASED	1


#include "main.h"

typedef struct {
	GPIO_TypeDef *GPIOx;
	uint16_t GPIO_Pin;
	uint8_t prevState;
} BUTTON_HandleTypeDef;

extern BUTTON_HandleTypeDef hButton_Mode; // btn1 handle 위한 handler 정의 (mode변경)
extern BUTTON_HandleTypeDef hButton_SpeedTime; // btn2 handle 위한 handler 정의 (TimeTick 주기 변경)

uint8_t BUTTON_GetState(BUTTON_HandleTypeDef *hButton);
/*
uint8_t BUTTON1_GetState();
uint8_t BUTTON2_GetState();
*/

#endif /* DRIVER_BUTTON_H_ */
