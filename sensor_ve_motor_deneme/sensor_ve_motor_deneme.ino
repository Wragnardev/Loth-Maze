// mavi robot

//2 sol arka
//3 sol
//4 ön
//5 sağ
//6 sağ arka

#define ma 14
#define ca 15
#define mb 16
#define cb 17
#define s 6

int u;

void setup()
{
  Serial.begin(9600);
  pinMode(ma, OUTPUT);
  pinMode(ca, OUTPUT);
  pinMode(mb, OUTPUT);
  pinMode(cb, OUTPUT);
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
    digitalWrite(mb, HIGH);
    digitalWrite(cb, HIGH);
  }
  else if (u == 1)
  {
    digitalWrite(ma, LOW);
    digitalWrite(ca, LOW);
    digitalWrite(mb, LOW);
    digitalWrite(cb, LOW);
  }
}
