/*
   Miguel Frias Mayo A01024080
   Jose Granger Salgado A01023661
   It is a counter that can count from 0 to 39. It has a +1, -1, +10 and -10 options.
   It can be turned on and off via the potentiometer.
   It has a reset and a safety for that reset.
*/

#include <Servo.h>
Servo servo;

void setup() {

  Serial.begin(9600);
  servo.attach(1);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);  //HERE THE PIN MODES ARE DECLARED
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, INPUT) ;
}

const int topled = 8;
const int middleled = A0;
const int bottomled = 11;
const int leftupled = 13;
const int leftdownled = 12;
const int rightupled = 9;
const int rightdownled = 10;
const int RGBgreen = A2;
const int RGBblue = A3;
const int RGBred = A1;
const int upbutton = 2;    //HERE I NAME THE VARIABLES

const int downbutton = 3;
const int rightbutton = 5;
const int leftbutton = 4;
const int abutton = 7;
const int bbutton = 6;
const int buzzer = 0;
const int pot = A4;
const int IRsensor = A5;
int i = 0; //for the counter (0-9)
int c = 0; //THIS IS THE TOTAL COUNT (0-39)

void loop() {
  if (analogRead(pot) < 250) {
    //START NUMBER COUNTER
    if (digitalRead(upbutton) == LOW && c <= 39 && analogRead(IRsensor) > 250) {
      c++;  //triggered :)
      delay(1000);
      Serial.print("up");  //THIS ADDS 1 TO THE NUMBER
      Serial.print(c);
    };
    if (digitalRead(downbutton) == LOW && c >= -1 && analogRead(IRsensor) > 250) {
      c--;
      delay(1000);
      Serial.print("down");   //THIS SUBTRACTS 1
      Serial.print(c);
    };
    if (!digitalRead(rightbutton) && c <= 30 && analogRead(IRsensor) > 250) {
      c = c + 10;
      delay(1000);  //THIS ADDS 10
    }
    if (!digitalRead(leftbutton) && c >= 9 && analogRead(IRsensor) > 250) {
      c = c - 10;
      delay(1000);
    }
    if (c == -1 || c == 40) {
      for (int j = 1; j <= 3; j++) {
        analogWrite(RGBred, 255);
        delay(200);
        analogWrite(RGBred, 0);  //THIS FLASHES RED WHEN LIMIT IS PASSED
        delay(200);
      };
      Serial.print("limit passed!");
      switch (c) {
        case 40:
          c = c - 1;
          Serial.print("MORE");  //IF IT WAS MORE THAN 39
          break;
        case -1:
          c = c + 1;
          Serial.print("LESS");  //IF IT WAS LESS THAN 0
          break;
      };
    };
    if (c < 40 && c > 29) {
      i = c - 30; //THIS SETS i THE LAST DIGIT
      servo.write(180); //THIS SETS SERVO IN POSITION 3
    }
    if (c < 30 && c > 19) {
      i = c - 20; //THIS SETS i THE LAST DIGIT
      servo.write(120); //SETS SERVO IN POSITION 2
    }
    if (c < 20 && c > 9) {
      i = c - 10; //THIS SETS i THE LAST DIGIT
      servo.write(60); //SETS SERVO IN POSITION 1
    }
    if (c < 10 && c > -1) {
      i = c; //THIS SETS i THE LAST DIGIT
      servo.write(1); //SETS SERVO IN POSITION 0
    }
    switch (i) {
      case 0:
        digitalWrite(topled, HIGH);
        digitalWrite(bottomled, HIGH);
        analogWrite(middleled, 0);
        digitalWrite(rightupled, HIGH);
        digitalWrite(rightdownled, HIGH);
        digitalWrite(leftupled, HIGH);
        digitalWrite(leftdownled, HIGH);
        analogWrite(RGBgreen, 0);
        break;
      case 1:
        digitalWrite(topled, LOW);
        digitalWrite(bottomled, LOW);
        analogWrite(middleled, 0);
        digitalWrite(rightupled, HIGH);
        digitalWrite(rightdownled, HIGH);
        digitalWrite(leftupled, LOW);
        digitalWrite(leftdownled, LOW);
        analogWrite(RGBgreen, 0);
        break;
      case 2:
        digitalWrite(topled, HIGH);
        digitalWrite(bottomled, HIGH);
        analogWrite(middleled, 255);
        digitalWrite(rightupled, HIGH);
        digitalWrite(rightdownled, LOW);
        digitalWrite(leftupled, LOW);
        digitalWrite(leftdownled, HIGH);
        analogWrite(RGBgreen, 0);
        break;
      case 3:
        digitalWrite(topled, HIGH);
        digitalWrite(bottomled, HIGH);
        analogWrite(middleled, 255);
        digitalWrite(rightupled, HIGH);
        digitalWrite(rightdownled, HIGH);
        digitalWrite(leftupled, LOW);
        digitalWrite(leftdownled, LOW);
        analogWrite(RGBgreen, 0);
        break;
      case 4:
        digitalWrite(topled, LOW);
        digitalWrite(bottomled, LOW);
        analogWrite(middleled, 255);
        digitalWrite(rightupled, HIGH);
        digitalWrite(rightdownled, HIGH);
        digitalWrite(leftupled, HIGH);
        digitalWrite(leftdownled, LOW);
        analogWrite(RGBgreen, 0);
        break;
      case 5:
        digitalWrite(topled, HIGH);
        digitalWrite(bottomled, HIGH);
        analogWrite(middleled, 255);
        digitalWrite(rightupled, LOW);
        digitalWrite(rightdownled, HIGH);
        digitalWrite(leftupled, HIGH);
        digitalWrite(leftdownled, LOW);
        analogWrite(RGBgreen, 0);
        break;
      case 6:
        digitalWrite(topled, HIGH);
        digitalWrite(bottomled, HIGH);
        analogWrite(middleled, 255);
        digitalWrite(rightupled, LOW);
        digitalWrite(rightdownled, HIGH);
        digitalWrite(leftupled, HIGH);
        digitalWrite(leftdownled, HIGH);
        analogWrite(RGBgreen, 0);
        break;
      case 7:
        digitalWrite(topled, HIGH);
        digitalWrite(bottomled, LOW);
        analogWrite(middleled, 0);
        digitalWrite(rightupled, HIGH);
        digitalWrite(rightdownled, HIGH);
        digitalWrite(leftupled, LOW);
        digitalWrite(leftdownled, LOW);
        analogWrite(RGBgreen, 0);
        break;
      case 8:
        digitalWrite(topled, HIGH);
        digitalWrite(bottomled, HIGH);
        analogWrite(middleled, 255);
        digitalWrite(rightupled, HIGH);
        digitalWrite(rightdownled, HIGH);
        digitalWrite(leftupled, HIGH);
        digitalWrite(leftdownled, HIGH);
        analogWrite(RGBgreen, 0);
        break;
      case 9:
        digitalWrite(topled, HIGH);
        digitalWrite(bottomled, HIGH);
        analogWrite(middleled, 255);
        digitalWrite(rightupled, HIGH);
        digitalWrite(rightdownled, HIGH);
        digitalWrite(leftupled, HIGH);
        digitalWrite(leftdownled, LOW);
        analogWrite(RGBgreen, 0);
        break;
      default:
        analogWrite(RGBgreen, 255);
        break;
    }
    //END NUMBER COUNTER
    if (!digitalRead(abutton) && !digitalRead(bbutton)) {
      delay(1000);
      if (!digitalRead(abutton) && !digitalRead(bbutton)) {
        tone(buzzer, 3000);
        delay(200);
        noTone(buzzer);
        c = 0;
      }
    }
  } else {
    c = 0;
    ledsoff();
  }
}

void ledsoff() {
  digitalWrite(topled, LOW);
  digitalWrite(bottomled, LOW);
  analogWrite(middleled, 0);
  digitalWrite(rightupled, LOW); //TURNS LEDS OFF
  digitalWrite(rightdownled, LOW);
  digitalWrite(leftupled, LOW);
  digitalWrite(leftdownled, LOW);
  analogWrite(RGBgreen, 0);
}
