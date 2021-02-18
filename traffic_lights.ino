int red = 8;
int yellow = 6;
int green = 4;
int buzzer = 10;
int button = 2;
int flash = 1;

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
  flash = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  while(flash == 1){
    digitalWrite(red, HIGH);
     delay(500);
    digitalWrite(red, LOW);
    delay(500);
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
  flash = 1;
}
