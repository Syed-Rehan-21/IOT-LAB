// DHT-11 Sensor with Arduino UNO:

#include <DHT11.h>

DHT11 dht11(2);

void setup() {
  Serial.begin(9600);
}

void loop() {
  float humidity = dht11.readHumidity();
  float temperature = dht11.readTemperature();

  if (temperature != -1 && humidity != -1) {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  } else {
    Serial.println("Error reading data");
  }

  delay(2000);
}
