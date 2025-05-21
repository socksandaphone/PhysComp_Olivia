import processing.video.*;
import processing.serial.*;


Serial myPort; 
int val = 0; // creates variable for data coming from serial port
int lastVal = 0;
int currentMovie = 1; // to keep track of which vid is playing

Capture video; //video capture object
Movie vid1; // movie objects
Movie vid2;
Movie vid3;

void setup() 
{
  size(1280, 720);
  textSize(32);
  textAlign(CENTER);
  
  String[] cameras = Capture.list();  //list of available cameras
  
  if (cameras.length == 0) 
  {
    println("There are no cameras available for capture.");
    exit();
  } 
  else 
  {
    println("Available cameras:");
    for (int i = 0; i < cameras.length; i++) 
    {
      println(cameras[i]);  //print available cameras to serial monitor
    }

    video = new Capture(this,width,height,"pipeline:avfvideosrc device-index=0",30);
    video.start();     //start video capture
  }      
  
  vid1 = new Movie(this, "vid1.mp4");
  vid1.loop();
  vid2 = new Movie(this, "vid2.mp4");
  vid2.loop();
  vid3 = new Movie(this, "vid3.mp4");
  vid3.loop();
  
  printArray(Serial.list()); // this line prints the port list to the console
  String portName = Serial.list()[2]; //change the number in the [] for the port you need
  myPort = new Serial(this, portName, 115200);  // commented out while not communicating w arduino
}

void movieEvent(Movie m) {
  if (m == vid1) {
    vid1.read();
  } 
  else if (m == vid2) {
    vid2.read();
  }
  else if (m == vid3) {
    vid3.read();
  }
}

void draw() {
  if (video.available() == true) //if video feed is available
  {
    video.read();  //capture video pixels
  }
  image(video, -300, 0);
  
  if (currentMovie == 1){
    vid1.play(); 
    image(vid1, 640,0,640,720);
  }
  else if (currentMovie == 2) {
    vid2.play();
    image(vid2, 640,0,640,720);  
  }
  else if (currentMovie == 3) {
    vid3.play();
    image(vid3,640,0,640,720);
  }
  
  
  if (myPort.available() > 0) // If data is available,...
  { 
    val = myPort.read();       // ...read it and store it in val
  }
  if (val==1) {
    currentMovie++;
    if (currentMovie>3){
      currentMovie = 1;
    }
    //println("currentmovie is: "+currentMovie);
    
    if (currentMovie == 1){
      vid2.stop();
      vid3.stop();
    }
    else if (currentMovie == 2) {
      vid1.stop();
      vid3.stop();
    }
    else if (currentMovie == 3) {
      vid1.stop();
      vid2.stop();
    }  
    val=0;
  }
  
  // ears 
  noFill();
  stroke(255);
  strokeWeight(10);
  line(120,195, 80,70);
  line(80,70, 210,150);
  
  line(520,195, 560,70);
  line(560,70, 430,150);
  textSize(32);
  text("YOU ARE A CAT.",200,600);
  textSize(18);
  text("meow",200,620);
}
