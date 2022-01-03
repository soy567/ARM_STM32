#include "FND.h"

uint8_t modeData;
uint8_t speedData;

// PB0-7
uint8_t FND_FONT[] = {
		0x3f, 0x06, 0x5b, 0x4f, 0x66,
		0x6d, 0x7d, 0x07, 0x67, 0x80
};

void FND_ShowMode(uint8_t mode) {
	modeData = mode;
}

void FND_ShowSpeed(uint8_t speed) {
	speedData = speed;
}

//
void FND_ISR_Process(void) {
	FND_WriteData();
}

void FND_WriteData(void) {
	static uint8_t fndstate = 0;
	fndstate = (fndstate + 1) % 4; // 자릿수 결정

	HAL_GPIO_WritePin(FND_DATA_GPIO, 0xff, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(FND_GPIO_DIGIT_0, FND_PIN_DIGIT_0, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(FND_GPIO_DIGIT_1, FND_PIN_DIGIT_1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(FND_GPIO_DIGIT_2, FND_PIN_DIGIT_2, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(FND_GPIO_DIGIT_3, FND_PIN_DIGIT_3, GPIO_PIN_RESET);

	switch(fndstate) {
		case DIGIT_0:
			HAL_GPIO_WritePin(FND_DATA_GPIO, FND_FONT[modeData%10], GPIO_PIN_SET);
			HAL_GPIO_WritePin(FND_GPIO_DIGIT_0, FND_PIN_DIGIT_0, GPIO_PIN_SET);
			break;
		case DIGIT_1:
			HAL_GPIO_WritePin(FND_DATA_GPIO, FND_FONT[modeData/10%10], GPIO_PIN_SET);
			HAL_GPIO_WritePin(FND_GPIO_DIGIT_1, FND_PIN_DIGIT_1, GPIO_PIN_SET);
			break;
		case DIGIT_2:
			HAL_GPIO_WritePin(FND_DATA_GPIO, FND_FONT[speedData%10], GPIO_PIN_SET);
			HAL_GPIO_WritePin(FND_GPIO_DIGIT_2, FND_PIN_DIGIT_2, GPIO_PIN_SET);
			break;
		case DIGIT_3:
			HAL_GPIO_WritePin(FND_DATA_GPIO, FND_FONT[speedData/10%10], GPIO_PIN_SET);
			HAL_GPIO_WritePin(FND_GPIO_DIGIT_3, FND_PIN_DIGIT_3, GPIO_PIN_SET);
			break;
	}
}

