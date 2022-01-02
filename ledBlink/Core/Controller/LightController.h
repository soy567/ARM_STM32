/*
 * LightController.h
 *
 *  Created on: Dec 28, 2021
 *      Author: kccistc
 */

#ifndef CONTROLLER_LIGHTCONTROLLER_H_
#define CONTROLLER_LIGHTCONTROLLER_H_

#include "main.h"
#include "../Driver/led.h"
#include "../Driver/button.h"


enum {LIGHT_ON, LIGHT_OFF, LEFT_SHIFT, RIGHT_SHIFT};

void setLightState(uint8_t state);
uint8_t getLightState();
void LightControllerInit(void);
void LightController(void);
void LightOnState(void);
void LightOffState();
void leftShiftState();
void rightShiftState();
void leftShiftAState();
void rightShiftAState();


#endif /* CONTROLLER_LIGHTCONTROLLER_H_ */
