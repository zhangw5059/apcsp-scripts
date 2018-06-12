#include <wiringPiI2C.h>
#include <math.h>
#include "MAX44009.h"

float getLux(int fd)
{
	int vhigh = wiringPiI2CReadReg8(fd, lux_h_register);
	int vlow  = wiringPiI2CReadReg8(fd, lux_l_register);
	
	int exponent=( vhigh & 0xF0 ) >> 4;
	int mantisa= ( vhigh & 0x0F ) << 4 | vlow;
	
	float lux= ( ( pow(2,(double)exponent) ) * (double)mantisa ) * 0.045;
	return lux;
}
