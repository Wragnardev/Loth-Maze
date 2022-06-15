#define wbSensor 8 //siyah beyaz sensörü

int a;

void setup()
{
  Serial.begin(9600);
  pinMode(wbSensor, OUTPUT);
}

void loop()
{
  a = digitalRead(wbSensor);
  Serial.println(a);
  delay(100);
}
