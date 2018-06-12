#!/bin/bash

# Raspberry Pi LM75A I2C temperature sample code.
# Author: Leon Anavi <leon@anavi.org>

# By default the address of LM75A is set to 0x48
# aka A0, A1, and A2 are set to GND (0v).
address=0x48

# Check if another address has been specified
if [ ! -z "$1" ]; then
	address=$1
fi

# Read from I2C and print temperature 
i2cget -y 1 $address 0x00 w |
awk '{printf("%.2f\n", (a=( \
(("0x"substr($1,5,2)substr($1,3,1))*0.0625)+0.1) \
)>128?a-256:a)}'
