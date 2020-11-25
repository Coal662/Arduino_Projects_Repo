bool crossing = true;
int crossingTime = 5000;


void setup()
{
  pinMode(2, OUTPUT); //crossing1 green
  pinMode(3, OUTPUT); //crossing1 yellow
  pinMode(4, OUTPUT); //crossing1 red
  pinMode(5, OUTPUT); //crossing2 green
  pinMode(6, OUTPUT); //crossing2 yellow
  pinMode(7, OUTPUT); //crossing2 red
  pinMode(8, OUTPUT); //pedestrian green
  pinMode(9, OUTPUT); //pedestrian red
  pinMode(10, INPUT_PULLUP); //button input
}

void loop()
{
  crossing = digitalRead(10);
  if (crossing == false) {
    crossingGo();
  }
  else {
    digitalWrite(2, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(9, HIGH);
  }
}

void crossingGo()
{
  delay(crossingTime / 2);
  digitalWrite(2, LOW);
  digitalWrite(5, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(6, HIGH);
  delay(crossingTime);
  digitalWrite(3, LOW);
  digitalWrite(6, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(7, HIGH);
  delay(crossingTime / 2);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  delay(crossingTime);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
  delay(300);
  digitalWrite(4, LOW);
  digitalWrite(7, LOW);
  for (int flashing = 0; flashing < 8; flashing++) {
    delay(300);
    digitalWrite(9, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    delay(300);
    digitalWrite(9, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(6, HIGH);
  }
  digitalWrite(3, LOW);
  digitalWrite(6, LOW);
  digitalWrite(2, HIGH);
  digitalWrite(5, HIGH);
  delay(crossingTime);
  
}
