#include <Arduino.h>

#ifndef TEENSYPWM_H
#define TEENSYPWM_H

#define THROTTLE_MAX_PWM  1000
#define THROTTLE_MIN_PWM  1500
#define TMAP_MAX_IN       1500
#define TMAP_MIN_IN       1000
#define TMAP_MAX_OUT      1000
#define TMAP_MIN_OUT      2000

void calcThrottlePercent();
void calcSteeringAngle();
void risingCH1();
void risingCH2();
void risingCH3();

typedef enum
{  
  STEERING_INTERRUPT_PIN = 18,
  THROTTLE_INTERRUPT_PIN = 19,
  CH3_INTERRUPT_PIN = 20,
  SWITCH_POS_1 = A0,
  SWITCH_POS_2 = A1
} Pins;

typedef struct
{
//THROTTLE PID VARIABLES
double mappedThrottlePWM = 900;
double rawThrottlePWM = 1500;
double autopilotThrottlePWM = 1500;
//STEERING PID VARIABLES
double rawSteeringPWM;
double steeringFilteredPWM;
double manualSteeringPWM = 1500;
double autopilotSteeringPWM = 1500;
// other variables
bool ch3toggle = 0;
double CH3PWM;
double throttlePercent;
double steeringAngle;
unsigned long futabaCH3PWM = 1000;
unsigned long ch1Timer;
unsigned long ch2Timer;
unsigned long ch3Timer;

} PWMdata;

extern PWMdata pwmData; //Create a pointer to the system data

#endif