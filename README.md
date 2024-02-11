# IOT Lab - Sensor Interfacing with Arduino and Raspberry Pi

## Table of Contents
- [Introduction](#introduction)
- [Sensor Interfacing](#sensor-interfacing)
  - [1. LDR Sensor with Arduino UNO](#1-ldr-sensor-with-arduino-uno)
  - [2. LCD 16X2 and IR Sensor with Arduino UNO](#2-lcd-16x2-and-ir-sensor-with-arduino-uno)
  - [3. Ultra-Sonic Sensor with Raspberry Pi 3 B+](#3-ultra-sonic-sensor-with-raspberry-pi-3-b)
- [Communication Modules](#communication-modules)
  - [4. GSM Module with Arduino UNO](#4-gsm-module-with-arduino-uno)
- [Communication between Arduino and Raspberry Pi](#communication-between-arduino-and-raspberry-pi)
  - [5. Communication between Arduino and Raspberry Pi using Serial Cable](#5-communication-between-arduino-and-raspberry-pi-using-serial-cable)

## Introduction

This README provides instructions and code snippets for interfacing various sensors with Arduino UNO and Raspberry Pi 3 B+.

## Sensor Interfacing

### 1. LDR Sensor with Arduino UNO

```cpp
// Paste your LDR Sensor code here
void setup() {
  // Your setup code
}

void loop() {
  // Your loop code
}
```

### 2. LCD 16X2 and IR Sensor with Arduino UNO

```cpp
#include <LiquidCrystal_I2C.h> 

int irSensorPin = 2; // Connect IR sensor output to pin 2 (modify if needed)
int ledPin = 13; // Connect LED to pin 13 (optional)

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Address, 16 columns, 2 rows

void setup() {
  Serial.begin(9600); // Initialize serial communication for debugging
  Serial.println("Serial Working"); // Print confirmation message

  lcd.init();
  lcd.backlight();
  lcd.clear(); // Clear the LCD display
  lcd.print("Sensor:");

  pinMode(irSensorPin, INPUT); // Set IR sensor pin as input
  pinMode(ledPin, OUTPUT); // Set LED pin as output
  digitalWrite(ledPin, LOW); // Turn LED off initially (optional)
}

void loop() {
  int sensorStatus = digitalRead(irSensorPin);

  lcd.setCursor(0, 1);
  if (sensorStatus == HIGH) {
    lcd.print("Object Detected");
    digitalWrite(ledPin, HIGH); // Turn LED on
    Serial.println("Object Detected"); // Send message to serial monitor
  } else {
    lcd.print("No Object");
    digitalWrite(ledPin, LOW); // Turn LED off
    Serial.println("No Object Detected"); // Send message to serial monitor
  }

  delay(100); // Adjust delay as needed
}
```

### 3. Ultra-Sonic Sensor with Raspberry Pi 3 B+

```python
import RPi.GPIO as GPIO
import time

# Define GPIO pins for trigger and echo
TRIGGER_PIN = 21
ECHO_PIN = 18

# Set GPIO mode (BCM or BOARD)
GPIO.setmode(GPIO.BCM)

# Set trigger pin as output
GPIO.setup(TRIGGER_PIN, GPIO.OUT)

# Set echo pin as input
GPIO.setup(ECHO_PIN, GPIO.IN)

def measureDistance():
  # Send 10 microsecond pulse to trigger pin
  GPIO.output(TRIGGER_PIN, True)
  time.sleep(0.00001)
  GPIO.output(TRIGGER_PIN, False)

  # Measure pulse duration on echo pin
  pulseStart = time.time()
  while GPIO.input(ECHO_PIN) == 0:
    pulseStart = time.time()
  while GPIO.input(ECHO_PIN) == 1:
    pulseEnd = time.time()

  pulseDuration = pulseEnd - pulseStart

  # Calculate distance in centimeters
  distance = pulseDuration * 17000 / 2

  return distance

if __name__ == '__main__':
  try:
    while True:
      # Get distance reading
      distanceCm = measureDistance()

      # Print distance to console
      print("Distance:", distanceCm, "cm")

      time.sleep(1) # Adjust delay as needed

  except KeyboardInterrupt:
    # Clean up GPIO on exit
    GPIO.cleanup()
```

## Communication Modules

### 4. GSM Module with Arduino UNO

```cpp
#include <SoftwareSerial.h>

SoftwareSerial gsm(8, 9); // RX, TX pins for software serial communication

const char recipientPhoneNumber[] = "+91XXXXXXXXXX"; // Store phone number as a variable
char message[] = "Hello from Arduino!";

void setup() {
  Serial.begin(9600);  // Initialize serial communication with computer (for debugging)
  gsm.begin(9600);    // Initialize serial communication with GSM module
  Serial.println("Initializing...");
  delay(3000); // Wait for GSM module to boot up

  // Send AT commands and check responses using waitForResponse function
  if (!waitForResponse("AT", "OK")) return;
  if (!waitForResponse("AT+CMGF=1", "OK")) return;
  if (!waitForResponse(String("AT+CMGS=\"") + recipientPhoneNumber + "\""), ">")) return;

  // Send message content and Ctrl+Z
  gsm.println(message);
  UpdateSerial();
  gsm.write(26); // ASCII code for Ctrl+Z

  Serial.println("SMS sent successfully!");
}

void loop() {
  delay(10000);  // Send SMS only once every 10 seconds (adjust as needed)
  UpdateSerial(); // Optional for debugging and monitoring
}

bool waitForResponse(String command, const char* expected) {
  gsm.println(command);
  UpdateSerial();
  return waitForResponse(1000, expected); // Use existing waitForResponse function
}

void UpdateSerial() {
  delay(500);  // Brief delay to allow for serial data transfer
  // Relay any incoming data from the serial monitor to the GSM module
  while (Serial.available()) {
    gsm.write(Serial.read());
  }
  // Relay any incoming data from the GSM module to the serial monitor
  while (gsm.available()) {
    Serial.write(gsm.read());
  }
}
```

## Communication between Arduino and Raspberry Pi

### 5. Communication between Arduino and Raspberry Pi using Serial Cable

```cpp
// Paste your Serial Communication code here
void setup() {
  // Your setup code
}

void loop() {
  // Your loop code
}
```