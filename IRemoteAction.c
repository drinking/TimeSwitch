  #include "IRemoteAction.h"
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
