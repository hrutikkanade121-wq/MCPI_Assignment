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


		led_on(LED_GREEN);
		DelayMs(500);
		led_on(LED_ORANGE);
		DelayMs(500);
		led_on(LED_RED);
		DelayMs(500);
		led_on(LED_BLUE);
		DelayMs(500);

		led_off(LED_BLUE);
		DelayMs(500);
		led_off(LED_RED);
		DelayMs(500);
		led_off(LED_ORANGE);
		DelayMs(500);
		led_off(LED_GREEN);
		DelayMs(500);
	}

}
