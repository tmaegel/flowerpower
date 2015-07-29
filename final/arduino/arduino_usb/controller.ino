#include "dht.h"
#include <Servo.h>

/*
  ------------------------------------
  ErrorCode
  
  Code 0: Der DHT Sensor konnte 15mal nicht ausgelesen werden.
          Es muss ein Techniker schauen,ob die Kabel angeschlossen
          sind.
  Code 1: Es wurde kein bekannter Befehl gesendet
  ------------------------------------
*/

/*
  ------------------------------------
  Led Ausgabe zum ErrorCode
  
  Code 0: LED blinkt einmal kurz auf (500ms High)
  Code 1: LED blinkt zweimal kurz auf (500ms High)
  ------------------------------------
*/

dht DHT;
#define DHT22_PIN 7
#define errorLed 12
#define hardwareID 1
#define versionNum 1
Servo myservo;

float humGround = 0;
float tempGround = 0;
int brightAir;
int tempAir;

int chk = 0;
int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

bool error = true;
bool maxError = false;
int errorCount = 0;
int humCount = 0;

int input = 0;
String command = "";

void sendData();
void readData();
void showErrorode(int);

void setup()
{
  Serial.begin(115200);

  pinMode(errorLed, OUTPUT);
  myservo.attach(13);
  
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
}

void loop()
{
  /*
    Warte auf Daten
    Ließt zeichenweise ein und speichert diese in command
    Stoppt wenn ein '!' gelesen wird
  */
  
  if (Serial.available() > 0) {
    input = Serial.read();
    char currentChar = input;
//    Serial.print(currentChar);
    if (currentChar  != '!') // frage nach trennzeichen
    {
      command = command + currentChar;
    }
    else if (currentChar == '!') {     
      if (command == "rd") {
        
        /*       
          rd
          Ließt solange den dht22 bis kein Fehler zurueck kommt
          Maximal allerdings 15 mal
          Dann wird der Lesevorgang abgebrochen
        */
        
//        Serial.print("Befehl readData erhalten\n");
        while ((error == true) && (maxError == false)) {
          readData();
          switch (chk)
          {
            case DHTLIB_OK:
              error = false;
//              Serial.print("Uebertrage Daten DHT22\n");
              sendData();              
              break;
            default:
              error = true;
              errorCount++;
              if (errorCount > 5) {
                maxError = true;
                showErrorCode(0);
                Serial.print("error0");
              }
              delay(2500);
              break;
          }
        }
        // Ruecksetzen der Daten
        error = true;
        maxError = false;
        errorCount = 0;
        command = "";
        
        /*
          vo
          Oeffnet das Ventil solange bis der die Feuchtigkeit erreicht wurde
          oder eine maximale Zeit von 40Sekunden erreicht wurde
        */
        
      } else if (command == "vo") {
//        Serial.print("Befehl ventilOpen erhalten");
        myservo.write(180);
        while ((humGround < 100) && (humCount < 1)) {
          delay(4000);
          readData();
          humCount++;
        }
        myservo.write(-179);
        command = "";
        /*
          Ungueltiger Befehl
        */
      } else {
        Serial.print("error1\n");
        showErrorCode(0);
      }
    }
  }
}

/*
  readData
  ließt die Sensoren aus und speichert die Werte
*/
void readData() {
  uint32_t start = micros();
  chk = DHT.read22(DHT22_PIN);
  uint32_t stop = micros();

  humGround = DHT.humidity;
  tempGround = DHT.temperature;

  brightAir = analogRead(A0);
  tempAir = analogRead(A1);
}

/*
  sendData
  Uebertraegt die Daten per USB
*/
void sendData() {
  // Protokoll- Versionsnummer
  Serial.print(versionNum);
  Serial.print(";");
  // Hardware ID des Raspberry PI
  Serial.print(hardwareID);
  Serial.print(";");
  // Anzahl der Uebertragenenwerten
  Serial.print("4;");
  // Feuchtigkeit in der Erde
  Serial.print(humGround);
  Serial.print(";");
  // Temperatur in der Erde
  Serial.print(tempGround);
  Serial.print(";");
  // Helligkeit
  Serial.print(brightAir);
  Serial.print(";");
  float voltage = (tempAir / 1024.0) * 5.0;
  float temperature = (voltage - .5) * 100;
  float tempe = temperature - 1;
  // Lufttemperatur
  Serial.print(tempe);
  Serial.println("#");
}

/*
  showErrorCode
  Gibt den Fehlercode auf der LED aus
*/
void showErrorCode(int error){
  switch(error)
  {
    case 0: digitalWrite(errorLed,1);
            delay(500);
            digitalWrite(errorLed,0);            
            break;
    case 1: digitalWrite(errorLed,1);
            delay(500);
            digitalWrite(errorLed,0);
            delay(500);
            digitalWrite(errorLed,1);
            delay(500);
            digitalWrite(errorLed,0);
            break;
    default:
            break;  
    }
}


