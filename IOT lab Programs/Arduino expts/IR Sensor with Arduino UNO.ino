// IR Sensor with Arduino UNO:

int IRSensor = 2;
int LED = 13;

void setup() {
  Serial.begin(9600);
  pinMode(IRSensor, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  int statusSensor = digitalRead(IRSensor);

  if (statusSensor == 1) {
    digitalWrite(LED, LOW);
    Serial.println("Object detected");
  } else {
    digitalWrite(LED, HIGH);
    Serial.println("Object not detected");
  }
}
