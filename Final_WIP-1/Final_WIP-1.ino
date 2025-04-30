const int touchPin1; // treat
const int touchPin2; // toy
const int touchPin3; // vid switcher

const int touchVal1; // treat
const int touchVal2; // toy
const int touchVal3; // vid switcher

int touchThreshold; ////////// add value here

bool buttonState = 0;
bool lastButtonState = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  /////////////////////////// BUTTONS ///////////////////////////////////////////
  touchVal1 = analogRead(touchPin1);
  touchVal2 = analogRead(touchPin2);
  touchVal3 = analogRead(touchPin3);


  // map values?


  if (touchVal1 > touchThreshold){
    buttonState = 1;
    //lastButtonState = buttonState;
  }
  else {
    buttonState = 0;
  }

  if (touchVal2 > touchThreshold){
    buttonState = 1;
    //lastButtonState = buttonState;
  }
  else {
    buttonState = 0;
  }

  if (touchVal3 > touchThreshold){
    buttonState = 1;
    //lastButtonState = buttonState;
  }
  else {
    buttonState = 0;
  }
  lastButtonState = buttonState;
  if (buttonState && !lastButtonState){
    // do function
    toy();
    treat();
  }

  // serial monitor shtufff
  Serial.printf("touch val 1: %i \ntouch val 2: %i \ntouch val 3: %i \n", touchVal1, touchVal2, touchVal3); // test that ur getting readings from the 'buttons'
}

  void toy(){
    Serial.println("toy function yippy");
  }

  void treat(){
    Serial.println("treat function yipppiieeieei");
  }

