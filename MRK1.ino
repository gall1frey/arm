#include<Servo.h>

int pos=90, a;

Servo base, vert, hor;

void setup(){
  Serial.begin(9600);
  base.attach(3);
  base.write(pos);
  vert.attach(5);
  vert.write(pos);
  hor.attach(6);
  hor.write(pos);
  Serial.println("Hello");
}

void loop(){
  if(Serial.available()){
    a=Serial.read();
    Serial.println("Servo Selected");
    delay(300);
    Serial.println(base.read());
    Serial.println(vert.read());
    Serial.println(hor.read());
    pos=Serial.read();
    if(a==49) {base.write(pos); Serial.println("Moved");}
    if(a==50) {vert.write(pos); Serial.println("Moved");}
    if(a==51) {hor.write(pos); Serial.println("Moved");}
  }
}

