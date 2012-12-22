/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */
#include "Timer.h"
#include "IRremote.h"
#include "stdio.h"
#include "DigitalTube.h"
DigitalTube *mDisplay;
int RECV_PIN = 11;
int LED_ONE=8;
bool on=false;
int i=0;
IRrecv irrecv(RECV_PIN);
long command=0;
decode_results results;
Timer t;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(LED_ONE,OUTPUT);
  mDisplay=new DigitalTube();
}

void loop() {
//   digitalWrite(LED_ONE,HIGH);

  if (irrecv.decode(&results)) {
    if(results.value!=KEY_UP){
      command=results.value;
//      if(command==KEY_0){
//      Serial.println("DO ACTION...");
//      }
      mDisplay->invoke(command);
    }else if(results.value==KEY_UP&&command!=KEY_UP){
      command=KEY_UP;
    }
    irrecv.resume(); // Receive the next value
  }
  mDisplay->updateDisplay();
}
// Project 14 - Double Dice
//void loop()
//{
//  static int dice1;
//  static int dice2;
//  dice1 = random(1,7);
//  dice2 = random(1,7);
//  mDisplay->updateDisplay(2,5);
//}

