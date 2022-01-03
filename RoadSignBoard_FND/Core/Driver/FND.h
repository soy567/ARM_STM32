#ifndef DRIVER_FND_H_
#define DRIVER_FND_H_

#include "main.h"

#define FND_DATA_GPIO		GPIOB

#define FND_GPIO_DIGIT_0	GPIOA
#define FND_GPIO_DIGIT_1	GPIOA
#define FND_GPIO_DIGIT_2	GPIOC
#define FND_GPIO_DIGIT_3	GPIOC

#define FND_PIN_DIGIT_0		GPIO_PIN_10
#define FND_PIN_DIGIT_1		GPIO_PIN_11
#define FND_PIN_DIGIT_2		GPIO_PIN_4
#define FND_PIN_DIGIT_3		GPIO_PIN_3

enum {DIGIT_0, DIGIT_1, DIGIT_2, DIGIT_3};


void FND_ShowMode(uint8_t mode);
void FND_ShowSpeed(uint8_t speed);
void FND_ISR_Process(void);
void FND_WriteData(void);


#endif /* DRIVER_FND_H_ */
