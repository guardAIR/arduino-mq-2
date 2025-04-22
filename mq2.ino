int sensorPin = A5;
float ppm;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int leitura = analogRead(sensorPin);
  if (leitura > 40){
    leitura = leitura - 40;
  }
  else {
    leitura = 0;
  }
  ppm = (leitura / 1023.0) * 100;
  Serial.println(ppm);

  delay(1000);
}
