#include <Arduino.h>

#ifndef TEENSYPWM_H
#define TEENSYPWM_H

#define THROTTLE_MAX_PWM  1000
#define THROTTLE_MIN_PWM  1500
#define TMAP_MAX_IN       1500
#define TMAP_MIN_IN       1000
#define TMAP_MAX_OUT      1000
#define TMAP_MIN_OUT      2000

void PWMSetup();
void risingApStr();
void risingStr();
void risingApThr();
void risingThr();
void risingCh3();

void fallingApStr();
void fallingStr();
void fallingApThr();
void fallingThr();
void fallingCh3();
void smooth(long throttle);
typedef enum
{ 
  STR_INTERRUPT_PIN = 2,
  THR_INTERRUPT_PIN = 3,
  CH3_INTERRUPT_PIN = 4,
  APSTR_INTERRUPT_PIN = 5,
  APTHR_INTERRUPT_PIN = 6,
} Pins;

typedef struct
{
unsigned long ApStrPWM = 1500;
unsigned long ApThrPWM = 1500;
unsigned long prevApStrPWM = 1500;
unsigned long prevApThrPWM = 1500;

unsigned long ApStrTimer;
unsigned long ApThrTimer;
float smoothingWeight;
unsigned long prevThrottle;
unsigned long smoothedThrottle;
unsigned long StrPWM = 1500;
unsigned long ThrPWM = 1500;
unsigned long Ch3PWM = 1000;
unsigned long prevStrPWM = 1500;
unsigned long prevThrPWM = 1500;
unsigned long prevCh3PWM = 1000;

unsigned long StrTimer;
unsigned long ThrTimer;
unsigned long Ch3Timer;

} PWMdata;

extern PWMdata pwmData; //Create a pointer to the system data

#endif