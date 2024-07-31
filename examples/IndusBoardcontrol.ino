#include <IndusBoard.h>

IndusBoard Board;

void setup() {
    Serial.begin(115200);
    Board.begin();
}

void loop() {
    // Print touch value of pin 4
    Serial.print("Touch Value (Pin 4): ");
    Serial.println(Board.touchValue(4));

    // Check if pin 3 is touched
    if (Board.touch(3)) {
        Serial.println("Pin 3 is touched.");
    }

    // Read all touch pins
    Serial.println(Board.readAll());

    // Control the built-in LED
    Board.led("on");
    delay(1000);
    Board.led("off");
    delay(1000);
    Board.led(128); // Set brightness to 50%
    delay(1000);
}
