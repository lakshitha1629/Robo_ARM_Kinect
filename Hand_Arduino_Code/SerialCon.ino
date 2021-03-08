#include <SoftwareSerial.h>
//SoftwareSerial mySerial(0,1);

char receivedChar[77];
//char receivedChar;


void setup()
{
    Serial.begin(115200);
//    mySerial.begin(115200);
    Serial.println("Setup Done");
}
void loop()
{
//    if(mySerial.available()>0)
//    {
      Serial.readBytes(receivedChar,77); //Read the serial data and store in var
//      receivedChar=Serial.read();
      Serial.println(receivedChar); //Print data on Serial Monitor
      delay(150);
//    }
}


 
