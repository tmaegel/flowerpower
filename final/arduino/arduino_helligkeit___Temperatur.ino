
// variable to hold sensor value
int sensorValue;
int sensorbright;
int sensortmpe;
// variable to calibrate low value
int sensorLow = 1023;
// variable to calibrate high value
int sensorHigh = 0;
// LED pin
const int ledPin = 13;

void setup() {
  Serial.println("Starte Setup");
  Serial.begin(9600);
  pinMode(5, OUTPUT); 
  pinMode(10, INPUT);
  
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
  Serial.println("Setup done");
}

void loop() {
  
  sensorbright = analogRead(A0);
  sensortmpe = analogRead(A1);

  // map the sensor values to a wide range of pitches
  //int pitch = map(sensorbright, sensorLow, sensorHigh, 50, 4000);

  Serial.println("------------------------------");
  Serial.print("Helligkeit: ");
  Serial.println(sensorbright);

  Serial.print("Pruefwert:    ");
  Serial.println(sensorbright, BIN);
  Serial.print("Daten    : ");
  for (byte i=11; i>0; i--){
    byte state = bitRead(sensorbright,i);
    Serial.print(state);
    digitalWrite(5,state);
    delay(10);
    }
  byte state = bitRead(sensorbright,0);
  Serial.print(state);
  digitalWrite(5,state);
  Serial.println();
  Serial.println();
  
  float voltage = (sensortmpe/1024.0) * 5.0;
  Serial.print("Temperatur. Spannung: ");
  Serial.print(voltage);

  
  Serial.print(", degrees C: "); 
  float temperature = (voltage - .5) * 100;
  int tempe = temperature -3;
  Serial.println(tempe);
  Serial.print("Pruefwert:        ");
  Serial.println(tempe, BIN); 
  Serial.print("Daten    : ");
    for (byte i=11; i>0; i--){
    state = bitRead(tempe,i);
    Serial.print(state);
    digitalWrite(5,state);
    delay(10);
    }
  state = bitRead(sensorbright,0);
  Serial.println(state);
  digitalWrite(5,state);
  
  Serial.println("------------------------------");
  Serial.println();
  // wait for a moment
  delay(2000);
}

