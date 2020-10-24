const int switchPin = 10; //Digital Pin Controlling Mosfet Voltage

void setup() {
  pinMode(switchPin, OUTPUT);

}

void loop() {

  digitalWrite(switchPin, LOW);
  //Turns on LED because Mosfet open (Current goes through LED).
  //This is below the gate threshold voltage.
  delay(1000);
  //How long LED is on.

  digitalWrite(switchPin, HIGH);
  //Turns of LED because voltage going into Mosfet is 5V 
  //Connects resistor to ground (no current through LED)
  //This is above the gate threshold voltage (4V)
  delay(1000); 
  //How long LED is on

}
