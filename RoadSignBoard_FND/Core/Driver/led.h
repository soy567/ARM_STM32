/*
 * led.h
 *
 *  Created on: Dec 29, 2021
 *      Author: kccistc
 */

#ifndef DRIVER_LED_H_
#define DRIVER_LED_H_

#include "main.h"

void LED_SetledState(uint8_t state);
uint8_t LED_GetledState(void);
void LED_WriteData(uint8_t data);
void LED_AllOff();
void LED_LeftSign();
void LED_RightSign();
void LED_TwoWaySign();
void LED_AllBlink();


#endif /* DRIVER_LED_H_ */
