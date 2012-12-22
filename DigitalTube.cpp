#include "DigitalTube.h"
  boolean isDigital(long command){
    if(command==KEY_0|command==KEY_1
    ||command==KEY_2||command==KEY_3
    ||command==KEY_4||command==KEY_5
    ||command==KEY_6||command==KEY_7
    ||command==KEY_8||command==KEY_9)
    return true;
    
    return false;
  }

  int getDigital(long command){
    if(command==KEY_0) return 0;
    if(command==KEY_1) return 1;
    if(command==KEY_2) return 2;
    if(command==KEY_3) return 3;
    if(command==KEY_4) return 4;
    if(command==KEY_5) return 5;
    if(command==KEY_6) return 6;
    if(command==KEY_7) return 7;
    if(command==KEY_8) return 8;
    if(command==KEY_9) return 9;
  
  }
DigitalTube::DigitalTube(){
   for (int i=0; i < 8; i++){
     pinMode(segmentPins[i], OUTPUT);
   }
  pinMode(displayPins[0], OUTPUT);
  pinMode(displayPins[1], OUTPUT);
  pinMode(displayPins[2], OUTPUT);
  times[0]=times[1]=times[2]=0;
  index=0;
  changed=true;
}
void DigitalTube::setSegments(int n){
  for (int i=0; i < 8; i++){
    digitalWrite(segmentPins[i], ! digits[n][i]);
  } 

}
void DigitalTube::update(){

//  timer.update();
  updateDisplay();

}
void DigitalTube::updateDisplay(){
  
  digitalWrite(displayPins[0], HIGH);
  digitalWrite(displayPins[1], LOW);
  digitalWrite(displayPins[2], LOW);
  setSegments(getTime(0));
  delay(5);
  digitalWrite(displayPins[0], LOW);
  digitalWrite(displayPins[1], HIGH);
  digitalWrite(displayPins[2], LOW);
  setSegments(getTime(1));
  delay(5);  
  digitalWrite(displayPins[0], LOW);
  digitalWrite(displayPins[1], LOW);
  digitalWrite(displayPins[2], HIGH);
  setSegments(getTime(2));
  delay(5);  
}
void DigitalTube::setTime(int time){
  times[index]=time;
  changed=false;
}
int DigitalTube::getTime(int which){
  if(changed&&which==index){
    return random(1,7);
  }else{
    return times[which];
  }
}
void DigitalTube::invoke(long command){
  
    if(isDigital(command)){
      setTime(getDigital(command));
      return;
    }
    if(command==KEY_BACK){
      leftMove();
    }
    if(command==KEY_FORWARD){
      rightMove();
    }

}
