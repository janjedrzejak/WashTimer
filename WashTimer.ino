#include <Servo.h>

int Trig = 8;
int Echo = 9;

long Czas = 0;
int Odleglosc = 0;
int Max = 200;
int Min = 2;
Servo Serwo;

void setup() {
  Serial.begin(9600);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  Serwo.attach(2);
  Serwo.write(0);
}

void wyslij(int odczyt) {
  Serial.println(odczyt);
}

int i = 0;

void loop() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  Czas = pulseIn(Echo, HIGH);
  Odleglosc = Czas / 58;
    wyslij(Odleglosc);
    wyslij(i);
    if(Odleglosc < 30) {
      Serwo.write(i);
      i = i + 1;
    }

    if(i > 200 && Odleglosc > 30) {
      Serwo.write(0);
      i = 0;
    }
    delay(100);
  
}
