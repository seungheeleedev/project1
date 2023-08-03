/*
  제목 : 2week_DC motor driver
  내용 : 모터 드라이버를 사용하여 DC 모터 정방향 회전
*/


int ENA = 5; // DC 모터 드라이버의 EnableA를 5번핀으로 선언
int IN12 = 9; // DC 모터 드라이버의 IN1&IN2를 9번핀으로 선언

// DC 모터의 회전 속도를 정의
// 디지털 핀으로 0~255 범위의 값으로 DC 모터의 속도를 제어
// 사용된 127이란 값은, 디지털 핀으로 출력 할 수 있는 최대값 255의 절반에 해당되므로, DC 모터가 5V 전류로 낼 수 있는 최대 회전 속도의 절반으로 해석
// 이는 디지털로 아날로그 신호를 보내는 펄스 폭 모듈레이션(PWM)에서 duty-cycle이 50%인 것으로 설정
int speed = 127;

void setup() 
{
  pinMode(ENA, OUTPUT); // EnableA핀을 OUTPUT으로 설정
  pinMode(IN12, OUTPUT); // IN1&IN2핀을 OUTPUT으로 설정
}
 
void loop() 
{
  // 지정된 speed로 DC 모터 정방향으로 회전
  analogWrite(ENA, speed);
  digitalWrite(IN12, HIGH);
}