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
// Paste your LCD 16X2 and IR Sensor code here
void setup() {
  // Your setup code
}

void loop() {
  // Your loop code
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
// Paste your GSM Module code here
void setup() {
  // Your setup code
}

void loop() {
  // Your loop code
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