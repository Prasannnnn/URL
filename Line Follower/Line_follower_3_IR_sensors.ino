#define left 4
#define center 3
#define right 2

//motor one
#define ENA 12
#define IN1 8
#define IN2 9

//motor two
#define ENB 13
#define IN3 10
#define IN4 11

 // speed of this robot

void setup() {
  Serial.begin(9600);
  pinMode(left, INPUT);
  pinMode(center, INPUT);
  pinMode(right, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
  bool leftV = digitalRead(left);
  bool centerV = digitalRead(center);
  bool rightV = digitalRead(right);

  Serial.println(rightV);

  if (leftV == 0 && centerV == 1 && rightV == 0) {
    carforward();
    Serial.println("forward");
    delay(1000);
  } else if (leftV == 0 && centerV == 0 && rightV == 0) {
    carStop();
    Serial.println("Stop");
    delay(1000);
  } else if (leftV == 1 && centerV == 1 && rightV == 1) {
    carStop();
    Serial.println("Stop");
    delay(1000);
  } else if (leftV == 1 && centerV == 1 && rightV == 0) {
    carturnleft();
    Serial.println("sharp turn left");
    delay(1000);
  } else if (leftV == 0 && centerV == 1 && rightV == 1) {
    carturnright();
    Serial.println("sharp turn right");
    delay(1000);
  } else if (leftV == 1 && centerV == 0 && rightV == 0) {
    carturnleft();
    Serial.println("medium left");
    delay(1000);
  } else if (leftV == 0 && centerV == 0 && rightV == 1) {
    carturnright();
    Serial.println("medium right");
    delay(1000);
  }
}

void carforward() {
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void carturnleft() {
  analogWrite(ENA, 80);
  analogWrite(ENB, 80);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void carturnright() {
  analogWrite(ENA, 80);
  analogWrite(ENB, 80);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void carStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}