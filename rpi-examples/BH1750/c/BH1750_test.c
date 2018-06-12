#include <stdio.h>
#include "BH1750.h"

int main()
{
	int fd = wiringPiI2CSetup(BH1750_ADDR) ;
	printf("Lux: %d \n", getLux(fd));
	return 0 ;
}
