/**
 * @file Ultrasonic_Distance_Measurement.ino
 * @author Ashish Kumar Yadav
 * @date 2026-02-20
 * @version 1.0
 *
 * @brief Measures distance using an ultrasonic sensor (HC-SR04).
 *
 * @details
 * This program sends a trigger pulse to the ultrasonic sensor
 * and measures the echo return time. The distance is calculated
 * using the speed of sound formula and displayed on the Serial Monitor.
 *
 * Formula Used:
 * Distance (cm) = (Duration × 0.0343) / 2
 *
 * Connections:
 * - Trig → Digital Pin 9
 * - Echo → Digital Pin 10
 *
 * @note
 * Ensure proper 5V power supply to ultrasonic sensor.
 *
 * @warning
 * Do not place objects too close (<2cm) as readings may be inaccurate.
 */

#include <Arduino.h>

/** @brief Ultrasonic trigger pin */
#define TRIG_PIN 9

/** @brief Ultrasonic echo pin */
#define ECHO_PIN 10

/** @brief Time duration of echo signal */
long duration;

/** @brief Calculated distance in centimeters */
long distance;


/**
 * @brief Initializes pins and serial communication.
 */
void setup()
{
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
}


/**
 * @brief Main loop function.
 *
 * @details
 * Sends trigger pulse, reads echo time,
 * calculates distance, and prints result.
 */
void loop()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);   ///< Echo time in microseconds
  distance = (duration * 0.0343) / 2;   ///< Distance calculation

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
}