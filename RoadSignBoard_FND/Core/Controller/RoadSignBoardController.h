/*
 * RoadSignBoardController.h
 *
 *  Created on: Dec 29, 2021
 *      Author: kccistc
 */

#ifndef CONTROLLER_ROADSIGNBOARDCONTROLLER_H_
#define CONTROLLER_ROADSIGNBOARDCONTROLLER_H_

#include "main.h"
#include "RoadSignBoard_EventController.h"
#include "RoadSignBoard_SpeedTimeController.h"
#include "../Driver/button.h"
#include "../Driver/led.h"
#include "../Driver/FND.h"


enum {IDLE, LEFT_SIGN, RIGHT_SIGN, TWOWAY_SIGN, BLINK_SIGN};


void RoadSignBoard_Init();
void RoadSignBoardController(void);
void RoadSignBoard_ExcuteHandler(void (*pfLED_DirectionSign) (void));
void RoadSignBoard_Idle_State();
void RoadSignBoard_Left_State();
void RoadSignBoard_Right_State();
void RoadSignBoard_TwoWay_State();
void RoadSignBoard_Blink_State();


#endif /* CONTROLLER_ROADSIGNBOARDCONTROLLER_H_ */
