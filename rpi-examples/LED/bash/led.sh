#!/bin/bash

if [ "$1" == "on" ]; then
	led=1
else
	led=0
fi
gpio mode 0 out
gpio write 0 $led
