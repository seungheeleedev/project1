/*
  제목 : 1week_cds sensor
  내용 : 조도센서가 빛을 받으면 LED ON & 조도센서를 손으로 가려 어둡게 만들면 LED OFF
*/
 

int cds = A0; // 조도센서를 A0핀으로 선언
int led = 3; // LED를 3번핀으로 선언
 
void setup() 
{
  Serial.begin(9600); // 조도센서의 동작 상태를 확인하기 위하여 시리얼 통신을 설정 (전송속도 9600bps)
  pinMode(led, OUTPUT); // LED핀을 OUTPUT으로 설정
}
 
void loop() 
{
  int cdsValue = analogRead(cds); // 조도센서로부터 측정된 밝기 값을 읽어 cdsValue라는 변수에 저장
 
  // 측정된 밝기 값을 시리얼 모니터에 출력
  Serial.print("cds =  ");
  Serial.println(cdsValue);
 
  // 조도센서로부터 측정된 밝기 값이 200보다 크다면(어둡다면), 아래의 블록을 실행
  if (cdsValue > 200) 
  {
    digitalWrite(led, LOW); // LED OFF
    Serial.println("LED OFF (cds > 200)"); // 시리얼 모니터에 LED OFF (cds > 200) 출력
  }
 
  // 조도센서로부터 측정된 밝기 값이 200보다 작다면(빛을 받는다면), 아래의 블록을 실행
  else 
  {
    digitalWrite(led, HIGH); // LED ON
    Serial.println("LED ON (cds < 200)"); // 시리얼 모니터에 LED ON (cds < 200) 출력
  }

  delay(200); // 200ms 지연
}