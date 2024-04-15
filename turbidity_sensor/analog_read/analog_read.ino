const int turbidityPin = 34; // Turbidity sensor connected to GPIO34 (Analog ADC1_CH6)

void setup() {
  Serial.begin(115200);
}

void loop() {
  float sum_turbidity = 0;
  float sum_voltage = 0;

  for (int sample_number = 0; sample_number < 1000; sample_number++) {
    int turbidityValue = analogRead(turbidityPin);
    float voltage = turbidityValue * (5.0 / 1023.0);

    sum_turbidity += turbidityValue;
    sum_voltage += voltage;

    delay(10);
  }

  float average_turbidity = sum_turbidity / 1000;
  float average_voltage = sum_voltage / 1000;
    
  String voltageCategory; 
  if (average_voltage >= 20) {
    voltageCategory = "AIR JERNIH";
  } else if (average_voltage >= 14) {
    voltageCategory = "AIR AGAK KERUH";
  } else if (average_voltage >= 6) {
    voltageCategory = "AIR SETENGAH KERUH";
  } else {
    voltageCategory = "AIR SANGAT KERUH";
  }
  
  Serial.print("Average Analog Reading: ");
  Serial.print(average_turbidity);
  Serial.print("\tAverage Voltage: ");
  Serial.println(average_voltage);
  Serial.print("Category: ");
  Serial.println(voltageCategory);
}