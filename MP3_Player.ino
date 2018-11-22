/*2018-11-22
#
// ####################################################
TODO list :
// TODO /CHECK : upload and verify the logic with hardware

///////////////////////////////////////////////////

###########################
*/


#define PushButton_PIN 7     // pin connected to the push button
#define PlayOutput_PIN 8
#define NextOutput_PIN 10
float musicduration= 15000;

float currenttime = 0;


void setup(){

pinMode(PushButton_PIN,INPUT);
pinMode(PlayOutput_PIN,OUTPUT);
pinMode(NextOutput_PIN,OUTPUT);

}

void loop(){


if (digitalRead(PushButton_PIN)==HIGH){
currenttime = millis();
delay(100);
//#play music
digitalWrite(PlayOutput_PIN,HIGH);
    while (currenttime - musicduration <0)
    { if (digitalRead(PushButton_PIN)==HIGH)
      {
      digitalWrite(NextOutput_PIN,HIGH);
      delay(100);
      currenttime = millis();
      }
    }
}
delay(300);
}
