#include "IndusBoard.h"

IndusBoard::IndusBoard() {
    for (int i = 0; i < 10; i++) {
        lastTouchValue[i] = 0;
    }
}

void IndusBoard::begin() {
    pinMode(33, OUTPUT);
    for (int i = 0; i < 10; i++) {
        touchAttachInterrupt(i, []{}, 40);
    }
}

int IndusBoard::touchValue(uint8_t pin) {
    return touchRead(pin);
}

bool IndusBoard::touch(uint8_t pin) {
    int currentValue = touchRead(pin);
    if (abs(currentValue - lastTouchValue[pin]) > 2000) {
        lastTouchValue[pin] = currentValue;
        return true;
    } else {
        lastTouchValue[pin] = currentValue;
        return false;
    }
}

String IndusBoard::readAll() {
    String result = "";
    for (uint8_t pin = 1; pin <= 10; pin++) {
        if (touch(pin)) {
            result += "Pin " + String(pin) + " is touched. ";
        }
    }
    return result;
}

void IndusBoard::led(const char* state) {
    if (strcmp(state, "on") == 0) {
        digitalWrite(33, HIGH);
    } else if (strcmp(state, "off") == 0) {
        digitalWrite(33, LOW);
    }
}

void IndusBoard::led(int brightness) {
    analogWrite(33, brightness);
}
