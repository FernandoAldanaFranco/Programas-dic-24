/**
 * Author: Omar Draidrya
 * Date: 2024/06/07
 * This code controls the forward and backward movement of a motor using an H-bridge.
 */
 
#define ledPin 7 // Pin for the LED
char state = 0; // Variable to store incoming data
 
void setup() {
  pinMode(ledPin, OUTPUT); // Set the LED pin as output
  digitalWrite(ledPin, LOW); // Initialize the LED state to OFF
  Serial.begin(9600); // Baudrate set to 9600 for consistency
}
 
void loop() {
  if (Serial.available() > 0) { // Check if data is coming from the serial port
    state = Serial.read(); // Read the data from the serial port
    if (state == '0') { // If the received data is '0'
      digitalWrite(ledPin, LOW); // Turn LED OFF
      Serial.println("LED: OFF"); // Send back to the phone
    } else if (state == '1') { // If the received data is '1'
      digitalWrite(ledPin, HIGH); // Turn LED ON
      Serial.println("LED: ON"); // Send back to the phone
    }
  }
}
