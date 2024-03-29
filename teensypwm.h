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
  STEERING_SERVO_PIN = 3,
  THROTTLE_SERVO_PIN = 6,
  STEERING_INTERRUPT_PIN = 15,
  THROTTLE_INTERRUPT_PIN = 16,
  CH3_INTERRUPT_PIN = 17,
  LED_GPS_FIX_PIN = 18,
  LED_AUTOPILOT_PIN = 19,
  LED_5V_VOLTAGE_PIN = 22,
  LED_12V_VOLTAGE_PIN = 23,
  SENSE_5V_VOLTAGE_PIN = A6,
  SENSE_12V_VOLTAGE_PIN = A7,
  BATTERY_VOLTAGE_PIN = A0,
  EXTERNAL_LED_PIN = 4,
  C1_SWITCH_PIN = 2,
  C2_SWITCH_PIN = 5
} Pins;

typedef struct
{
//THROTTLE PID VARIABLES
double mappedThrottlePWM = 900;
double manualThrottlePWM = 1500;
double autopilotThrottlePWM = 1500;
//STEERING PID VARIABLES
double steeringPWM;
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