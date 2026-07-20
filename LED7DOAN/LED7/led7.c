#include "led7.h"

static uint8_t seg_code[10] = {0X3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void LED7_Init(LED7_HANDLE *hLED,
							LED7_GPIO seg_a, 
							LED7_GPIO seg_b, 
							LED7_GPIO seg_c, 
							LED7_GPIO seg_d, 
							LED7_GPIO seg_e, 
							LED7_GPIO seg_f, 
							LED7_GPIO seg_g, 
							LED7_GPIO7_TYPE type)
{
	hLED->type = type;
	hLED->segment[0] = seg_a;
	hLED->segment[1] = seg_b;
	hLED->segment[2] = seg_c;
	hLED->segment[3] = seg_d;
	hLED->segment[4] = seg_e;
	hLED->segment[5] = seg_f;
	hLED->segment[6] = seg_g;
}

void LED7_Display(LED7_HANDLE *hLED, uint8_t number)
{
	if(number > 9) return;
	uint8_t data = seg_code[number];
	for(uint8_t i = 0; i < 7; i ++){
		uint8_t bit = (data >> i) & (0x01);
		GPIO_PinState state;
		if(hLED->type == LED_ANODE){
			state = bit ? 0 : 1;
		} else {
			state = bit ? 1 : 0;
		}
		HAL_GPIO_WritePin(hLED->segment[i].PORT, hLED->segment[i].PIN, state);
	}
}
