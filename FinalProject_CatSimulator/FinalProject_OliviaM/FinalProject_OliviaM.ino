#include <ESP32Servo.h> 

// variables for touch button functionality
// set pin numbers
const int touchPin1 = 4; // treat
const int touchPin2 = 5; // toy
const int touchPin3 = 6; // vid switcher
// to store touch values
int touchVal1; // treat
int touchVal2; // toy
int touchVal3; // vid switcher
const int threshold = 48000;  // threshold for touch buttons
int touchState1; // current reading from touch button
int touchState2;
int touchState3;
int lastTouchState1 = LOW; // previous reading from touch button
int lastTouchState2 = LOW;
int lastTouchState3 = LOW;

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time

// for servo functionality
Servo toyServo; 
Servo treatServo;
// set pin numbers
const int servoPin1 = 1; // treat
const int servoPin2 = 2; // toy
int toyAngle = 0;  //angle of servo motor
int treatAngle = 0;


void setup() {
  toyServo.attach(servoPin2); // attach servo object to physical pin
  treatServo.attach(servoPin1);

  toyServo.write(toyAngle); // set initial angle 
  treatServo.write(treatAngle);

  Serial.begin(115200);
}

void loop() {
  // read the state of the pin
  touchVal1 = touchRead(touchPin1);
  touchVal2 = touchRead(touchPin2);
  touchVal3 = touchRead(touchPin3);

  // set value to either HIGH or LOW 
  if (touchVal1 < threshold) {
    touchVal1 = HIGH;
  } 
  else {
    touchVal1 = LOW;
  }
  if (touchVal2 < threshold) {
    touchVal2 = HIGH;
  } 
  else {
    touchVal2 = LOW;
  }
  if (touchVal3 < threshold) {
    touchVal3 = HIGH;
  } 
  else {
    touchVal3 = LOW;
  }

/*
some of the code below taken from https://lastminuteengineers.com/esp32-basics-capacitive-touch-pins/
*/
  // if button 1 is touched:
  if (touchVal1 != lastTouchState1) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce delay, so take it as the actual current state:
    // if the touch state has changed:
    if (touchVal1 != touchState1) {
      touchState1 = touchVal1;
      // only run function if the new touch state is HIGH
      if (touchState1 == HIGH) {
        //playVid(); // this function only used for testing
        Serial.write(touchState1); // tell processing that a button was pressed so it knows to switch the vid
      }
      else {
        Serial.write(touchState1); // tell processing that a button is not being pressed
      }
    }
  }

  // if button 2 is touched:
  if (touchVal2 != lastTouchState2) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (touchVal2 != touchState2) {
      touchState2 = touchVal2;
      if (touchState2 == HIGH) {
        toy();
      }
    }
  }

  // if button 3 is touched:
  if (touchVal3 != lastTouchState3) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (touchVal3 != touchState3) {
      touchState3 = touchVal3;
      if (touchState3 == HIGH) {
        treat();
      }
    }
  }

  // save touch value
  lastTouchState1 = touchVal1;
  lastTouchState2 = touchVal2;
  lastTouchState3 = touchVal3;
}

void playVid() { // this function only used for testing
  //Serial.println("viddy switched");
}

void toy() {
  //Serial.println("toy function yippy"); // this line used for testing only
  // move servo
  for (int i=0;i<180;i++){
    toyAngle = i;
    delay(5);   
    toyServo.write(toyAngle);
  }
}

void treat() {
  //Serial.println("treat function yipppiieeieei"); // this line used for testing only
  // move servo
  for (int i=0;i<180;i++){
    treatAngle = i;
    delay(5);  
    treatServo.write(treatAngle);
  }
}