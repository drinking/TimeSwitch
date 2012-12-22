#include "arduino.h"
#include "IRemoteAction.h"
#include "Timer.h"

class DigitalTube{

  
  public:
  DigitalTube();
  ~DigitalTube(){}

  void setSegments(int n);
  void update();
  void updateDisplay();
  void invoke(long command);
  void leftMove(){index++; if(index>2)index=0; changed=true;}
  void rightMove(){index--; if(index<0)index=2; changed=true;}
  void setTime(int time);
  int getTime(int witch);
  
  private:
  int times[3];
  int index;
  boolean changed;
//  Timer timer;
  boolean start;
};
  static const byte digits[10][8] = {
//  a  b  c  d  e  f  g  .
  { 1, 1, 1, 1, 1, 1, 0, 0},  // 0
  { 0, 1, 1, 0, 0, 0, 0, 0},  // 1
  { 1, 1, 0, 1, 1, 0, 1, 0},  // 2
  { 1, 1, 1, 1, 0, 0, 1, 0},  // 3
  { 0, 1, 1, 0, 0, 1, 1, 0},  // 4
  { 1, 0, 1, 1, 0, 1, 1, 0},  // 5
  { 1, 0, 1, 1, 1, 1, 1, 0},  // 6
  { 1, 1, 1, 0, 0, 0, 0, 0},  // 7
  { 1, 1, 1, 1, 1, 1, 1, 0},  // 8  
  { 1, 1, 1, 1, 0, 1, 1, 0}  // 9  
};
 const static int segmentPins[] = {3, 7, A2, A4, A5, 4, A1, A3}; 
 const static int displayPins[] = {6, 5,2};
