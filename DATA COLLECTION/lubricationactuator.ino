// Arduino code to control an actuator (motor, solenoid, etc.) on/off with a push button

const int actuatorPin = 2;     // Define the digital output pin for the actuator
const int buttonPin = 3;       // Define the digital input pin for the button
int buttonState = 0;           // Variable to store the current state of the button
bool actuatorState = false;    // Variable to store the current state of the actuator

void setup() {
  pinMode(actuatorPin, OUTPUT); // Set the actuator pin as output
  pinMode(buttonPin, INPUT_PULLUP); // Set the button pin as input with internal pull-up resistor
}

void loop() {
  // Read the state of the button
  buttonState = digitalRead(buttonPin);

  // Check if the button is pressed (LOW)
  if (buttonState == LOW) {
    // Toggle the actuator state
    actuatorState = !actuatorState;

    // Set the actuator pin based on the actuator state
    digitalWrite(actuatorPin, actuatorState ? HIGH : LOW);

    // Wait for a short debounce time
    delay(50);
  }
}
