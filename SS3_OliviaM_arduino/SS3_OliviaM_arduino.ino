/*
////////////////////////////////////////////////////////
Assignment 3
MTEC 2280
Olivia Mundie
////////////////////////////////////////////////////////
*/

const int potPin = 18;
const int numReads = 16;  
int reading[numReads];  
int count = 0;      

void setup() {
  Serial.begin(115200);
  analogReadResolution(11);
}

void loop() {
  reading[count] = analogRead(potPin); 
  count++;

  if (count >= numReads) {
    count = 0; 
  }

  int sum = 0;    

  for (int i = 0; i < numReads; i++){
    sum += reading[i];  
  }

  int analogValue = sum / numReads; 
  
  int mapVal = map(analogValue, 0, 2047, 0, 255);

  Serial.write(mapVal);
  delay(20);
}
