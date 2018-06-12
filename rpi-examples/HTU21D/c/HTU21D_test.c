#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "wiringPi.h"
#include "wiringPiI2C.h"


#include "HTU21D.h"

int main ()
{
	wiringPiSetup();
	int fd = wiringPiI2CSetup(HTU21D_I2C_ADDR);
	if ( 0 > fd )
	{
		fprintf (stderr, "Unable to open I2C device: %s\n", strerror (errno));
		exit (-1);
	}
	
	printf("%5.2fC\n", getTemperature(fd));
	printf("%5.2f%%rh\n", getHumidity(fd));
	
	return 0;
}
