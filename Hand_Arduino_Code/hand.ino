#include <SoftwareSerial.h>
#include <Servo.h>

String readString;
Servo thumbServo, pointerServo, middleServo, ringServo, littleServo;  // create servo object to control a servo

void setup() {
  Serial.begin(115200);

  // thumbServo.writeMicroseconds(1500); //set initial servo position if desired
  
  thumbServo.attach(6);  //the pin for the thumbServo control
  pointerServo.attach(7);  //the pin for the pointerServo control
  middleServo.attach(8);  //the pin for the middleServo control
  ringServo.attach(9);  //the pin for the ringServo control
  littleServo.attach(10);  //the pin for the littleServo control
  Serial.println("Setup Done"); // so I can keep track of what is loaded
}

void loop() {

  if (Serial.available())  {
    char c = Serial.read();  //gets one byte from serial buffer
    if (c == '#') {
      if (readString.length() >1) {
        //Serial.println(readString); //prints string to serial port out
        String readStringsub = readString.substring(1, 8); 
        //Serial.println(readStringsub);

        int n = readStringsub.substring(3, 8).toInt();

        // auto select appropriate value, copied from someone elses code.
        if(n >= 500)
        {
          Serial.print("writing Microseconds: ");
          Serial.println(n);
          Serial.println(readString.substring(0, 4));
          if(readString.substring(0, 4) == "001P") thumbServo.writeMicroseconds(n);
          if(readString.substring(0, 4) == "002P") pointerServo.writeMicroseconds(n);
          if(readString.substring(0, 4) == "003P") middleServo.writeMicroseconds(n);
          if(readString.substring(0, 4) == "004P") ringServo.writeMicroseconds(n);
          if(readString.substring(0, 4) == "005P") littleServo.writeMicroseconds(n);
        }
        else
        {   
          Serial.print("writing Angle: ");
          Serial.println(n);
          if(readString.substring(0, 4) == "001P") thumbServo.write(n);
          if(readString.substring(0, 4) == "002P") pointerServo.write(n);
          if(readString.substring(0, 4) == "003P") middleServo.write(n);
          if(readString.substring(0, 4) == "004P") ringServo.write(n);
          if(readString.substring(0, 4) == "005P") littleServo.write(n);
        }
         readString=""; //clears variable for new input
      }
    } 
    else {     
      readString += c; //makes the string readString
    }
  }
}

