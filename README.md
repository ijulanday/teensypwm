# teensypwm

A small library that attaches interrupt pins on the Teensy 4.0 with a handy struct for PWM data.

## example usage

```c
// main.cpp

#include "teensypwm.h"
#include "ChRt.h"

//------------------------------------------------------------------------------
//                            thread - SERIAL
//                                 10Hz
//------------------------------------------------------------------------------
// thread SERIAL - High Priority ChRt SERIAL thread
// 64 byte stack beyond task switch and interrupt needs.
static THD_WORKING_AREA(waThreadSERIAL, 64);
static THD_FUNCTION(ThreadSERIAL, arg)
{
    (void)arg;
    while (true)
    {
        Serial.print(systemData.manualSteeringPWM);
        Serial.print(", \t");
        Serial.print(systemData.manualThrottlePWM);
        Serial.print(", \t");
        Serial.println(systemData.CH3PWM);
        chThdSleepMilliseconds(10);
    }
}

// ChRt code -- not part of this library
void chSetup()
{
  chThdCreateStatic(waThreadHEART, sizeof(waThreadHEART),
                    NORMALPRIO + 1, ThreadHEART, NULL);
  chThdCreateStatic(waThreadSERIAL, sizeof(waThreadSERIAL),
                      NORMALPRIO + 1, ThreadSERIAL, NULL);
 
}
 
void setup()
{
  Serial.begin(9600);
  while (!Serial)
  {
    delay(1);
  }
 
  // attach interrupt pins in setup
  attachInterrupt(digitalPinToInterrupt(15), risingCH1, RISING);
  attachInterrupt(digitalPinToInterrupt(16), risingCH2, RISING);
  attachInterrupt(digitalPinToInterrupt(17), risingCH3, RISING);
  
  // ChRt code -- not part of this library
  chBegin(chSetup);
  while (true)
  {
  }
}
 
void loop()
{
    // do things here if not using ChRt
}
```