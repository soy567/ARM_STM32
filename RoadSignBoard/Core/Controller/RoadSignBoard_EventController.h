/*
 * RoadSignBoard_EventController.h
 *
 *  Created on: Dec 30, 2021
 *      Author: kccistc
 */

#ifndef CONTROLLER_ROADSIGNBOARD_EVENTCONTROLLER_H_
#define CONTROLLER_ROADSIGNBOARD_EVENTCONTROLLER_H_

#include "main.h"
#include "RoadSignBoard_SpeedTimeController.h"
#include "../Driver/button.h"
#include "../Driver/led.h"

void RoadSignBoard_SetState(uint8_t state);
uint8_t RoadSignBoard_GetState();
void RoadSignBoard_EventHandler(uint8_t state);


#endif /* CONTROLLER_ROADSIGNBOARD_EVENTCONTROLLER_H_ */
