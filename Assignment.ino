const int blinkCount_hot = 50; // delay count(10ms * 50 = 500ms)
const int blinkCount_cold = 25; // delay count(10ms * 25 = 250ms)
int counter = 0; // Counter to keep track of blink cycles

void setup() {
  pinMode(A0, INPUT); // Temperature sensor pin
  pinMode(13, OUTPUT); // LED pin
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  
  int sensor = analogRead(A0); // Read analog value from the sensor
  float voltage = (sensor / 1024.0) * 5.0;  // Convert sensor value to voltage
  float tempC = (voltage - 0.5) * 100;  // Convert voltage to temperature
  
  // Check if the temperature is above 30 degrees Celsius
  if (tempC > 30) {
    blink_hot(counter); // Call function for blinking LEDs for high temperature
    counter = (counter + 1) % (blinkCount_hot * 2); // Increment counter for high temperature blinks
  } else {
    blink_cold(counter); // Call function for blinking LEDs for low temperature
    counter = (counter + 1) % (blinkCount_cold * 2); // Increment counter for low temperature blinks
  }
}

void blink_hot(int count) {
  // Check if the count is within the specified number of blinks for high temperature
  if (count < blinkCount_hot) {
    digitalWrite(13, HIGH); // Led ON
    Serial.println(1);
  } else {
    digitalWrite(13, LOW); //Led OFF
    Serial.println(0);
  }
}

void blink_cold(int count) {
  // Check if the count is within the specified number of blinks for low temperature
  if (count < blinkCount_cold) {
    digitalWrite(13, HIGH); // Led ON
    Serial.println(1);
  } else {
    digitalWrite(13, LOW); // Led OFF
    Serial.println(0);
  }
}
