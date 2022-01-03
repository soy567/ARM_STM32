#ifndef CONTROLLER_ROADSIGNBOARD_SPEEDTIMECONTROLLER_H_
#define CONTROLLER_ROADSIGNBOARD_SPEEDTIMECONTROLLER_H_

#include "main.h"


void RoadSignBoard_SetSpeedState(uint8_t state);
uint8_t RoadSignBoard_GetSpeedState(void);
void RoadSignBoard_SetSpeedTime(uint16_t speedTime);
uint16_t RoadSignBoard_GetSpeedTime();
void RoadSignBoard_ChangeSpeedTime();


#endif /* CONTROLLER_ROADSIGNBOARD_SPEEDTIMECONTROLLER_H_ */
