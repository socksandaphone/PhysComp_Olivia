/*
////////////////////////////////////////////////////////
Assignment 2
MTEC 2280
Olivia Mundie
////////////////////////////////////////////////////////
*/

int ms = 500;
int pattern = 1; // to cycle through different patterns

// pin numbers of the LEDs
int redLed = 4;
int whiteLed = 5;
int greenLed = 6;
int blueLed = 7;

// button pin
int buttonPin = 1;
int buttonState = 0;
int lastButtonState = 0;

void setup() {
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
  delay(10);

  if ((buttonState==HIGH) && (lastButtonState==LOW)){
    pattern++;
    if (pattern>4){ // reset after 4
      pattern=1;
    }
  }
  
  lastButtonState = buttonState;

  // two on, two off
  if (pattern==1){
      digitalWrite(redLed, HIGH);
      digitalWrite(whiteLed, LOW);
      digitalWrite(greenLed, HIGH);
      digitalWrite(blueLed, LOW);
      delay(ms);
      digitalWrite(redLed, LOW);
      digitalWrite(whiteLed, HIGH);
      digitalWrite(greenLed, LOW);
      digitalWrite(blueLed, HIGH);
      delay(ms);
    
  }

  // one on at a time
  else if (pattern==2){
      digitalWrite(redLed, HIGH);
      digitalWrite(whiteLed, LOW);
      digitalWrite(greenLed, LOW);
      digitalWrite(blueLed, LOW);
      delay(ms);
      digitalWrite(redLed, LOW);
      digitalWrite(whiteLed, HIGH);
      digitalWrite(greenLed, LOW);
      digitalWrite(blueLed, LOW);
      delay(ms);
      digitalWrite(redLed, LOW);
      digitalWrite(whiteLed, LOW);
      digitalWrite(greenLed, HIGH);
      digitalWrite(blueLed, LOW);
      delay(ms);
      digitalWrite(redLed, LOW);
      digitalWrite(whiteLed, LOW);
      digitalWrite(greenLed, LOW);
      digitalWrite(blueLed, HIGH);
      delay(ms);
    
  }

  // each one comes on then all turn off
  else if (pattern==3){
      digitalWrite(redLed, LOW);
      digitalWrite(whiteLed, LOW);
      digitalWrite(greenLed, LOW);
      digitalWrite(blueLed, LOW);
      delay(ms);
      digitalWrite(redLed, HIGH);
      delay(ms);
      digitalWrite(whiteLed, HIGH);
      delay(ms);
      digitalWrite(greenLed, HIGH);
      delay(ms);
      digitalWrite(blueLed, HIGH);
      delay(ms);
    
  }

  // all on and flash 
  else if (pattern==4){
      digitalWrite(redLed, HIGH);
      digitalWrite(whiteLed, HIGH);
      digitalWrite(greenLed, HIGH);
      digitalWrite(blueLed, HIGH);
      delay(ms);
      for(int i=0;i<8;i++){ // flash 8 times
        digitalWrite(redLed, LOW);
        digitalWrite(whiteLed, LOW);
        digitalWrite(greenLed, LOW);
        digitalWrite(blueLed, LOW);
        delay(50);
        digitalWrite(redLed, HIGH);
        digitalWrite(whiteLed, HIGH);
        digitalWrite(greenLed, HIGH);
        digitalWrite(blueLed, HIGH);
        delay(50);
      }
      delay(ms);
    
  }

  //Serial.printf("button state is: %i \n",buttonState);
  //Serial.printf("pattern is: %i \n", pattern); // just to track what pattern we're on

}
