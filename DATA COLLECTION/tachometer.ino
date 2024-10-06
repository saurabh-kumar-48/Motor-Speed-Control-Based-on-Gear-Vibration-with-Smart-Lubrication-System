// Arduino code for measuring RPM using a tachometer sensor

const int sensorPin = 2; // Define the input pin for the tachometer sensor
volatile int count = 0; // Initialize a counter variable

unsigned long previousMillis = 0; // Initialize variables for timing
const long interval = 1000; // Interval for calculating RPM (in milliseconds)

void setup() {
  Serial.begin(9600); // Initialize serial communication
  pinMode(sensorPin, INPUT_PULLUP); // Set the sensor pin as input with pull-up resistor
  attachInterrupt(digitalPinToInterrupt(sensorPin), countPulses, RISING); // Attach interrupt for counting pulses
}

void loop() {
  unsigned long currentMillis = millis(); // Get the current time
  
  if (currentMillis - previousMillis >= interval) { // Check if it's time to calculate RPM
    // Calculate RPM
    float rpm = (count * 60.0) / (interval / 1000.0);
    
    // Print RPM to serial monitor
    Serial.print("RPM: ");
    Serial.println(rpm);
    
    // Reset count and update timing
    count = 0;
    previousMillis = currentMillis;
  }
}

void countPulses() {
  // This function is called every time a pulse is detected
  count++; // Increment the pulse count
}
