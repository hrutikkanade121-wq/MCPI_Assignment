#include <stdint.h>
#include <stdio.h>

#include<led.h>
#include<switch.h>

void delay(void)
{
	for(volatile unsigned int i = 0; i < 50000; i++);
}

void all_led_off(void)
{
	led_off(LED_GREEN);
	led_off(LED_ORANGE);
	led_off(LED_RED);
	led_off(LED_BLUE);
}

int main()
{
	int count = 0;
	uint8_t prev = 0;

	switch_init(SWITCH_PIN);

	led_init(LED_GREEN);
	led_init(LED_ORANGE);
	led_init(LED_RED);
	led_init(LED_BLUE);

	while(1)
	{
		uint8_t curr = switch_status(SWITCH_PIN);

		// Edge detection (button press)
		if(curr == 1 && prev == 0)
		{
			count++;
			if(count > 4)
				count = 0;

			all_led_off();   // reset LEDs on mode change
		}

		prev = curr;

		switch(count)
		{
			case 0:
				all_led_off();
				break;

			case 1: // Clockwise
				led_on(LED_GREEN);
				delay();
				led_off(LED_GREEN);

				led_on(LED_ORANGE);
				delay();
				led_off(LED_ORANGE);

				led_on(LED_RED);
				delay();
				led_off(LED_RED);

				led_on(LED_BLUE);
				delay();
				led_off(LED_BLUE);

				break;

			case 2: // Anti-clockwise
				led_on(LED_BLUE);
				delay();
				led_off(LED_BLUE);

				led_on(LED_RED);
				delay();
				led_off(LED_RED);

				led_on(LED_ORANGE);
				delay();
				led_off(LED_ORANGE);

				led_on(LED_GREEN);
				delay();
				led_off(LED_GREEN);

				break;

			case 3: // Red + Blue
				led_on(LED_RED);
				delay();
				led_on(LED_BLUE);

				led_off(LED_RED);
				delay();
				led_off(LED_BLUE);
				break;

			case 4: // Green + Orange
				led_on(LED_GREEN);
				delay();
				led_on(LED_ORANGE);

				led_off(LED_GREEN);
				delay();
				led_off(LED_ORANGE);
				break;
		}
	}
}
