#ifndef INDUSBOARD_H
#define INDUSBOARD_H

#include "Arduino.h"

class IndusBoard {
public:
    IndusBoard();
    void begin();
    int touchValue(uint8_t pin);
    bool touch(uint8_t pin);
    String readAll();
    void led(const char* state);
    void led(int brightness);
    
private:
    int lastTouchValue[10];
};

#endif
