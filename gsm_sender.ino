// send_sms
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