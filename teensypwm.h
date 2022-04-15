#include <Arduino.h>

#ifndef TEENSYPWM_H
#define TEENSYPWM_H

#define THROTTLE_MAX_PWM  1000
#define THROTTLE_MIN_PWM  1500
#define TMAP_MAX_IN       1500
#define TMAP_MIN_IN       1000
#define TMAP_MAX_OUT      1000
#define TMAP_MIN_OUT      2000

void risingCH1();
void risingCH2();
void risingCH3();
void fallingCH1();
void fallingCH2();
void fallingCH3();

typedef enum
{  
  CH1_INTERRUPT_PIN = 24,
  CH2_INTERRUPT_PIN = 25,
  CH3_INTERRUPT_PIN = 33,
  SWITCH_PAYLOAD = A1
} Pins;

typedef struct
{
unsigned long ch1PWM = 1500;
unsigned long ch2PWM = 1500;
unsigned long ch3PWM = 1500;
unsigned long prevCh1PWM = 1500;
unsigned long prevCh2PWM = 1500;
unsigned long prevCh3PWM = 1500;

unsigned long futabaCH3PWM = 1000;
unsigned long ch1Timer;
unsigned long ch2Timer;
unsigned long ch3Timer;
} PWMdata;

extern PWMdata pwmData; //Create a pointer to the system data

#endif