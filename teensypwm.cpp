#include "teensypwm.h"

PWMdata pwmData; // pwm data instance...
int delayTime = 0;  //this is like a trim kinda thing, probably keep at zero

bool acceptable(unsigned long pwm) 
{
  return (pwm >= 900) & (pwm <= 2000);
}

void PWMSetup() 
{
  attachInterrupt(digitalPinToInterrupt(APSTR_INTERRUPT_PIN), risingApStr, RISING);
  attachInterrupt(digitalPinToInterrupt(APTHR_INTERRUPT_PIN), risingApThr, RISING);
  attachInterrupt(digitalPinToInterrupt(STR_INTERRUPT_PIN), risingStr, RISING);
  attachInterrupt(digitalPinToInterrupt(THR_INTERRUPT_PIN), risingThr, RISING);
  attachInterrupt(digitalPinToInterrupt(CH3_INTERRUPT_PIN), risingCh3, RISING);
}
void smooth(long throttle)
{
  pwmData.smoothedThrottle = pwmData.smoothingWeight * (float)throttle + (1.0 - pwmData.smoothingWeight) * (float)pwmData.prevThrottle;
  pwmData.prevThrottle = pwmData.smoothedThrottle;
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

void fallingStr()
{
  pwmData.prevStrPWM = pwmData.StrPWM;
  unsigned long temp = (micros() - delayTime) - pwmData.StrTimer;
  pwmData.StrPWM = acceptable(temp) ? temp : pwmData.prevStrPWM;
  attachInterrupt(digitalPinToInterrupt(STR_INTERRUPT_PIN), risingStr, RISING);
}
void risingStr()
{
  pwmData.StrTimer = micros();
  attachInterrupt(digitalPinToInterrupt(STR_INTERRUPT_PIN), fallingStr, FALLING);
}

void fallingThr()
{
  pwmData.prevThrPWM = pwmData.ThrPWM;
  unsigned long temp = (micros() - delayTime) - pwmData.ThrTimer;
  pwmData.ThrPWM = acceptable(temp) ? temp : pwmData.prevThrPWM;
  attachInterrupt(digitalPinToInterrupt(THR_INTERRUPT_PIN), risingThr, RISING);
}
void risingThr()
{
  pwmData.ThrTimer = micros();
  attachInterrupt(digitalPinToInterrupt(THR_INTERRUPT_PIN), fallingThr, FALLING);
}

void fallingCh3()
{
  pwmData.prevCh3PWM = pwmData.Ch3PWM;
  unsigned long temp = (micros() - delayTime) - pwmData.Ch3Timer;
  pwmData.Ch3PWM = acceptable(temp) ? temp : pwmData.prevCh3PWM;
  
  attachInterrupt(digitalPinToInterrupt(CH3_INTERRUPT_PIN), risingCh3, RISING);
}
void risingCh3()
{
  pwmData.Ch3Timer = micros();
  attachInterrupt(digitalPinToInterrupt(CH3_INTERRUPT_PIN), fallingCh3, FALLING);
}
