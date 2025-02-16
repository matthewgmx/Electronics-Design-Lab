
volatile bool leftBlack = LOW;
volatile bool rightBlack = LOW;

const int pinLeftBlack = 20;
const int pinRightBlack = 21;
const int leftIndicator = 14;
const int rightIndicator = 13;

const int pinRightForward = 7;
const int pinRightBackward = 8;
const int pinRightPWM = 9;
const int pinLeftPWM = 10;
const int pinLeftForward = 11;
const int pinLeftBackward = 12;

void setup() {

  pinMode(pinRightForward, OUTPUT);
  pinMode(pinRightBackward, OUTPUT);
  pinMode(pinRightPWM, OUTPUT);
  pinMode(pinLeftForward, OUTPUT);
  pinMode(pinLeftBackward, OUTPUT);
  pinMode(pinLeftPWM, OUTPUT);

  digitalWrite(pinRightForward, HIGH);
  digitalWrite(pinRightBackward, LOW);
  analogWrite(pinRightPWM, 0);
  digitalWrite(pinLeftForward, HIGH);
  digitalWrite(pinLeftBackward, LOW);
  analogWrite(pinLeftPWM, 0);
  
  pinMode(pinLeftBlack, INPUT);
  attachInterrupt(digitalPinToInterrupt(pinLeftBlack), service20, RISING);
  pinMode(pinRightBlack, INPUT);
  attachInterrupt(digitalPinToInterrupt(pinRightBlack), service21, RISING);

  pinMode(14, OUTPUT);
  pinMode(13, OUTPUT);
  
  Serial.begin(9600);

}

void loop() {
  
  if(leftBlack == HIGH) {
    moveForward(5, 2);
    tone(leftIndicator, 2000);
    delay(750);
    noTone(leftIndicator);
    leftBlack = LOW;
  }
  else if(rightBlack == HIGH) {
    moveForward(2, 5);
    tone(rightIndicator, 2000);
    delay(750);
    noTone(rightIndicator);
    rightBlack = LOW;
  }
  else {
    moveForward(2, 2);
  }
}


void service20() {
  leftBlack = HIGH;
}

void service21() {
  rightBlack = HIGH;
}


void moveForward(int ls, int rs){

  analogWrite(pinLeftPWM, ls*51);
  analogWrite(pinRightPWM, rs*51);
  
}
