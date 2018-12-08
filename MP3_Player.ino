/*2018-11-22
#
// ####################################################
TODO list :
// TODO /CHECK : pause doesnt work .... odnt know why
// updated for arduino NANO pin out
///////////////////////////////////////////////////


#define PlayOutput_PIN 11
#define NextOutput_PIN 12
#define PreviousOutput_PIN 10
###########################
*/
#include <GPD2846.h>

GPD2846 mp3(12,11,10); // Arduino pins D12 = S1 ((vol-, corner connection), D11 = S2, D10 = S3 on MP3 player

#define PushButton_PIN 13     // pin connected to the push button
#define AlimMP3_PIN 19 // A5
float musicduration= 10000;

float currenttime = 0;


void setup(){
  Serial.begin(115200);
pinMode(PushButton_PIN,INPUT);
pinMode(AlimMP3_PIN,OUTPUT);
      digitalWrite(AlimMP3_PIN,HIGH);
mp3.pause();
delay(200);
mp3.volumeDown();
Serial.println("volume down");
delay(200);
mp3.volumeDown();
Serial.println("volume down");
delay(200);
mp3.volumeDown();Serial.println("volume down");
}

void loop(){


if (digitalRead(PushButton_PIN)==HIGH){
  Serial.println("button pressed once  ");
currenttime = millis();
delay(100);
//#play music
mp3.play();

  Serial.println("play music");
    while (millis()-currenttime - musicduration <0)
    { if (digitalRead(PushButton_PIN)==HIGH)
      {  Serial.print("button pressed again  ");Serial.println(currenttime);
      mp3.next();
        Serial.println("play next");
      delay(100);
      currenttime = millis();
      }
    }
mp3.pause();
  Serial.println("pause music");
}
delay(300);
}
