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
