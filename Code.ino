#include <xmotion.h>
void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);  //LED
  pinMode(10, INPUT);  //Telecomanda

  pinMode(A1, INPUT);  //Dreapta
  pinMode(A2, INPUT);  //Diagonala Dreapta
  pinMode(4, INPUT);   //Mijloc
  pinMode(1, INPUT);   //Diagonala Stanga
  pinMode(0, INPUT);   //Stanga
}
void loop() {
  bool f = digitalRead(10);
  bool m = digitalRead(4);
  bool d = digitalRead(A1);
  bool s = digitalRead(0);
  bool ds = digitalRead(1);
  bool dd = digitalRead(A2);


  if (f == 1) {
    if (analogRead(A5) < 400 || analogRead(A4) < 400) {
      //xmotion.StopMotors(50);
      xmotion.Backward(100, 250);
      xmotion.Right0(50, 200);
    }
    if (m == 1) {
      xmotion.Forward(100,1);
    }
    if (dd == 1) {
      xmotion.ArcTurn(40, 0, 4);
    }
    if (ds == 1) {
      xmotion.ArcTurn(0, 40, 4);
    }
    if (d == 1) {
      xmotion.ArcTurn(40, 0, 250);
    }
    if (s == 1) {
      xmotion.ArcTurn(0, 40, 250);
      //xmotion.Forward(100,1);
    }

    xmotion.Forward(35, 1);
  } 
  else if (f == 0) 
  {
    xmotion.StopMotors(1);
    digitalWrite(9, 1);
  }
}
