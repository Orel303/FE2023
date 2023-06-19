#include <Servo.h>
Servo myservo;

void rgb(int r, int g, int b) {
  digitalWrite(8, 1 - r);
  digitalWrite(10, 1 - g);
  digitalWrite(11, 1 - b);
}


void rul(int a) {
  myservo.write(a);
}

void move(int s) {
  s = constrain(s, -255, 255);
  if (s > 0) {
    digitalWrite(4, 0);
    digitalWrite(5, 1);
  }
  else if (s < 0) {
    digitalWrite(4, 1);
    digitalWrite(5, 0);
    s = -s;
  }
  else {
    digitalWrite(4, 0);
    digitalWrite(5, 0);
    s = 0;
  }
  analogWrite(6, s);
}

void setup() {
  Serial.begin(115200);
  myservo.attach(9);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, 1);
  pinMode(10, 1);
  pinMode(11, 1);
  rgb(0, 0, 0);

  pinMode(4, 1);
  pinMode(5, 1);
  pinMode(6, 1);
  rul(90);
}
//move(100);

void loop() {
  int b = digitalRead(7);
  if (Serial.available() > 0) {
    String msg = Serial.readStringUntil('$');
    Serial.print(String(b) + "$");
  }
}
