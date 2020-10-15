#include <SPI.h>   //the communication interface with the modem
#include "RF24.h"   //the library which helps us to control the radio modem

int msg[1];

//define the flex sensor input pins 
int flex_5 = A5; int flex_4 = A4; 
int flex_3 = A3; int flex_2 = A2; 
int flex_1 = A1;

//define variables for flex sensor values
int flex_5_val; int flex_4_val; 
int flex_3_val; int flex_2_val; 
int flex_1_val;

RF24 radio(5,10);  //5 and 10 are a digital pin numbers to which signals CE and CSN are connected.

const uint64_t pipe = 0xE8E8F0F0E1LL;  //the address of the modem, that will receive data from Arduino.

void setup(void){ Serial.begin(9600); 
radio.begin();  //it activates the modem.
radio.openWritingPipe(pipe);   //sets the address of the receiver to which the program will send data.
}

void loop(){
flex_5_val = analogRead(flex_5);   //175 - 0
flex_5_val=map(flex_5_val,1023,0,0,10); msg[0] = flex_5_val;
radio.write(msg, 1);

data = msg[0], pos=map(data, 21, 30, 175, 0);
myServo4.write(pos);
}
if(msg[0] <41 && msg[0]>30){
data = msg[0], pos=map(data, 31, 40, 175, 0); 
myServo2.write(pos);
}
if(msg[0] <51 && msg[0]>40){
data = msg[0], pos=map(data, 41, 40, 175, 0); 
myServo2.write(pos);
}
