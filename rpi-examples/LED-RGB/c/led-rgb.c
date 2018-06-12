#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>

// Red: GPIO 7, aka pin 7
const int pinRed = 7;
// Green: GPIO 0, aka pin 11
const int pinGreen = 0;
// Blue: GPIO 2, aka pin 13
const int pinBlue = 2;

void color(int colorRed, int colorGreen, int colorBlue) 
{
  digitalWrite(pinRed, colorRed);
  digitalWrite(pinGreen, colorGreen);
  digitalWrite(pinBlue, colorBlue);
  //Wait for 1 second
  delay(1000);
}

int main()
{
  if (-1 == wiringPiSetup())
  {
    printf("setup wiringPi failed!\n");
    return 1;
  }

  // Set pin mode
  pinMode(pinRed, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinBlue, OUTPUT);

  for(;;) 
  {
    // Red
    color(1, 0, 0);
    // Green
    color(0, 1, 0);
    //Blue
    color(0, 0, 1);	
  }
  return 0;
}
