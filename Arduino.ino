#include <Servo.h>

#define THRESHOLD 150 // Threshold to determine hand state
#define EMGPIN 3 // Analog pin for Muscle Sensor
#define LITTLEPIN 2 // Digital pin for Little servo
#define RINGPIN 3 // Digital pin for Ring servo
#define MIDDLEPIN 4 // Digital pin for Middle servo
#define INDEXPIN 5 // Digital pin for Index servo
#define THUMBPIN 6 // Digital pin for Thumb servo

// Constants for finger identification
#define LITTLE 1 
#define RING   2
#define MIDDLE 3
#define INDEX  4
#define THUMB  5

Servo servoLittleFinger; // Define servo for Little finger
Servo servoRingFinger; // Define servo for Ring finger
Servo servoMiddleFinger; // Define servo for Middle finger
Servo servoIndexFinger; // Define servo for Index finger
Servo servoThumbFinger; // Define servo for Thumb finger

int finger;

// Functions to open and close the hand
void openhand() {
    for(finger = 1; finger < 6; finger++) {
        openFinger(finger);
    }
}

void closehand() {
    for(finger = 1; finger < 6; finger++) {
        closeFinger(finger);
    }
}

// Function to open a specific finger
void openFinger(int finger) {
    if(finger == LITTLE) {
        servoLittleFinger.write(0); // Open Little finger
    } else if(finger == RING) {
        servoRingFinger.write(170); // Open Ring finger
    } else if(finger == MIDDLE) {
        servoMiddleFinger.write(170); // Open Middle finger
    } else if(finger == INDEX) {
        servoIndexFinger.write(170); // Open Index finger
    } else if(finger == THUMB) {
        servoThumbFinger.write(0); // Open Thumb finger
    }
}

// Function to close a specific finger
void closeFinger(int finger) {
    if(finger == LITTLE) {
        servoLittleFinger.write(170); // Close Little finger
    } else if(finger == RING) {
        servoRingFinger.write(0); // Close Ring finger
    } else if(finger == MIDDLE) {
        servoMiddleFinger.write(0); // Close Middle finger
    } else if(finger == INDEX) {
        servoIndexFinger.write(0); // Close Index finger
    } else if(finger == THUMB) {
        servoThumbFinger.write(170); // Close Thumb finger
    }
}

void setup() {
    Serial.begin(115200); // Initialize serial communication
    servoLittleFinger.attach(LITTLEPIN); // Attach Little finger servo
    servoRingFinger.attach(RINGPIN); // Attach Ring finger servo
    servoMiddleFinger.attach(MIDDLEPIN); // Attach Middle finger servo
    servoIndexFinger.attach(INDEXPIN); // Attach Index finger servo
    servoThumbFinger.attach(THUMBPIN); // Attach Thumb finger servo
}

void loop() {
    int value = analogRead(EMGPIN); // Read muscle sensor value
    if(value > THRESHOLD) {
        closehand(); // Close hand if threshold is exceeded
    } else {
        openhand(); // Open hand otherwise
    }
    Serial.println(value); // Print sensor value for monitoring
}
