#define ma 8
#define ca 9
#define s 2

int u;

void setup()
{
  Serial.begin(9600);
  pinMode(ma, OUTPUT);
  pinMode(ca, OUTPUT);
  pinMode(s, INPUT);
}

void loop()
{
  u = digitalRead(s);
  Serial.println(u);
  if (u == 0)
  {
    digitalWrite(ma, HIGH);
    digitalWrite(ca, HIGH);
  }
  else if (u == 1)
  {
    digitalWrite(ma, LOW);
    digitalWrite(ca, LOW);
  }
}
n
