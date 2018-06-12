#!/usr/bin/python
# Depends on Adafruit Python BMP from Bastien Wirtz:
# https://github.com/bastienwirtz/Adafruit_Python_BMP

import Adafruit_BMP.BMP280 as BMP280

sensor = BMP280.BMP280()

print 'Temperature: {0:0.2f} *C'.format(sensor.read_temperature())
print 'Barometric Pressure: {0:0.2f} Pa'.format(sensor.read_pressure())
print 'Altitude: {0:0.2f} m'.format(sensor.read_altitude())
print 'Sealevel Pressure: {0:0.2f} Pa'.format(sensor.read_sealevel_pressure())
