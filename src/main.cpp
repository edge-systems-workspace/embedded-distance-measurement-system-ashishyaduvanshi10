#include <Arduino.h>

int trigPin = 9;
int echoPin = 10;

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600);
}

void loop() {
}