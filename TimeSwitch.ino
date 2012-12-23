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
Timer timer;
void countdown(){
  mDisplay->countDown();
}
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(LED_ONE,OUTPUT);
  mDisplay=new DigitalTube();
  digitalWrite(LED_ONE,HIGH);
  timer.every(60000,countdown); 
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
  timer.update();
  mDisplay->updateDisplay();
}

