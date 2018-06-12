#include <stdio.h>
#include "MAX44009.h"

int main()
{
	int fd = wiringPiI2CSetup(MAX44009_ADDR) ;
	printf("Lux: %.3f \n", getLux(fd));
	return 0 ;
}
