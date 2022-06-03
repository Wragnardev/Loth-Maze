#define ma 8
#define ca 9
#define mb 10
#define cb 11

void setup()
{
  pinMode(ma, OUTPUT);
  pinMode(ca, OUTPUT);
  pinMode(mb, OUTPUT);
  pinMode(cb, OUTPUT);
}

void loop()
{
  digitalWrite(ma, HIGH);
  digitalWrite(ca, HIGH);
  digitalWrite(mb, HIGH);
  digitalWrite(cb, HIGH);
}
