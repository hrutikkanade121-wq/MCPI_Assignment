/*
 * led.c
 *
 *  Created on: 29-Mar-2026
 *      Author: sunbeam
 */

#include<led.h>

void led_init(uint8_t pin)
{
	//clock enable
	RCC->AHB1ENR |=BV(GPIOD_CLK_EN);

	LED_GPIO->MODER &= ~BV(pin * 2 + 1);
	LED_GPIO->MODER |= BV(pin * 2);

	//select output type as push pull
	LED_GPIO->OTYPER &= ~BV(pin);


	//speed- low
	LED_GPIO->OSPEEDR &= ~(BV(pin * 2 + 1) | BV(pin * 2));

	//disable pull/pull down
	LED_GPIO->PUPDR &= ~(BV(pin * 2 + 1) | BV(pin * 2));

}

void led_on(uint8_t pin)
{
	LED_GPIO->ODR |=BV(pin);

}

void led_off(uint8_t pin)
{
	LED_GPIO->ODR &= ~BV(pin);
}
