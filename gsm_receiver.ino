// receive_sms
#include <SoftwareSerial.h>

SoftwareSerial gsm(8, 9); 

void setup() {
  Serial.begin(9600);
  gsm.begin(9600);
  Serial.println("Initializing...");
  delay(3000);

  // Send AT commands and check responses using waitForResponse function
  if (!waitForResponse("AT", "OK")) return;
  if (!waitForResponse("AT+CMGF=1", "OK")) return;
  if (!waitForResponse("AT+CNMI=1,2,0,0,0", "OK")) return;

  Serial.println("GSM module configured for SMS reception.");
}

void loop() {
  UpdateSerial(); // Continuously monitor serial communication
}

bool waitForResponse(String command, const char* expected) {
  gsm.println(command);
  UpdateSerial(); 
  return waitForResponse(1000, expected); // Use existing waitForResponse function
}

void UpdateSerial() {
  delay(500);
  while (Serial.available()) {
    gsm.write(Serial.read());
  }
  while (gsm.available()) {
    Serial.write(gsm.read());
  }
}