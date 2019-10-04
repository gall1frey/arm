#include<Servo.h>

int pos=90,x=90, y=90, z=90, a;

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
    if(a==49) {x+=2; base.write(x);}
    if(a==50) {y+=2; vert.write(y);}
    if(a==51) {z+=2; hor.write(z);}
    if(a==52) {x-=2; base.write(x);}
    if(a==53) {y-=2; vert.write(y);}
    if(a==54) {z-=2; hor.write(z);}
  }
}

