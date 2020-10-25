const int GreenLEDPin = 10;
const int RedLEDPin = 11;

void setup() {
  pinMode(GreenLEDPin, OUTPUT);
  pinMode(RedLEDPin, OUTPUT);
  digitalWrite(RedLEDPin, LOW);
  digitalWrite(GreenLEDPin, LOW);

}

void loop() {
  digitalWrite(RedLEDPin, HIGH);//Red LED turns on.
  delay(200);
  digitalWrite(RedLEDPin, LOW); //Red LED turns off.
  delay(800);

  digitalWrite(GreenLEDPin, HIGH);//Green LED turns on.
  delay(200);
  digitalWrite(GreenLEDPin, LOW);//Green LED turns off.
  delay(800);

}
