#include "teensypwm.h"

PWMdata pwmData; //Create a pointer to the system data
int delayTime = 0;

// throttle% = -0.00202(pwm) + 3.11717 for fly sky controller
void calcThrottlePercent() {
  pwmData.throttlePercent = -0.00202*pwmData.manualThrottlePWM + 3.11717;
}

void calcSteeringAngle() {
  pwmData.steeringAngle = (pwmData.manualSteeringPWM - 1000) * 0.18;
}

void risingCH1();
void fallingCH1()
{
  pwmData.manualSteeringPWM = (micros() - delayTime) - pwmData.ch1Timer;
  attachInterrupt(digitalPinToInterrupt(STEERING_INTERRUPT_PIN), risingCH1, RISING);
}
void risingCH1()
{
  pwmData.ch1Timer = micros();
  attachInterrupt(digitalPinToInterrupt(STEERING_INTERRUPT_PIN), fallingCH1, FALLING);
}
void risingCH2();
void fallingCH2()
{
  pwmData.manualThrottlePWM = (micros() - delayTime) - pwmData.ch2Timer;
  attachInterrupt(digitalPinToInterrupt(THROTTLE_INTERRUPT_PIN), risingCH2, RISING);
}
void risingCH2()
{
  pwmData.ch2Timer = micros();
  attachInterrupt(digitalPinToInterrupt(THROTTLE_INTERRUPT_PIN), fallingCH2, FALLING);
}
void risingCH3();
void fallingCH3()
{
  pwmData.CH3PWM = (micros() - delayTime) - pwmData.ch3Timer;
  attachInterrupt(digitalPinToInterrupt(CH3_INTERRUPT_PIN), risingCH3, RISING);
}
void risingCH3()
{
  pwmData.ch3Timer = micros();
  attachInterrupt(digitalPinToInterrupt(CH3_INTERRUPT_PIN), fallingCH3, FALLING);
}

