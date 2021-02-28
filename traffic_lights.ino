//initializing pins and values
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
  
  //setting up pins and configuring them as inputs or outputs
  //also setting parameters of interrupt function
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button), cycleStart, CHANGE);
  
}

void buzz(){
  
  //buzz function buzzes buzzer for 3 seconds when called
   for(int i=0; i<500; i++){
    digitalWrite(buzzer, HIGH);
    delay(3);
    digitalWrite(buzzer, LOW);
    delay(3);
  }
}

void cycleStart(){
  
  //cycleStart called at buttonPush and acts as a flag to exit while loop inside of loop() when called
  blinky = -1;
}

void loop() {
  // main loop function
  
  while(true){
    
    // timer is set to millis() which returns the amount of time that the program has been running
    // millis() uses internal timer TIMER0 to track the milliseconds that the program has been running
    timer = millis();
    
    // if statements check to see if 500 milliseconds have passed or if ISR was called
    if( timer - newTime == blinky ){
      
      //when condition is met, newTime is set to Timer and the difference is checked to
      //determine when 500 milliseconds has passed
      newTime = timer;
      
      // bool type variable Mode is set to its other state ( 1 or 0 )
      Mode = !Mode;
      
      // red LED is set to its other state (on or off)
      digitalWrite(red, Mode);
      
    }
    
    // if ISR is called and flag is returned then program exits loop
    else if( blinky == -1){
      
      break;
      
    }
    
  }
  
  // rest of traffic light program toggles through red, yellow, and green LEDS for set times
  // and buzzes for 3 seconds before transitioning to the next state
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
