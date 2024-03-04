// LDR Sensor with Arduino UNO:

const int ledPin = 13;
const int ldrPin = A0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);
}

void loop() {
  int ldrStatus = analogRead(ldrPin);

  if (ldrStatus <= 300) {
    digitalWrite(ledPin, LOW);
    Serial.print("Bright, Turn OFF LED: ");
    Serial.println(ldrStatus);
  } else {
    digitalWrite(ledPin, HIGH);
    Serial.print("Dark, Turn ON LED: ");
    Serial.println(ldrStatus);
  }
}
