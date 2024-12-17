/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/



// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  
}

void set(int setting){
  digitalWrite(D0, setting);
  digitalWrite(D1, setting);
  digitalWrite(D2, setting);
  digitalWrite(D3, setting);
  digitalWrite(LED_BUILTIN, setting);
}

void hi(int dur=20){set(HIGH);delay(dur);}
void lo(int dur=20){set(LOW);delay(dur);}


void left(int dur=20){
  digitalWrite(D0, LOW);
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, LOW);
  printf("Forward\n");
  delay(dur);
}

void right(int dur=20){
  digitalWrite(D0, 1);
  digitalWrite(D1, 0);
  digitalWrite(D2, 0);
  digitalWrite(D3, 1);
  printf("Back\n");
  delay(dur);
}

void fwd(int dur=20){
  digitalWrite(D0, LOW);
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D3, HIGH);
  printf("Left\n");
  delay(dur);
}

void back(int dur=20){
  digitalWrite(D0, HIGH);
  digitalWrite(D1, LOW);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, LOW);
  printf("Right\n");
  delay(dur);
}

void alternator(){

  int min = 10000;
  int max = 12000;
  int steps = 2;

  for(int i=min; i<max; i+=(max-min)/steps ){
    // hi(i);
    // lo(i);
    fwd(i);
    lo(2000);

    back(i);
    lo(2000);

    left(i);
    lo(2000);

    right(i);
    lo(2000);
  }
}

void staticSet(int d0, int d1, int d2, int d3){
  digitalWrite(D0, d0);
  digitalWrite(D1, d1);
  digitalWrite(D2, d2);
  digitalWrite(D3, d3);
}

// the loop function runs over and over again forever
void loop() {
  alternator();
  // staticSet(0,0,0,0);
}
