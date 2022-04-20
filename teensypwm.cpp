#include "teensypwm.h"

PWMdata pwmData; // pwm data instance
int delayTime = 0;  //this is like a trim kinda thing, probably keep at zero

bool acceptable(unsigned long pwm) 
{
  return pwm >= 900 & pwm <= 2000;
}

void PWMSetup() 
{
  attachInterrupt(digitalPinToInterrupt(APSTR_INTERRUPT_PIN), risingApStr, RISING);
  attachInterrupt(digitalPinToInterrupt(APTHR_INTERRUPT_PIN), risingApThr, RISING);
}

void fallingApStr()
{
  pwmData.prevApStrPWM = pwmData.ApStrPWM;
  unsigned long temp = (micros() - delayTime) - pwmData.ApStrTimer;
  pwmData.ApStrPWM = acceptable(temp) ? temp : pwmData.prevApStrPWM;
  attachInterrupt(digitalPinToInterrupt(APSTR_INTERRUPT_PIN), risingApStr, RISING);
}
void risingApStr()
{
  pwmData.ApStrTimer = micros();
  attachInterrupt(digitalPinToInterrupt(APSTR_INTERRUPT_PIN), fallingApStr, FALLING);
}

void fallingApThr()
{
  pwmData.prevApThrPWM = pwmData.ApThrPWM;
  unsigned long temp = (micros() - delayTime) - pwmData.ApThrTimer;
  pwmData.ApThrPWM = acceptable(temp) ? temp : pwmData.prevApThrPWM;
  attachInterrupt(digitalPinToInterrupt(APTHR_INTERRUPT_PIN), risingApThr, RISING);
}
void risingApThr()
{
  pwmData.ApThrTimer = micros();
  attachInterrupt(digitalPinToInterrupt(APTHR_INTERRUPT_PIN), fallingApThr, FALLING);
}

