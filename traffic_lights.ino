int red = 8;
int yellow = 6;
int green = 4;
int buzzer = 10;
int button = 2;
int blinky = 500;
int newTime = 0;
int timer = 0;
bool Mode = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button), cycleStart, CHANGE);
  
}

void buzz(){
   for(int i=0; i<500; i++){
    digitalWrite(buzzer, HIGH);
    delay(3);
    digitalWrite(buzzer, LOW);
    delay(3);
  }
}

void cycleStart(){
  blinky = -1;
}

void loop() {
  // put your main code here, to run repeatedly:
  while(true){
    timer = millis();
    if( timer - newTime == blinky ){
      newTime = timer;
      Mode = !Mode;
      digitalWrite(red, Mode);
    }
    else if( blinky == -1){
      break;
    }
  }

  digitalWrite(red, HIGH);
  delay(12000);
  buzz();

  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  delay(12000);
  buzz();

  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  buzz();

  digitalWrite(yellow, LOW);
}
