const byte whiteLED = 12;
const byte blueLED = 11;
const byte redLED = 10;
const byte pwmIN = 3;
float durationHI = 0;

//Letter speed multiplier (default setting: A = 1).
//Increasing A will increase the time dashes and dots take.
//Decreasing A will decrease the time dashes and dots take.
float A = 0.75;

//Time between character and words multiplier (default setting: B = 1).
//Increasing A will increase the time/space between words and letters.
//Decreasing A will decrease the time/space between words and letters.
float B = 0.5;

/*
 * Morse Code settings: https://morsecode.world/international/translator.html
 * Input: Go Gators!
 * Output: --. --- / --. .- - --- .-. ... -.-.--
 * 10 character speed
 * 5 Farnsworth speed
 * Light option: ON
 */
//Time proportions was determined using a light sensor (5V -> 16-33k photoresistor -> 10k resistor -> GND)
//Voltage measured across photoresistor for peaks when light changed resistance of photoresistor.
uint16_t t1 = A*330; //Time (milliseconds) dash is HIGH: 330 is our default speed
uint16_t t2 = B*1250; //Time for character space: 1250 is our default speed
uint16_t restart = 1000; //Time in between end and beginning of pharse. Going from ! to G in "Go Gators!".

uint16_t dashHI = t1;
uint16_t dashLO = 0.25 * t1;
uint16_t dotHI = 0.363 * t1;
uint16_t dotLO = 0.348 * t1; 
uint16_t characterSpace = t2;
uint16_t wordSpace = 1.4 * t2;


void setup() {
 
  pinMode(whiteLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  digitalWrite(whiteLED, LOW);
  digitalWrite(blueLED, LOW);
  digitalWrite(redLED, LOW);
}

void loop() {
  
  //Change range for code to run according to signal output from carrier board in the plane.
  durationHI = pulseIn(pwmIN, HIGH);
  if ((durationHI < 1250 && durationHI > 750)) { 
    letter_G();
    letter_O();
    delay(wordSpace);
    letter_G();
    letter_A();
    letter_T();
    letter_O();
    letter_R();
    letter_S();
    exclamation();
    delay(restart);
 }
 
 //Used for testing light outputs. 
 //Comment out when flying.
 letter_G();
 letter_O();
 delay(wordSpace);
 letter_G();
 letter_A();
 letter_T();
 letter_O();
 letter_R();
 letter_S();
 exclamation();
 delay(restart);
}

void letter_G () { // - - .
  dash('w');
  dash('b');
  dot('r');
  character_space();
}
void letter_A () { // . -
  dot('w');
  dash('b');
  character_space();
}
void letter_T () { // -
  dash('r');
  character_space();
}
void letter_O () { // - - - 
  dash('w');
  dash('b');
  dash('r');
  character_space();
}
void letter_R () { // . - .
  dot('w');
  dash('b');
  dot('r');
  character_space();
}
void letter_S () { // . . .
  dot('w');
  dot('b');
  dot('r');
  character_space();
}
void exclamation () { // - . - . - -
  dash('w');
  dot('b');
  dash('r');
  dot('w');
  dash('b');
  dash('r');
}
void dash (char color) { // -
  if (color == 'w') {
    digitalWrite(whiteLED, HIGH);
    delay(dashHI);
    digitalWrite(whiteLED, LOW);
    delay(dashLO);
  }
  else if (color == 'b') {
    digitalWrite(blueLED, HIGH); // -
    delay(dashHI);
    digitalWrite(blueLED, LOW);
    delay(dashLO);
  }
  else if (color == 'r') {
    digitalWrite(redLED, HIGH); // .
    delay(dashHI);
    digitalWrite(redLED, LOW);
    delay(dashLO);
  }
  else {} //Nothing
}
void dot (char color) { // .
  if (color == 'w') {
    digitalWrite(whiteLED, HIGH);
    delay(dotHI);
    digitalWrite(whiteLED, LOW);
    delay(dotLO);
  }
  else if (color == 'b') {
    digitalWrite(blueLED, HIGH);
    delay(dotHI);
    digitalWrite(blueLED, LOW);
    delay(dotLO);
  }
  else if (color == 'r') {
    digitalWrite(redLED, HIGH);
    delay(dotHI);
    digitalWrite(redLED, LOW);
    delay(dotLO);
  }
  else {} //Nothing
}
void character_space () {
  delay(characterSpace);
}
