#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <softPwm.h>
#include <ctype.h>
#include <getopt.h>

const int speedMax = 200;

// Motor 1 1st: GPIO 0, aka pin 11
const int motor1pin1 = 0;
// Motor 1 2nd: GPIO 1, aka pin 12
const int motor1pin2 = 1;

// Motor 2 1st: GPIO 3, aka pin 15
const int motor2pin1 = 3;
// Motor 2 2nd: GPIO 4, aka pin 16
const int motor2pin2 = 4;

void motor1(int pin1, int pin2)
{
  digitalWrite(motor1pin1, pin1);
  digitalWrite(motor1pin2, pin2);
}

void motor2(int pin1, int pin2)
{
  digitalWrite(motor2pin1, pin1);
  digitalWrite(motor2pin2, pin2);
}

void brake()
{
  softPwmWrite(motor1pin1, 0);
  softPwmWrite(motor1pin2, 0);
  softPwmWrite(motor2pin1, 0);
  softPwmWrite(motor2pin2, 0);
  motor1(LOW, LOW);
  motor2(LOW, LOW);
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
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  //Software PWM
  enablePWM(motor1pin1, speedMax);
  enablePWM(motor1pin2, speedMax);
  enablePWM(motor2pin1, speedMax);
  enablePWM(motor2pin2, speedMax);

  brake();
  return 0;
}

void forward()
{
  softPwmWrite(motor1pin1, 90);
  softPwmWrite(motor2pin1, 90);

  motor1(HIGH, LOW);
  motor2(HIGH, LOW);
}

void back(int speed)
{
  softPwmWrite(motor1pin2, speed);
  softPwmWrite(motor2pin2, speed);

  motor1(LOW, HIGH);
  motor2(LOW, HIGH);
}

right(int speed)
{
  softPwmWrite(motor1pin2, speed);
  softPwmWrite(motor2pin2, 0);

  motor1(LOW, HIGH);
  motor2(LOW, LOW);
}

left(int speed)
{
  softPwmWrite(motor1pin2, 0);
  softPwmWrite(motor2pin2, speed);

  motor1(LOW, LOW);
  motor2(LOW, HIGH);
}

int main(int argc, char **argv)
{
  char *direction = "";
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
  else if (0 == strcmp(direction, "left"))
  {
    printf("Turning left...\n");
    left(speed);
  }
  else if (0 == strcmp(direction, "right"))
  {
    printf("Turning right...\n");
    right(speed);
  }
  else
  {
    printf("Unknown direction. Stopping...\n");
    brake();
    return 3;
  }
  sleep(1);
  brake();
  return 0;
}
