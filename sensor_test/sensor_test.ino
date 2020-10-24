const int switchPin = 10; //Digital Pin Controlling Mosfet Voltage

void setup() {
  pinMode(switchPin, OUTPUT);

}

void loop() {

  digitalWrite(switchPin, LOW);
  //Turns off LED because voltage going into Mosfet is 0V.
  //This is below the gate threshold voltage
  delay(1000);
  //How long LED is off

  digitalWrite(switchPin, HIGH);
  //Turns on LED because voltage going into Mosfet is 5V.
  //This is above the gate threshold voltage (4V)
  delay(1000); 
  //How long LED is on

}
