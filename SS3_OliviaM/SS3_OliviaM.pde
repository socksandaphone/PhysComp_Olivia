/*
////////////////////////////////////////////////////////
Assignment 3
MTEC 2280
Olivia Mundie
////////////////////////////////////////////////////////
*/
import processing.serial.*;

Serial myPort;

int val = 0;

int catR;
int catG;
int catB;

int currentChannel = 0;
int lastChannel = 0;

int tempVal = 0;

int bkgR = 180;
int bkgB = 100;
int bkgG = 200;

void setup() {
  size(700,700);
  textAlign(CENTER);
  ellipseMode(CENTER);
  textSize(20);
  
  printArray(Serial.list());
  String portName = Serial.list()[2]; 
  myPort = new Serial(this, portName, 115200);
  
  catR = val;
  catG = val;
  catB = val;
}

void draw() {
  background(bkgR,bkgG,bkgB);
  
  if (myPort.available() > 0) {
    val = myPort.read(); 
  }
  
  fill(0);
  textSize(27);
  text("press X to switch between red, green, and blue channels",width/2,height/6);
  textSize(15);
  text("hold down space and move the mouse while twisting the dial to adjust background color",width/2, 150);
  
  // cat head
  noStroke();
  fill(catR,catG,catB);
  ellipse(width/2,height/2,200,200);
  triangle(250,350, 265,210, 340,260);
  triangle(450,350, 435,210, 360,260);
  //eyes
  fill(0);
  ellipse(280,350,20,40);
  ellipse(420,350,20,40);
  // mouth
  noFill();
  strokeWeight(5);
  stroke(0);
  arc(320,390,60,40, 0, 4);
  //arc(320,390,60,40, 0, val/60);
  arc(380,390,60,40, -0.7,3);
  //arc(380,390,60,40, -val/180,3);
  // whiskers
  strokeWeight(2);
  // right
  line(425,380, 525,350);
  line(425,390, 525,420);
  // left
  line(275,380, 175,350);
  line(275,390, 175,420);
  
  /* tried to adjust the whisker values here, didnt work out
  // right
  line(425,380, val*2,val*1.5);
  line(425,390, val*2,val*1.5 +70);
  // left
  line(275,380, 175,350);
  line(275,390, 175,420);
  */
  
  textSize(20);
  if (currentChannel == 0){
    fill(0);
    text("you are currently adjusting the red channel",width/2, 600);
    catR = val;
    fill(val);
    text("value = " + catR, width/2, 624);
  }
  else if (currentChannel == 1){
    fill(0);
    text("you are currently adjusting the green channel",width/2, 600); 
    catG = val;
    fill(val);
    text("value = " + catG, width/2, 624);
  }
  else if (currentChannel == 2){
    fill(0);
    text("you are currently adjusting the blue channel",width/2, 600);
    catB = val;
    fill(val);
    text("value = " + catB, width/2, 624);
  }
  else if (currentChannel == 3) {
    text("you are currently adjusting the background",width/2, 600);
    bkgR = val/5*6;
    bkgG = pmouseX/3;
    bkgB = pmouseY/3;
  }
  //System.out.println("the current channel is: " + currentChannel);
  //System.out.println("last channel is: "+lastChannel + "     current channel is: " + currentChannel);
  
  if (currentChannel != 3){
    lastChannel = currentChannel;
  }
  
  if (keyPressed){  
    if (key == ' '){
      currentChannel = 3;
    }
  }
  else {
    currentChannel = lastChannel;
  }
}


void keyPressed(){
  if (key == 'x' || key == 'X'){
    currentChannel++;
    if (currentChannel>2){
      currentChannel = 0;
    }
  }
}
