// 조도센서를 A0핀으로 선언하고 led핀을 3번핀으로 선언하고 DC모터를 5번 핀으로 설정합니다.
int cds = A0;
int led = 3;
int motor = 5;

int speed = 127;

void setup() 
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() 
{
  int cdsValue = analogRead(cds);
 
  Serial.print("cds =  ");
  Serial.println(cdsValue);
  
  if (cdsValue > 200) 
  {
    digitalWrite(led, LOW);
    Serial.println("LED OFF (cds > 200)");
    analogWrite(motor, 0);
  }

  else 
  {
    digitalWrite(led, HIGH);
    Serial.println("LED ON (cds < 200)");
    analogWrite(motor, speed);
  }
}
