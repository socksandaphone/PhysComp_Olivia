import processing.video.*;
import processing.serial.*;


Serial myPort; // creates object from Serial class
int val = 0; // creates variable for data coming from serial port
int lastVal = 0;
//video capture object
Capture video;

// movie objects
Movie vid1;
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
    //video = new Capture(this, cameras[1]);
    video.start();     //start video capture
  }      
  
  vid1 = new Movie(this, "vid1.mp4");
  vid1.loop();
  vid2 = new Movie(this, "vid2.mp4");
  //vid2.loop();
  vid3 = new Movie(this, "vid3.mp4");
  //vid3.loop();
  
  printArray(Serial.list()); // this line prints the port list to the console
  String portName = Serial.list()[2]; //change the number in the [] for the port you need
  //myPort = new Serial(this, portName, 115200);  // commented out while not communicating w arduino
}

void movieEvent (Movie vid1) { // (Movie vid1, Movie vid2, Movie vid3)
  vid1.read();
  //vid2.read();
  //vid3.read();
}

void draw() {
  if (video.available() == true) //if video feed is available
  {
    video.read();  //capture video pixels
  }
  image(video, -300, 0);
  image(vid1,640,0,640,720);
  
  // below all commented out while not communicating with arduino
  /*
  if (myPort.available() > 0) // If data is available,...
  { 
    val = myPort.read();       // ...read it and store it in val
  }
  
  
  text(val,width/2,height/2);
  */
  
  // or do like
  /*
  if (val != lastVal) {
    // switch vid
  }
  */
  
  
  // ears 
  noFill();
  stroke(255,0,0);
  strokeWeight(10);
  //triangle(100,300, 150,70, 200,100);
  //triangle(140,195, 105,70, 240,150);
  line(120,195, 80,70);
  line(80,70, 210,150);
  
  line(520,195, 560,70);
  line(560,70, 430,150);
  textSize(32);
  text("YOU ARE A CAT.",200,600);
  textSize(18);
  text("meow",200,620);
  
}
