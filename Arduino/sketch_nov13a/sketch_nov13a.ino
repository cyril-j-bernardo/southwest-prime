int pin1 = 2;
int pin2 = 3;
int pin3 = 4;
int pin4 = 5;
int pin5 = 6; 
int pin6 = 7;
int pin7 = 8;

void setup() {
  // put your setup code here, to run once:
pinMode(pin1, OUTPUT);
pinMode(pin2, OUTPUT);
pinMode(pin3, OUTPUT);
pinMode(pin4, OUTPUT);
pinMode(pin5, OUTPUT);
pinMode(pin6, OUTPUT);
pinMode(pin7, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);
//  digitalWrite(pin3, HIGH);
  digitalWrite(pin4, HIGH);
//  digitalWrite(pin5, HIGH);
  digitalWrite(pin6, HIGH);
  digitalWrite(pin7, HIGH);

  delay(500);

  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
  digitalWrite(pin5, LOW);
  digitalWrite(pin6, LOW);
  digitalWrite(pin7, LOW);

  delay(500);
}
