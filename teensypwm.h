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
void risingApThr();
void fallingApStr();
void fallingApThr();

typedef enum
{  
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
} PWMdata;

extern PWMdata pwmData; //Create a pointer to the system data

#endif