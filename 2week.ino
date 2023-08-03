/*
  제목 : 2week
  내용 : 조도센서가 빛을 받으면 LED ON&DC 모터 정방향 회전 & 조도센서를 손으로 가려 어둡게 만들면 LED OFF&DC 모터 역방향 회전
*/


int cds = A0; // 조도센서를 A0핀으로 선언
int led = 3; // LED를 3번핀으로 선언
int ENA = 5; // DC 모터 드라이버의 EnableA를 5번핀으로 선언
int IN12 = 9; // DC 모터 드라이버의 IN1&IN2를 9번핀으로 선언

// DC 모터의 회전 속도를 정의
// 디지털 핀으로 0~255 범위의 값으로 DC 모터의 속도를 제어
// 사용된 127이란 값은, 디지털 핀으로 출력 할 수 있는 최대값 255의 절반에 해당되므로, DC 모터가 5V 전류로 낼 수 있는 최대 회전 속도의 절반으로 해석
// 이는 디지털로 아날로그 신호를 보내는 펄스 폭 모듈레이션(PWM)에서 duty-cycle이 50%인 것으로 설정
int speed = 127;

void setup()
{
  Serial.begin(9600); // 조도센서의 동작 상태를 확인하기 위하여 시리얼 통신을 설정 (전송속도 9600bps)
  pinMode(led, OUTPUT); // LED핀을 OUTPUT으로 설정
  pinMode(ENA, OUTPUT); // IN1핀을 OUTPUT으로 설정
  pinMode(IN12, OUTPUT); // IN2핀을 OUTPUT으로 설정
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

    // 지정된 speed로 DC 모터 역방향으로 회전
    analogWrite(ENA, speed);
    digitalWrite(IN12, LOW);
   }

  // 조도센서로부터 측정된 밝기 값이 200보다 작다면(빛을 받는다면), 아래의 블록을 실행
  else 
  {
    digitalWrite(led, HIGH); // LED ON
    Serial.println("LED ON (cds < 200)"); // 시리얼 모니터에 LED ON (cds < 200) 출력

    // 지정된 speed로 DC 모터 정방향으로 회전
    analogWrite(ENA, speed);
    digitalWrite(IN12, HIGH);
  }
}