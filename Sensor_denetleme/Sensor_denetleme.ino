int a;

void setup() {
  Serial.begin(9600);
  pinMode(7, INPUT);
}

void loop() {
  a = digitalRead(7);
  Serial.println(a);
  delay(100);
}
