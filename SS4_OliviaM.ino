/*
Olivia M
MTEC 2280
Assignment 4
*/

// pins for pots and buttons
const int adcPin_1 = 1;
const int adcPin_2 = 2;
const int buttonPin_1 = 20;
const int buttonPin_2 = 21;

// buttons
bool buttonState_1 = 0;
bool buttonState_2 = 0;

// pots
int adcRead_1 = 0;
int adcRead_2 = 0;

// software timer
int lastTime = 0;
int currentTime = 0;
int timerInterval = 20; 

void setup() {
  pinMode(buttonPin_1, INPUT_PULLUP);
  pinMode(buttonPin_2, INPUT_PULLUP);
  analogReadResolution(8); // 8 bit, 0-255
  Serial.begin(115200);
}

void loop() {
  //map ADC read from 0 to 255 range into -128 to 127 range
  adcRead_1 = map(analogRead(adcPin_1), 0, 255, -128, 127);
  adcRead_2 = map(analogRead(adcPin_2), 0, 255, -128, 127);

  buttonState_1 = !digitalRead(buttonPin_1);
  buttonState_2 = !digitalRead(buttonPin_2);

  //Serial.printf("%i \t %i \t %i \t %i \n", adcRead_1, adcRead_2, buttonState_1, buttonState_2);

  currentTime = millis();
  if (currentTime - lastTime >= timerInterval){
    lastTime = currentTime;

    // send data to processing
    Serial.write(buttonState_1); // 1st byte
    Serial.write(buttonState_2); // 2nd byte
    Serial.write(adcRead_1); // 3rd byte
    Serial.write(adcRead_2); // 4th byte
    Serial.write('e'); // 5th
  }
}