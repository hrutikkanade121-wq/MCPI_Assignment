/*
 * main.c
 *
 *  Created on: 29-Mar-2026
 *      Author: sunbeam
 */


#include<stdint.h>
#include<stdio.h>

#include<led.h>

int main(void)
{
	led_init(LED_GREEN);
	led_init(LED_ORANGE);
	led_init(LED_RED);
	led_init(LED_BLUE);

	while(1){

		led_toggle(LED_GREEN);
		led_toggle(LED_ORANGE);
		led_toggle(LED_RED);
		led_toggle(LED_BLUE);

		DelayMs(2000);
	}
}
