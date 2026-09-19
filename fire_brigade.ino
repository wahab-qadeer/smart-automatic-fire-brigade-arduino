#define enA 10
#define in1 9
#define in2 8

// Pump pins
#define in3 7
#define in4 6
#define enB 5

#define flame A0
#define buzzer 4

int Speed = 180;
int sensorValue;

void setup() {

  Serial.begin(9600);

  pinMode(flame, INPUT);

  // Motor pins
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  // Pump pins
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);

  // Buzzer
  pinMode(buzzer, OUTPUT);

  digitalWrite(buzzer, HIGH);

  // Motor speed
  analogWrite(enA, Speed);

  // Pump full speed
  analogWrite(enB, 255);

  Stop();
  PumpOff();

  delay(1000);
}

void loop() {

  sensorValue = analogRead(flame);

  Serial.print("Flame Value: ");
  Serial.println(sensorValue);

  // FIRE DETECTED
  if(sensorValue < 300) {

    Forward();

    PumpOn();

    digitalWrite(buzzer, LOW);
  }
  else {

    Stop();

    PumpOff();

    digitalWrite(buzzer, HIGH);
  }

  delay(50);
}

// ================= MOTOR =================

void Forward() {

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void Stop() {

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

// ================= PUMP =================

void PumpOn() {

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void PumpOff() {

  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
