#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <softPwm.h>

// Pin for controlling the LED strip: GPIO 11, aka pin 11
const int pinCtrl = 0;

void close()
{
	softPwmWrite(pinCtrl, 0);
	exit(0);
}

void enablePWM(int pin, int speed)
{
	if (0 != softPwmCreate(pin, 0, speed))
	{
		printf("ERROR: Cannot enable software PWM for pin %d\n", pin);
	}
}

int main()
{
	// Process Ctrl+C to terminate the application
	signal(SIGINT, close);

	if (-1 == wiringPiSetup())
	{
		printf("setup wiringPi failed!\n");
		return 1;
	}

	// Enable PWM and set max value
	enablePWM(pinCtrl, 5);

	// Infinite loop
	for(;;) 
	{
		// Increase brightness from 20% to 100%
		for (int fadeIn=1; fadeIn<6;fadeIn++)
		{
			printf("Brightness: %d%\n", fadeIn*20);
			softPwmWrite(pinCtrl, fadeIn);
			delay(3000);
		}

		// Decrease brightness from 80% to 40%
		for (int fadeOut=4; fadeOut>1; fadeOut--)
		{
			printf("Brightness: %d%\n", fadeOut*20);
			softPwmWrite(pinCtrl, fadeOut);
			delay(3000);
		}
	}
	return 0;
}
