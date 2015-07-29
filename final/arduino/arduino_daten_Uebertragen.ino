
int readPin = 6;
int writePin = 7;

void setup() {
  Serial.println("Starte Setup");
  Serial.begin(9600);
  pinMode(readPin, INPUT); 
  pinMode(writePin, OUTPUT);
  
  Serial.println("Setup done");
}

void loop() {
  
if (digitalRead(readPin) == HIGH){
  digitalWrite(writePin, HIGH);
}

digitalWrite(writePin, LOW);
  
}

