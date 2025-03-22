/*
////////////////////////////////////////////////////////
Midterm
MTEC 2280
Olivia Mundie
////////////////////////////////////////////////////////
*/

// to switch current light
int currentLight = 1;

// array for the different tones
int tones[8];

// photocell
int photoPin = 1;
int photoVal = 1;

// buzzer
int piezoPin = 2;

// pin numbers of the LEDs
int redLed = 4;
int whiteLed = 5;
int greenLed = 6;
int blueLed = 7;

// button
int buttonPin = 17;
bool buttonState = 0;
int lastButtonState = 0;

// potentiometer/blinking
int potPin = 18;
int ledState = 0;

// timing
int currentTime = 0;
int lastTime = 0;
int timerInterval = 1000;

void setup() {
  analogReadResolution(10);

  pinMode(photoPin, INPUT);

  pinMode(redLed, OUTPUT);
  pinMode(whiteLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);

  pinMode(buttonPin, INPUT);

  Serial.begin(115200);
}

void loop() {
  // button 
  buttonState = digitalRead(buttonPin);
  if ((buttonState==HIGH) && (lastButtonState==LOW)){
    currentLight++;
    addTones();
    if (currentLight>4){ // reset after 4
      currentLight=1;
    }
    playTone();
    //Serial.println("button was pressed!");
  } 
  lastButtonState = buttonState;
  //Serial.printf("currentLight: %i \n",currentLight);
  
  // photocell
  photoVal = analogRead(photoPin);
  if (photoVal < 700){
    // turn lights off
    digitalWrite(redLed,LOW);
    digitalWrite(whiteLed,LOW);
    digitalWrite(greenLed,LOW);
    digitalWrite(blueLed,LOW);
  }
  else {
    lightsOn();
  }
  Serial.printf("photoVal is: %i \n",photoVal);
  
  // potentiometer/blinking
  currentTime = millis();
  timerInterval = map(analogRead(potPin), 0, 1023, 10, 1000);
  if (currentTime - lastTime >= timerInterval){
    lastTime = currentTime;
    ledState = !ledState;
  }
}

// turn on  lights
void lightsOn() {
  if (currentLight == 1){
    digitalWrite(redLed,ledState);
    digitalWrite(whiteLed,LOW);
    digitalWrite(greenLed,LOW);
    digitalWrite(blueLed,LOW);
  }
  else if (currentLight == 2){
    digitalWrite(redLed,LOW);
    digitalWrite(whiteLed,ledState);
    digitalWrite(greenLed,LOW);
    digitalWrite(blueLed,LOW);
  }
  else if (currentLight == 3){
    digitalWrite(redLed,LOW);
    digitalWrite(whiteLed,LOW);
    digitalWrite(greenLed,ledState);
    digitalWrite(blueLed,LOW);
  }
  else if (currentLight == 4){
    digitalWrite(redLed,LOW);
    digitalWrite(whiteLed,LOW);
    digitalWrite(greenLed,LOW);
    digitalWrite(blueLed,ledState);
  }
}

// play tones
void playTone() {
  for (int i=0; i<8; i++){ // 8 = length of array
    tone(piezoPin, tones[i], 200);
  }
}

// populate tones array
void addTones() {
  for (int i = 0; i<8; i++){ 
    tones[i] = random(100,1000);
  }
  //Serial.println("new tones were added!\n");
}



// 
/*
set playing true/false every time button pressed
bool playing = false;

playTone(playing){
  if(playing)
  play the lfufcking loop or whatever slay
}
*/
