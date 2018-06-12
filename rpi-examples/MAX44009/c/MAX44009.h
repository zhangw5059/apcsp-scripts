#ifndef _MAX44009_H_
#define _MAX44009_H_

#define MAX44009_ADDR 0x4A

#define lux_h_register 0x03
#define lux_l_register 0x04

float getLux(int fd);

#endif
