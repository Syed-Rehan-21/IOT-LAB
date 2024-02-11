#define LDR_PIN A0  // Analog pin for LDR sensor
#define LED_PIN 13  // Digital pin for LED

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  pinMode(LDR_PIN, INPUT);  // Set LDR pin as input
  pinMode(LED_PIN, OUTPUT);  // Set LED pin as output
}

void loop() {
  int sensorValue = analogRead(LDR_PIN);  // Read LDR value
  float illumination = 1023.0 / sensorValue;  // Calculate relative illumination

  // Determine brightness based on illumination threshold
  if (illumination > 400) {  // Adjust threshold as needed
    digitalWrite(LED_PIN, HIGH);  // Bright: Turn LED on
    Serial.println("Bright light detected!");  // Print brightness status
  } else {
    digitalWrite(LED_PIN, LOW);  // Dark: Turn LED off
    Serial.println("Darkness detected!");  // Print darkness status
  }
}