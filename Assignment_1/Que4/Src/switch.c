/*
 * switch.c
 *
 *  Created on: 18-Mar-2026
 *      Author: sunbeam
 */

#include<switch.h>

void switch_init(uint8_t pin)
{
	// enable clock for switch GPIO
	RCC->AHB1ENR |= BV(GPIOA_CLK_EN);
	// select mode of gpio pin as input
	SWITCH_GPIO->MODER &= ~(BV(pin * 2) | BV(pin * 2 + 1));
	// disable pull up/down resistors
	SWITCH_GPIO->PUPDR &= ~(BV(pin * 2) | BV(pin * 2 + 1));
}

uint8_t switch_status(uint8_t pin)
{
	return SWITCH_GPIO->IDR & BV(pin) ? 1 : 0;
}








