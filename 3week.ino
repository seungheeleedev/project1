/*
  제목 : 3week
  내용 : 최종본
*/


int cds1 = A0; // 조도센서1을 A0핀으로 선언
int led1 = 3; // LED1을 3번핀으로 선언
int ENA = 5; // DC 모터 드라이버의 EnableA를 5번핀으로 선언
int IN12 = 9; // DC 모터 드라이버의 IN1&IN2를 9번핀으로 선언
int cds2 = A4; // 조도센서2를 A4핀으로 선언
int led2 = A5; // LED2를 A5핀으로 선언
int ENB = 10; // DC 모터 드라이버의 EnableB를 10번핀으로 선언
int IN34 = 11; // DC 모터 드라이버의 IN3&IN4를 11번핀으로 선언

// DC 모터의 회전 속도를 정의
// 디지털 핀으로 0~255 범위의 값으로 DC 모터의 속도를 제어
// 사용된 127이란 값은, 디지털 핀으로 출력 할 수 있는 최대값 255의 절반에 해당되므로, DC 모터가 5V 전류로 낼 수 있는 최대 회전 속도의 절반으로 해석
// 이는 디지털로 아날로그 신호를 보내는 펄스 폭 모듈레이션(PWM)에서 duty-cycle이 50%인 것으로 설정
int speed = 127;

void setup()
{
  Serial.begin(9600); // 조도센서의 동작 상태를 확인하기 위하여 시리얼 통신을 설정 (전송속도 9600bps)
  pinMode(led1, OUTPUT); // LED1핀을 OUTPUT으로 설정
  pinMode(ENA, OUTPUT); // EnableA를 OUTPUT으로 설정
  pinMode(IN12, OUTPUT); // IN2핀을 OUTPUT으로 설정
  pinMode(led2, OUTPUT); // LED2핀을 OUTPUT으로 설정
  pinMode(ENB, OUTPUT); // IN3핀을 OUTPUT으로 설정
  pinMode(IN34, OUTPUT); // IN4핀을 OUTPUT으로 설정
}

void loop()
{
  int cdsValue1 = analogRead(cds1); // 조도센서1으로부터 측정된 밝기 값을 읽어 cdsValue1이라는 변수에 저장
  int cdsValue2 = analogRead(cds2); // 조도센서2로부터 측정된 밝기 값을 읽어 cdsValue2라는 변수에 저장

  // 측정된 밝기 값을 각각 시리얼 모니터에 출력
  Serial.print("cds1 = ");
  Serial.print(cdsValue1);
  Serial.print(", cds2 = ");
  Serial.println(cdsValue2);

  // 조도센서로부터 측정된 밝기 값이 조도센서1보다 조도센서2가 크다면, 아래의 블록을 실행
  if (cdsValue1 < cdsValue2)
  {
    digitalWrite(led1, HIGH); // LED1 ON
    digitalWrite(led2, LOW); // LED2 OFF
    Serial.println("LED1 ON (cds1 < cds2)"); // 시리얼 모니터에 LED1 ON (cds1 < cds2) 출력

    // 지정된 speed로 DC 모터 정방향으로 회전
    analogWrite(ENA, speed);
    digitalWrite(IN12, HIGH);
    analogWrite(ENB, speed);
    digitalWrite(IN34, LOW);
   }

  // 조도센서로부터 측정된 밝기 값이 조도센서2보다 조도센서1이 크다면, 아래의 블록을 실행
  else
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    Serial.println("LED2 ON (cds1 > cds2)");

    // 지정된 speed로 DC 모터 역방향으로 회전
    analogWrite(ENA, speed);
    digitalWrite(IN12, LOW);
    analogWrite(ENB, speed);
    digitalWrite(IN34, HIGH);
  }
}