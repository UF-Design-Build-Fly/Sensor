const int GreenLEDPin = 10; //define which control signal is connected to a specific LED
const int RedLEDPin = 11;
const int BlueLEDPin = 12;

void setup() {
  pinMode(GreenLEDPin, OUTPUT);
  pinMode(RedLEDPin, OUTPUT);
  pinMode(BlueLEDPin, OUTPUT);
  digitalWrite(RedLEDPin, LOW); //The LED's are wired 'active high', meaning a 'high' will turn the LED on
  digitalWrite(GreenLEDPin, LOW);
  digitalWrite(BlueLEDPin, LOW);

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

  digitalWrite(GreenLEDPin, HIGH);//Blue LED turns on.
  delay(200);
  digitalWrite(GreenLEDPin, LOW);//Blue LED turns off.
  delay(800);

}
