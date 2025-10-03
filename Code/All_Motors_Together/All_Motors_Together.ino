#include <ESP32Servo.h>

int PWM_1 = 13;
int DIR_1 = 12;

int PWM_2 = 32;
int DIR_2 = 33;

int button_1 = 5;
int button_2 = 23;
int button_3 = 22;

int led_1 = 21;
int led_2 = 19;
int led_3 = 18;

Servo myServo;
int servo_pin = 25;

void setup() {
  Serial.begin(115200);

  pinMode(PWM_1, OUTPUT);
  pinMode(DIR_1, OUTPUT);

  pinMode(PWM_2, OUTPUT);
  pinMode(DIR_2, OUTPUT);

  pinMode(button_1, INPUT);
  pinMode(button_2, INPUT);
  pinMode(button_3, INPUT);

  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);

  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  myServo.setPeriodHertz(50);          // Standard servo refresh rate
  myServo.attach(servo_pin, 1000, 2000); // Attach servo to pin with pulse width range

  // Start motors in opposite directions (they will keep running)
  digitalWrite(DIR_1, HIGH);
  analogWrite(PWM_1, 255);   // Full speed

  digitalWrite(DIR_2, LOW);
  analogWrite(PWM_2, 255);   // Full speed
}

void loop() {
  // Servo oscillation between 0° and 90°
  myServo.write(0);
  delay(3000);   // Wait 3s at 0°

  myServo.write(90);
  delay(3000);   // Wait 3s at 90°
}
