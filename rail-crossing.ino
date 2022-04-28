const byte white = 12;
const byte red1 = 11;
const byte red2 = 10;
const byte btn1 = 9;
const byte btn2 = 8;
const byte buzzer = 6;
unsigned int redInterval = 500;
unsigned int whiteInterval = 750;

bool btnState1;
bool btnState2; 

void setup() {
  pinMode(white, OUTPUT);
  pinMode(red1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  btnState1 = digitalRead(btn1);
  btnState2 = digitalRead(btn2);

  if (btnState1) {
    while (btnState2 == LOW) {
      btnState2 = digitalRead(btn2);
      blinkRed(redInterval);
    }
    while (btnState2 == HIGH) {
      btnState2 = digitalRead(btn2);
      blinkRed(redInterval);
    }
  }
  else if (btnState2) {
    while (btnState1 == LOW) {
      btnState1 = digitalRead(btn1);
      blinkRed(redInterval);
    }
    while (btnState1 == HIGH) {
      btnState1 = digitalRead(btn1);
      blinkRed(redInterval);
    }
  }
  else {
    blinkWhite(whiteInterval);
  }
}

void blinkWhite(int interval) {
  digitalWrite(red1, LOW);
  digitalWrite(red2, LOW);
  digitalWrite(buzzer, LOW);
  static unsigned long int counter;
  static bool state;
  
  if (counter <= millis()) {
    if (state) {
      state = LOW;
    }
    else {
      state = HIGH;
    }
    counter = millis() + interval;
  }
  digitalWrite(white, state);
}

void blinkRed(int interval) {
  digitalWrite(white, LOW);
  static unsigned long int counter;
  static bool state;

  if (counter <= millis()) {
    if (state) {
      state = LOW;
      digitalWrite(red1, LOW);
      digitalWrite(red2, HIGH);
      analogWrite(buzzer, 0);
    }
    else {
      state = HIGH;
      digitalWrite(red1, HIGH);
      digitalWrite(red2, LOW);
      analogWrite(buzzer, 250);
    }
    counter = millis() + interval;
  }
}
