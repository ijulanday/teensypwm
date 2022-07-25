#include "teensypwm.h"

PWMdata pwmData; // pwm data instance
int delayTime = 0;  //this is like a trim kinda thing, probably keep at zero

bool acceptable(unsigned long pwm) 
{
  return (pwm >= 900) & (pwm <= 2000);
}

void fallingCH1()
{
  pwmData.prevCh1PWM = pwmData.ch1PWM;
  unsigned long temp = (micros() - delayTime) - pwmData.ch1Timer;
  pwmData.ch1PWM = acceptable(temp) ? temp : pwmData.prevCh1PWM;
  attachInterrupt(digitalPinToInterrupt(CH1_INTERRUPT_PIN), risingCH1, RISING);
}
void risingCH1()
{
  pwmData.ch1Timer = micros();
  attachInterrupt(digitalPinToInterrupt(CH1_INTERRUPT_PIN), fallingCH1, FALLING);
}

void fallingCH2()
{
  pwmData.prevCh2PWM = pwmData.ch2PWM;
  unsigned long temp = (micros() - delayTime) - pwmData.ch2Timer;
  pwmData.ch2PWM = acceptable(temp) ? temp : pwmData.prevCh2PWM;
  attachInterrupt(digitalPinToInterrupt(CH2_INTERRUPT_PIN), risingCH2, RISING);
}
void risingCH2()
{
  pwmData.ch2Timer = micros();
  attachInterrupt(digitalPinToInterrupt(CH2_INTERRUPT_PIN), fallingCH2, FALLING);
}

void fallingCH3()
{
  pwmData.prevCh3PWM = pwmData.ch3PWM;
  unsigned long temp = (micros() - delayTime) - pwmData.ch3Timer;
  pwmData.ch3PWM = acceptable(temp) ? temp : pwmData.prevCh3PWM;
  attachInterrupt(digitalPinToInterrupt(CH3_INTERRUPT_PIN), risingCH3, RISING);
}
void risingCH3()
{
  pwmData.ch3Timer = micros();
  attachInterrupt(digitalPinToInterrupt(CH3_INTERRUPT_PIN), fallingCH3, FALLING);
}



