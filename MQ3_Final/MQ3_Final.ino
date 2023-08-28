#define sensorDigital 2
#define buzzer 9
#define sensorAnalog A1
#define pushButton 5
#define additionalLED 6

void setup() {
  pinMode(sensorDigital, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(pushButton, INPUT_PULLUP);
  pinMode(additionalLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  bool digital = digitalRead(sensorDigital);
  int analog = analogRead(sensorAnalog);
  bool buttonState = digitalRead(pushButton);
  
  Serial.print("Analog value: ");
  Serial.print(analog);
  Serial.print("\t");
  Serial.print("Digital value: ");
  Serial.print(digital);
  Serial.print("\t");
  Serial.print("Button state: ");
  Serial.println(buttonState);
  
  if (digital == 0) {
    digitalWrite(buzzer, HIGH);
    digitalWrite(additionalLED, LOW);
  } else {
    if (buttonState == HIGH) {
      digitalWrite(buzzer, LOW);
      digitalWrite(additionalLED, LOW);
    } else {
      digitalWrite(buzzer, LOW);
      digitalWrite(additionalLED, HIGH);
    }
  }
}
