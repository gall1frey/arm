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
    if(a==76) {x+=2; base.write(x);}
    else if(a==82) {x-=2; base.write(x);}
    else if(a==70) {y-=2; vert.write(y);}
    else if(a==66) {y+=2; vert.write(y);}
    else if(a<=49 && a>=57) {hor.write(z+10*a);}
    else if(a==71) {y-=2; vert.write(y) ;x+=2; base.write(x);}
    else if(a==73) {y-=2; vert.write(y); x-=2; base.write(x);}
    else if(a==72) {y+=2; vert.write(y); x+=2; base.write(x);}
    else if(a==74) {y+=2; vert.write(y); x-=2; base.write(x);}
  }
}

