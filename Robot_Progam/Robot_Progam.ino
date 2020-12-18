#include <IRremote.h>
#include <IRremoteInt.h>
// remote channel needs to be on SAT code 0160
int RECV_PIN = 19;          // AKA A5 analog pin
IRrecv irrecv(RECV_PIN);
decode_results results;

boolean senseRight = true;
boolean senseLeft = true;
//int reverseTime;
int delayTime;
int noMoveDelay;
int turnDelay;
void setup() {
  //setup pinouts
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(7, INPUT_PULLUP);
pinMode(8, INPUT_PULLUP);
pinMode(A4, OUTPUT);        // A4 is used as a ground for the IR recever
Serial.begin(9600);
irrecv.enableIRIn();        // start the receiver
delay(1500);
}

void loop() {
  infered();
//exit(0);
}

void maze() {               // this is the maze program
  forwards();
  delay(400);
}

void infered() {            // this is the program for the infered sensor
  analogWrite(A4, 0);       // sets A4 to ground for the IR recever
  delayTime = 300;
 if(irrecv.decode(&results)){
  Serial.print("protocal: ");
  Serial.println(results.decode_type, DEC);
  Serial.print("Use this code in sketch 0x");
  Serial.println(results.value,HEX);
  switch (results.value) {
    case 0x87CDD0EF:        // forwards
     forwards();
     break;
    case 0x153F90A7:        // backwards
     backwards();
     break;
    case 0xA519853B:        // 45 left
     left();
     delay(120);
     noMove();
     break;
    case 0x42DD49:          // 45 right
     right();
     delay(120);
     noMove();
     break;
    case 0x5CDD8FBD:        // stop moving
     noMove();
     break;
    case 0x37788763:        // forwards right
     right();
     delay(120);
     noMove();
     forwards();
     break;
    case 0x92DF9279:        // forwards left
     left();
     delay(120);
     noMove();
     forwards();
     break;
    case 0x31BB009F:        // left turn
     left();
     delay(400);
     noMove();
     forwards();
     break;
    case 0x6872B60C:        // left right
     right();
     delay(400);
     noMove();
     forwards();
     break;
    case 0x6E56F924:        // does a 180 turn
     right();
     delay(410);
     noMove();
     break;
    case 0xFAE193FF:        // opperates the Maze program
     maze();
     noMove();
     break;
    default:

    break;
  }
  irrecv.resume();    // recive the next value
 }
 delay(100);
}

void cockroach() {                // this is the cockroach program
  turnDelay = random(50,400);     // set to 200 for a 90 degree turn defalut [ random(50,400) ]
  senseRight = digitalRead(7);
  senseLeft = digitalRead(8);
  Serial.print(senseRight);
  Serial.print("...");
  Serial.print(senseLeft);
  Serial.print("...");
  Serial.println(turnDelay);
  if((senseRight == true)&&(senseLeft == true)){
  forwards();
}

if(senseRight == false){
  backwards();delay(1000);
  left();delay(turnDelay);
}

if(senseLeft == false){
  backwards();delay(1000);
  right();delay(turnDelay);
}

}

void zigzag() {       // this does a zig zag pattern
delayTime = 1100;
noMoveDelay = 200;
left();delay(100);
noMove();delay(noMoveDelay);
forwards();delay(delayTime);
noMove();delay(noMoveDelay);
right();delay(200);
noMove();delay(noMoveDelay);
forwards();delay(delayTime);
noMove();delay(noMoveDelay);
left();delay(200);
noMove();delay(noMoveDelay);
forwards();delay(delayTime);
noMove();delay(noMoveDelay);
right();delay(200);
noMove();delay(noMoveDelay);
forwards();delay(delayTime);
noMove();delay(noMoveDelay);
left();delay(100);
noMove();delay(noMoveDelay);
}

void square() {         // does a perfect square
delayTime = 1200;
forwards();delay(delayTime);
noMove();delay(200);
right();delay(200);
noMove();delay(200);
forwards();delay(delayTime);
noMove();delay(200);
right();delay(200);
noMove();delay(200);
forwards();delay(delayTime);
noMove();delay(200);
right();delay(200);
noMove();delay(200);
forwards();delay(delayTime);
noMove();delay(200);
left();delay(200);
noMove();delay(200);
}

void forwards() {
analogWrite(9, 225);analogWrite(5, 215);
analogWrite(10, 0);analogWrite(6, 0);
}

void backwards() {
analogWrite(9, 0);analogWrite(5, 0);
analogWrite(10, 200);analogWrite(6, 200);
}

void right() {
analogWrite(9, 200);analogWrite(5, 0);
analogWrite(10, 0);analogWrite(6, 200);
}

void left() {
analogWrite(9, 0);analogWrite(5, 200);
analogWrite(10, 200);analogWrite(6, 0);
}

void noMove() {
analogWrite(9, 0);analogWrite(5, 0);
analogWrite(10, 0);analogWrite(6, 0);
}
