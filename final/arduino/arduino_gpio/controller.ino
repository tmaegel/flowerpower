#include "dht.h"

dht DHT;

#define DHT22_PIN 5


int brightAir;
int tempAir;

int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

int pinRead = 8;
int pinWrite = 9;

void senddata(float);
int takt = 200;

void setup()
{
  Serial.begin(115200);

  Serial.println("Setup Start");

  pinMode(pinRead, INPUT);
  pinMode(pinWrite, OUTPUT); 

  while (millis() < 5000) {
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    // record the minimum sensor value
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }

  Serial.println("Setup Done");
  Serial.println();
}

void loop()
{
  // TODO Warten auf Anfrage

  if (digitalRead(pinRead) == HIGH){
    // Action
  }

  // Einlesen des DHT 22
  Serial.println("-------------------");
  Serial.println("Read DHT 22");

  uint32_t start = micros();
  int chk = DHT.read22(DHT22_PIN);
  uint32_t stop = micros();

  float humGround = DHT.humidity;
  float tempGround = DHT.temperature;

  switch (chk)
  {
  case DHTLIB_OK:
    Serial.print("Feuchtigkeit: ");
    Serial.print(humGround);
    Serial.print("  Temperatur: ");
    Serial.print(tempGround);
    Serial.println();  

    break;
  default:
    Serial.println("Error!!!!");
    break;
  }

  // Einlesen der Analogsensoren  
  Serial.println("Read Analogsensor");

  brightAir = analogRead(A0);
  tempAir = analogRead(A1); 

  Serial.print("Helligkeit: ");
  Serial.print(brightAir);

  float voltage = (tempAir/1024.0) * 5.0;
  Serial.print(" Temperatur in C: "); 
  float temperature = (voltage - .5) * 100;
  float tempe = temperature - 1;
  Serial.println(tempe);
  Serial.println("-------------------");
  Serial.println();

  // Senden der Werte über digital Pin
  // Sende zwei Startbit
    senddata(1);
    senddata(1);
  // Sende Versionsnummer   
    senddata(1);
  // Sende Werte
    senddata((int)humGround);
    senddata((int)tempGround);
    senddata(brightAir);
    senddata(tempAir);
  delay(4000);
}

void senddata(int data){
  int i = 11;
  for (i; i>0; i--){
    byte state = bitRead(data,i);
    Serial.print(state);
    if (state == 1){
      digitalWrite(pinWrite,1);
      delay(takt/2);
      digitalWrite(pinWrite,0);
      delay(takt/2);
    }
    else if (state == 0){
      digitalWrite(pinWrite,0);
      delay(takt/2);
      digitalWrite(pinWrite,1);
      delay(takt/2);      
    }
  }
    byte state = bitRead(data,0);
    Serial.print(state);
    if (state == 1){
      digitalWrite(pinWrite,1);
      delay(takt/2);
      digitalWrite(pinWrite,0);
      delay(takt/2);
    }
    else if (state == 0){
      digitalWrite(pinWrite,0);
      delay(takt/2);
      digitalWrite(pinWrite,1);
      delay(takt/2);      
    }
    digitalWrite(pinWrite,0);
    Serial.println();
}



