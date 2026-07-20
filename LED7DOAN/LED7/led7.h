#ifndef LED7_H
#define LED7_H

#include <stm32f1xx_hal.h>

typedef struct{
	GPIO_TypeDef *PORT;
	uint16_t PIN;
}LED7_GPIO;

typedef enum {
	LED_ANODE,
	LED_CATHODE,
}LED7_GPIO7_TYPE;

typedef struct {
	LED7_GPIO segment[7];
	LED7_GPIO7_TYPE type;
}LED7_HANDLE;

void LED7_Init(LED7_HANDLE *hLED,
							LED7_GPIO seg_a, 
							LED7_GPIO seg_b, 
							LED7_GPIO seg_c, 
							LED7_GPIO seg_d, 
							LED7_GPIO seg_e, 
							LED7_GPIO seg_f, 
							LED7_GPIO seg_g, 
							LED7_GPIO7_TYPE type);

void LED7_Display(LED7_HANDLE *hLED, uint8_t number);

#endif
