#ifndef CONTROLLER_ROADSIGNBOARD_EVENTCONTROLLER_H_
#define CONTROLLER_ROADSIGNBOARD_EVENTCONTROLLER_H_

#include "main.h"
#include "RoadSignBoard_SpeedTimeController.h"
#include "../Driver/button.h"
#include "../Driver/led.h"
#include "../Driver/FND.h"
#include "../Driver/buzzer.h"


void RoadSignBoard_SetState(uint8_t state);
uint8_t RoadSignBoard_GetState();
void RoadSignBoard_EventHandler(uint8_t state);


#endif /* CONTROLLER_ROADSIGNBOARD_EVENTCONTROLLER_H_ */
