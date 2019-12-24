#include <Servo.h>

Servo a;
Servo b;
Servo c;
Servo d;
bool displayOutput;
String output;

void setup() {
  pinMode(13, OUTPUT); // for lazer
  digitalWrite(13, LOW);
  a.attach(4);
  b.attach(5);
  c.attach(6);
  d.attach(7);
  Serial.begin(9600);
  output = String();
  displayOutput = true;

}

//motor limits a=no limit, b 170 to 10, c 140 to 0, d is 110 to 0

void loop() {

  if (Serial.available()) {
    String input = String(Serial.readString());

    if (input[0] == 'a') {
      input[0] = '0';
      int rotation = extractValidInput(input);
      if (rotation != -1) {
        a.write(rotation);
        output = output + "You have rotated by " + rotation;
      }
    }


    if (input[0] == 'b') {
      input[0] = '0';
      int rotation = extractValidInput(input);
      if (rotation != -1) {
        //if motor within limits (0 to 170)
        if (rotation > 170) {
          rotation = 170;
        }
        b.write(rotation);
        output = output + "You have rotated by " + rotation;
      }
    }


    if (input[0] == 'c') {
      input[0] = '0';
      int rotation = extractValidInput(input);
      if (rotation != -1) {
        //if motor within limits (0 to 140)
        if (rotation > 140) {
          rotation = 140;
        }
        c.write(rotation);
        output = output + "You have rotated by " + rotation;
      }
    }


    if (input[0] == 'd') {
      input[0] = '0';
      int rotation = extractValidInput(input);
      if (rotation != -1) {
        //if motor within limits (0 to 110)
        if (rotation > 110) {
          rotation = 110;
        }
        d.write(rotation);
        output = output + "You have rotated by " + rotation;
      }
    }

    //Laser on or off
    if (input[0] == 'l') {
      if (input[1] == '0') {
        digitalWrite(13, LOW); //laser off
      }
      if (input[1] == '1') {
        digitalWrite(13, HIGH); //laser on
      }
    }

    delay(100);

    if (displayOutput) {
      Serial.println(output);
    }

  }

}

int extractValidInput(String in) {
  int out = in.toInt();
  if (out > -1 && out < 181) {
    return out;
  }
  return -1;
}
