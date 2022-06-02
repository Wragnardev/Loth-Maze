#define ma 8
#define ca 9

void setup()
{
  pinMode(ma, OUTPUT);
  pinMode(ca, OUTPUT);
}

void loop()
{
  digitalWrite(ma, HIGH);
  digitalWrite(ca, HIGH);
}
