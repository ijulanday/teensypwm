#include "teensypwm.h"

SysData systemData; //Create a pointer to the system data
int delayTime = 0;

// throttle% = 0.202(pwm) + 311.717 for fly sky controller
void calcThrottlePercent() {
    systemData.throttlePercent = -0.00202*systemData.manualThrottlePWM + 3.11717;
}

void risingCH1();
void fallingCH1()
{
  systemData.manualSteeringPWM = (micros() - delayTime) - systemData.ch1Timer;
  attachInterrupt(digitalPinToInterrupt(STEERING_INTERRUPT_PIN), risingCH1, RISING);
}
void risingCH1()
{
  systemData.ch1Timer = micros();
  attachInterrupt(digitalPinToInterrupt(STEERING_INTERRUPT_PIN), fallingCH1, FALLING);
}
void risingCH2();
void fallingCH2()
{
  systemData.manualThrottlePWM = (micros() - delayTime) - systemData.ch2Timer;
  attachInterrupt(digitalPinToInterrupt(THROTTLE_INTERRUPT_PIN), risingCH2, RISING);
}
void risingCH2()
{
  systemData.ch2Timer = micros();
  attachInterrupt(digitalPinToInterrupt(THROTTLE_INTERRUPT_PIN), fallingCH2, FALLING);
}
void risingCH3();
void fallingCH3()
{
  systemData.CH3PWM = (micros() - delayTime) - systemData.ch3Timer;
  attachInterrupt(digitalPinToInterrupt(CH3_INTERRUPT_PIN), risingCH3, RISING);
}
void risingCH3()
{
  systemData.ch3Timer = micros();
  attachInterrupt(digitalPinToInterrupt(CH3_INTERRUPT_PIN), fallingCH3, FALLING);
}

