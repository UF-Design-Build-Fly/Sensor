const byte whiteLED = 12;
const byte blueLED = 11;
const byte redLED = 10;
const byte pwmIN = 3;
float durationHI = 0;

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
 
uint16_t t = 330;
uint16_t dashHI = t;
uint16_t dashLO = 0.25 * t;
uint16_t dotHI = 0.363 * t;
uint16_t dotLO = 0.348 * t; 
uint16_t characterSpace = 1250;
uint16_t wordSpace = 3000;


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
    
    digitalWrite(whiteLED, HIGH);
    delay(1000);
    digitalWrite(whiteLED, LOW);
    delay(1000);

    digitalWrite(blueLED, HIGH);
    delay(1000);
    digitalWrite(blueLED, LOW);
    delay(1000);

    digitalWrite(redLED, HIGH);
    delay(1000);
    digitalWrite(redLED, LOW);
    delay(1000);
 }
}

void letter_G () { // - - .
  digitalWrite(whiteLED, HIGH); // -
  delay(dashHI);
  digitalWrite(whiteLED, LOW);
  delay(dashLO);
  digitalWrite(blueLED, HIGH); // -
  delay(dashHI);
  digitalWrite(blueLED, LOW);
  delay(dashLO);
  digitalWrite(redLED, HIGH); // .
  delay(dotHI);
  digitalWrite(redLED, LOW);
  delay(dotLO);
}

void letter_A () { // . -
  
}

void letter_T () { // -
  
}

void letter_O () { // - - - 
  
}

void letter_R () { // . - .
  
}

void letter_S () { // . . .
  
}

void letter_exclamation () { // - . - . - -
  
}

void character_space () { //Time in between each character
  delay(characterSpace);
}

void word_space () {
  delay(wordSpace);
}
