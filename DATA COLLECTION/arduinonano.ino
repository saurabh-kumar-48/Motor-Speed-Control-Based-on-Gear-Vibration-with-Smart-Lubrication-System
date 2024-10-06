// Arduino code for controlling 4-channel relay using MATLAB commands

const int relayPin1 = 2; // Define the pin numbers for each relay
const int relayPin2 = 3;
const int relayPin3 = 4;
const int relayPin4 = 5;

void setup() {
  Serial.begin(9600); // Initialize serial communication
  pinMode(relayPin1, OUTPUT); // Set the relay pins as outputs
  pinMode(relayPin2, OUTPUT);
  pinMode(relayPin3, OUTPUT);
  pinMode(relayPin4, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) { // Check if data is available to read
    char command = Serial.read(); // Read the incoming command from MATLAB
    if (command == '1') { // If command is '1', turn on relay 1
      digitalWrite(relayPin1, HIGH);
    } else if (command == '2') { // If command is '2', turn on relay 2
      digitalWrite(relayPin2, HIGH);
    } else if (command == '3') { // If command is '3', turn on relay 3
      digitalWrite(relayPin3, HIGH);
    } else if (command == '4') { // If command is '4', turn on relay 4
      digitalWrite(relayPin4, HIGH);
    } else if (command == '0') { // If command is '0', turn off all relays
      digitalWrite(relayPin1, LOW);
      digitalWrite(relayPin2, LOW);
      digitalWrite(relayPin3, LOW);
      digitalWrite(relayPin4, LOW);
    }
  }
}
