/*
Olivia M
MTEC 2280
Assignment 4
*/

import processing.serial.*;
Serial myPort;

byte[] val; // create array of bytes

int catX = 0;
int catY = 0;

boolean lastButton1State = false;
boolean lastButton2State = false;

int catR = 255;
int catG = 255;
int catB = 255;

int foodX;
int foodY;

int score = 0;

void setup(){ 
  size(765,765);
  textAlign(CENTER);
  rectMode(CENTER);
  textSize(24);
  generateFood();
  
  printArray(Serial.list()); // find port
  String portName = Serial.list()[2];
  myPort = new Serial(this, portName, 115200);
  
}

void draw() {
  if (myPort.available() > 0) {
    val = myPort.readBytesUntil('e'); // read received bytes into an array until 'e' ascii value is received
  }
  
  if (val.length == 5) {
    println(val); // confirm data arrived
    
    // map to 0-255 and cast to int
    int pot_1 = int(map(val[2], -128, 127, 0, 255));
    int pot_2 = int(map(val[3], -128, 127, 0, 255));
    
    // cast byte values to boolean
    boolean b_1 = boolean(val[0]);
    boolean b_2 = boolean(val[1]);
    
    background(250,180,180);
    noStroke();
    
    //drawing cat 
    fill(catR, catG, catB);
    // cat can move max of 255, needs to get to canvas size of 765, so * 3
    catX = pot_1*3;
    catY = pot_2*3;
    // head
    ellipse(catX, catY, 100,100);
    // ears
    //fill(180);
    triangle(catX-50, catY, catX-40, catY-75, catX, catY-25); // left ear
    triangle(catX+50, catY, catX+40, catY-75, catX, catY-25); // right ear
    // eyes
    fill(0);
    ellipse(catX-30, catY, 10, 20);
    ellipse(catX+30, catY, 10, 20);
    
    drawFood(); // draw pellet
    
    // if cat in range of pellet
    if (catX > foodX-40 && catX < foodX+40 && catY < foodY+40 && catY > foodY-40) {
      // button 1
      if (b_1 && !lastButton1State){
        score++; 
        generateFood();
      }
    }
    lastButton1State = b_1;
    
    // button 2
    if (b_2 && !lastButton2State){
        // change color
        catR = int(random(0,255));
        catG = int(random(0,255));
        catB = int(random(0,255));
      }
    lastButton2State = b_2;
    
    fill(0);
    textSize(24);
    text("score: " + score, width/2, 700);
    textSize(18);
    text("left button = collect food          right button = change color", width/2, 50);

  }
}

// generate position of pellet
void generateFood() {  
  foodX = int(random(10,width-10));
  foodY = int(random(10,height-10));
}

// draw the pellet
void drawFood() {
  fill(110,70,30);
  rect(foodX, foodY, 10, 10); 
}
