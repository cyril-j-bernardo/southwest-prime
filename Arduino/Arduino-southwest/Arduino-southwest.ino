
int inf_detect = 13;
int ultrasound = 12;

int inf_detect_val = 0;
int ultrasound_val = 0;

int binary0 = 2;
int binary1 = 3;
int binary2 = 4;
int binary3 = 5;
int binary4 = 6;
int binary5 = 7;
int binary6 = 8;
int binary7 = 9;

int binary0_val = 0;
int binary1_val = 0;
int binary2_val = 0;
int binary3_val = 0;
int binary4_val = 0;
int binary5_val = 0;
int binary6_val = 0;
int binary7_val = 0;

int binary_val[] = {binary0_val, binary1_val, binary2_val, binary3_val, binary4_val, binary5_val, binary6_val, binary7_val};
//int binary_val[] = {0};

void setup() {
  Serial.begin(9600);
  Serial.println("Starting setup...");
  // put your setup code here, to run once:
  pinMode(inf_detect, INPUT);
  Serial.println("Starting loop...");

  pinMode(binary0, OUTPUT);
  pinMode(binary1, OUTPUT);
  pinMode(binary2, OUTPUT);
  pinMode(binary3, OUTPUT);
  pinMode(binary4, OUTPUT);
  pinMode(binary5, OUTPUT);
  pinMode(binary6, OUTPUT);
  pinMode(binary7, OUTPUT);

}


void loop() {
  // put your main code here, to run repeatedly:
  inf_detect_val = digitalRead(inf_detect);
  ultrasound_val = analogRead(ultrasound);
  long duration, inches, cm;

  pinMode(ultrasound, OUTPUT);
  digitalWrite(ultrasound, LOW);
  delayMicroseconds(2);
  digitalWrite(ultrasound, HIGH);
  delayMicroseconds(5);
  digitalWrite(ultrasound, LOW);

  pinMode(ultrasound, INPUT);
  duration = pulseIn(ultrasound, HIGH);

  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  int zeros = 8 - String(inches,BIN).length();
  String myStr;

  for (int i=0; i<zeros; i++) {
    myStr = myStr + "0";
  }
  Serial.print(myStr);
  myStr = myStr + String(inches,BIN);

  for(int x=0;x<8;x++){
    binary_val[x] = myStr[x];
  }
  
//  binary_val = {binary0_val, binary1_val, binary2_val, binary3_val, binary4_val, binary5_val, binary6_val, binary7_val};

  for(int x = 0; x<=8;x++){
    if(binary_val[x] == 48){
      binary_val[x] == LOW;
    }
    else{
      binary_val[x] == HIGH;
    }
  }
  
  binary0_val = binary_val[0]-48;
  binary1_val = binary_val[1]-48;
  binary2_val = binary_val[2]-48;
  binary3_val = binary_val[3]-48;
  binary4_val = binary_val[4]-48;
  binary5_val = binary_val[5]-48;
  binary6_val = binary_val[6]-48;
  binary7_val = binary_val[7]-48;

  binary_val[0] = binary_val[0]-48;
  binary_val[1] = binary_val[1]-48;
  binary_val[2] = binary_val[2]-48;
  binary_val[3] = binary_val[3]-48;
  binary_val[4] = binary_val[4]-48;
  binary_val[5] = binary_val[5]-48;
  binary_val[6] = binary_val[6]-48;
  binary_val[7] = binary_val[7]-48;

  for(int x = 0; x<8; x++){
    if(binary_val[x] == 0){
      binary_val[x] = LOW;
    }
    else{
      binary_val[x] = HIGH;
    }
  }

  
  /*digitalWrite(binary0, binary0_val);
  digitalWrite(binary1, binary1_val);
  digitalWrite(binary2, binary2_val);
  digitalWrite(binary3, binary3_val);
  digitalWrite(binary4, binary4_val);
  digitalWrite(binary5, binary5_val);
  digitalWrite(binary6, binary6_val);
  digitalWrite(binary7, binary7_val);*/

  digitalWrite(binary0, binary_val[0]);
  digitalWrite(binary1, binary_val[1]);
  digitalWrite(binary2, binary_val[2]);
  digitalWrite(binary3, binary_val[3]);
  digitalWrite(binary4, binary_val[4]);
  digitalWrite(binary5, binary_val[5]);
  digitalWrite(binary6, binary_val[6]);
  digitalWrite(binary7, binary_val[7]);
  

  Serial.print("Ultrasonic Value: ");
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.print("\t");
  Serial.print("Motion Detection: ");
  Serial.print(inf_detect_val);
  Serial.print("\t");
  Serial.print("Binary Value: ");
  Serial.print(myStr);
  Serial.println();
  Serial.print(binary_val[0]);
  Serial.print("\t");
  Serial.print(binary_val[1]);
  Serial.print("\t");
  Serial.print(binary_val[2]);
  Serial.print("\t");
  Serial.print(binary_val[3]);
  Serial.print("\t");
  Serial.print(binary_val[4]);
  Serial.print("\t");
  Serial.print(binary_val[5]);
  Serial.print("\t");
  Serial.print(binary_val[6]);
  Serial.print("\t");
  Serial.print(binary_val[7]);
  Serial.println();
  delay(100);

}

long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}

