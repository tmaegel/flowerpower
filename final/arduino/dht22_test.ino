#include "dht.h"

dht DHT;

#define DHT22_PIN 5

void setup()
{
  Serial.begin(115200);
  Serial.println("Type,\tstatus,\tHumidity (%),\tTemperature");
}

void loop()
{

  Serial.print("DHT22, \t");

  uint32_t start = micros();
  int chk = DHT.read22(DHT22_PIN);
  uint32_t stop = micros();

  float hum = DHT.humidity;
  float temp = DHT.temperature;

  switch (chk)
  {
  case DHTLIB_OK:
    Serial.print("OK,\t");

    Serial.print(hum);
    Serial.print(",\t");
    Serial.print(temp);
    Serial.print(",\t");
    Serial.println();  

    break;
  default:
    Serial.print("Error,\t");
    break;
  }

  delay(2000);
}


