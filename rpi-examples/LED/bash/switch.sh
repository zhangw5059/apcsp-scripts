#!/bin/bash

if [ `gpio read 0` == "1" ]; then
	led=0
else
	led=1
fi
gpio mode 0 out
gpio write 0 $led
