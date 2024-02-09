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