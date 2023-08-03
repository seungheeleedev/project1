 /*
 제목 : 1week_DC motor
 내용 : 스위치를 누를 때마다 DC 모터 회전
 */


int motor = 5; // DC 모터를 5번핀으로 선언
int sw = 6; // 스위치를 6번핀으로 선언
 
// DC 모터의 회전 속도를 정의
// 디지털 핀으로 0~255 범위의 값으로 DC 모터의 속도를 제어
// 사용된 127이란 값은, 디지털 핀으로 출력 할 수 있는 최대값 255의 절반에 해당되므로, DC 모터가 5V 전류로 낼 수 있는 최대 회전 속도의 절반으로 해석
// 이는 디지털로 아날로그 신호를 보내는 펄스 폭 모듈레이션(PWM)에서 duty-cycle이 50%인 것으로 설정
int speed = 127;
 
void setup() 
{
    pinMode(sw, INPUT_PULLUP); // 스위치가 연결되는 핀은 PULL-UP 회로로 사용
}

void loop() 
{
    // 스위치가 닫혀있는 상태(눌린 상태) 이므로, 아래의 블록을 실행
    if (digitalRead(sw) == LOW) 
    {
        analogWrite(motor, speed); // 지정된 speed로 DC 모터 회전
    }
 
    // 스위치가 연결된 핀의 로직레벨이 HIGH라면,
    // 스위치가 열려있는 상태(누르지 않은 상태) 이므로, 아래의 블록을 실행
    else 
    {
        analogWrite(motor, 0); // duty-cycle을 0%로 설정하여 DC 모터 STOP
    }
}