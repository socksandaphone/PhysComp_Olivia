// photocell controls LED on/off
// button switches between which color light youre controlling
// buzzer buzzes when you press the button?

// pot control rate of flashing
// play different tone sequence depdning on the light that's selected

// to switch current light
currentLight = 1;

// photocell
int pResistor = 1;

// pin numbers of the LEDs
int redLed = 4;
int whiteLed = 5;
int greenLed = 6;
int blueLed = 7;

// button
int buttonPin = 2;
int buttonState = 0;
int lastButtonState = 0;


void setup() {
  pinMode(pResistor, INPUT);

  pinMode(redLed, OUTPUT);
  pinMode(whiteLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);

  pinMode(buttonPin, INPUT);

  Serial.begin(115200);
}

void loop() {


}
