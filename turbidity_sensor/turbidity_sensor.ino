const int turbidityPin = 34; // Turbidity sensor connected to GPIO34 (Analog ADC1_CH6)
const int numReadings = 1000; // Number of readings to average

long turbiditySum = 0; // Sum of turbidity values
float voltageSum = 0; // Sum of voltage values
int readingCount = 0; // Current reading count

void setup() {
  Serial.begin(115200);
}

void loop() {
  int turbidityValue = analogRead(turbidityPin);
  float voltage = turbidityValue * (5.0 / 1023.0);
  
  turbiditySum += turbidityValue;
  voltageSum += voltage;
  readingCount++;
  
  if (readingCount == numReadings) {
    // Calculate the averages
    float avgTurbidity = (float)turbiditySum / numReadings;
    float avgVoltage = voltageSum / numReadings;
    
    // Print the results
    Serial.print("Average Turbidity: ");
    Serial.println(avgTurbidity);
    Serial.print("Average Voltage: ");
    Serial.println(avgVoltage);
    
    // Reset the sums and reading count
    turbiditySum = 0;
    voltageSum = 0;
    readingCount = 0;
  }
  
  delay(10); // Delay between each reading (adjust as needed)
}