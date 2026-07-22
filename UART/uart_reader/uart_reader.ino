HardwareSerial STM32Serial(2);

void setup() {
  Serial.begin(115200);
  STM32Serial.begin(115200, SERIAL_8N1, 16, 17);
}

void loop() {
  while (STM32Serial.available()) {
    Serial.write(STM32Serial.read());
  }
  delay(1000);
}