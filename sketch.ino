int gasSensor = A0;
int gasValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(gasSensor, INPUT);
}

void loop() {
  gasValue = analogRead(gasSensor);

  Serial.print("Air Quality Value: ");
  Serial.println(gasValue);

  if (gasValue > 400) {
    Serial.println("⚠️ Air Pollution Detected!");
  } else {
    Serial.println("Air Quality Normal");
  }

  delay(1000);
}