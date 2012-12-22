#include "arduino.h"
#define KEY_UP  0xFFFFFFFF
#define KEY_POWER  0xFFA25D
#define KEY_MODE  0xFF629D
#define KEY_MUTE  0xFFE21D
#define KEY_PLAY  0xFF22DD
#define KEY_BACK  0xFF02FD
#define KEY_FORWARD  0xFFC23D
#define KEY_EQ  0xFFE01F
#define KEY_VOLDOWN  0xFFA857
#define KEY_VOLUP  0xFF906F
#define KEY_RPT  0xFF9867
#define KEY_SCN  0xFFB04F

#define KEY_0  0xFF6897
#define KEY_1  0xFF30CF
#define KEY_2  0xFF18E7
#define KEY_3  0xFF7A85
#define KEY_4  0xFF10EF
#define KEY_5  0xFF38C7
#define KEY_6  0xFF5AA5
#define KEY_7  0xFF42BD
#define KEY_8  0xFF4AB5
#define KEY_9  0xFF52AD

boolean isDigital(long command);
int getDigital(long command);

