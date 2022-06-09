#define ma 14
#define ca 15
#define mb 16
#define cb 17

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
