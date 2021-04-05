//There are now two LEDs being driven by 1 gate
//Each LED variable is the input at a MOSFET gate.
//Pins may not correspond to actual color (needs to be double checked).

//Tasks still required: Need a PWM range to start lights and code to drive servos
//If time permits, code lights to signal "Go Gators" in morse code.

const byte whiteLED = 12; 
const byte blueLED = 11;
const byte redLED = 10;
const byte pwmIN = 3;
float durationHI = 0;

void setup() {
  //Serial.begin(9600);
  pinMode(whiteLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  digitalWrite(whiteLED, LOW);
  digitalWrite(blueLED, LOW);
  digitalWrite(redLED, LOW);
}

void loop() {

  /*
   * Uncomment if you want code to run when there is a pwm signal
  durationHI = pulseIn(pwmIN, HIGH);
  Serial.println(durationHI);
  //900 to 1100 microsecond range is centered around 1ms which is 50% duty cycle for nano.
  //Change range for code to run according to signal output from carrier board in the plane.
  if ((durationHI < 1100) && (durationHI > 900)) { 
    
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
  */

  //Tests if each gate of the mosfet is working
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
