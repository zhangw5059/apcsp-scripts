#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <softPwm.h>
#include <ctype.h>
#include <getopt.h>

const int speedMax = 200;

// Motor 1 1st: GPIO 12, aka pin 15
const int motorPin1 = 3;
// Motor 1 2nd: GPIO 23, aka pin 16
const int motorPin2 = 4;

void motor1(int pin1, int pin2)
{
  digitalWrite(motorPin1, pin1);
  digitalWrite(motorPin2, pin2);
}

void brake()
{
  softPwmWrite(motorPin1, 0);
  motor1(LOW, LOW);
}

void enablePWM(pin, speed)
{
  if (0 != softPwmCreate(pin, 0, speed))
  {
    printf("ERROR: Cannot enable software PWM for pin %d", pin);
  }
}

int init()
{
  if (-1 == wiringPiSetup())
  {
    printf("setup wiringPi failed!\n");
    return 1;
  }

  signal(SIGINT, brake);

  // Set pin mode
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);

  //Software PWM
  enablePWM(motorPin1, speedMax);
  enablePWM(motorPin2, speedMax);

  brake();
  return 0;
}

void forward()
{
  softPwmWrite(motorPin1, 90);

  motor1(HIGH, LOW);
}

void back(int speed)
{
  softPwmWrite(motorPin2, speed);

  motor1(LOW, HIGH);
}

int main(int argc, char **argv)
{
  char *direction = "forward";
  opterr = 0;
  int argument = 0;
  int speed = 80;
  while ((argument = getopt (argc, argv, "d:s:")) != -1)
  {
    switch (argument)
    {
      case 'd':
        direction = optarg;
      break;

      case 's':
        speed = atoi(optarg);
      break;

      case '?':
        if (optopt == 'd')
        {
          fprintf (stderr, "Option -%c requires an argument: forward, back, stop, left or right.\n", optopt);
        }
        else if (isprint (optopt))
        {
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        }
        else
        {
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        }
        return 1;

      default:
        abort();
    }
  }

  printf("Direction: %s Speed: %d\n", direction, speed);

  if (0 < init())
  {
    return 1;
  }

  if (0 == strcmp(direction, "forward"))
  {
    printf("Moving forward...\n");
    forward(speed);
  }
  else if (0 == strcmp(direction, "back"))
  {
    printf("Moving backward...\n");
    back(speed);
  }
  else
  {
    printf("Unknown direction. Stopping...\n");
    brake();
    return 3;
  }
  sleep(5);
  brake();
  return 0;
}
