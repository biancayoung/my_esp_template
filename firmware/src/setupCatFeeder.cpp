//cat feeder code
#include "setupCatFeeder.h"
// Function to setup the cat feeder system
void setupFeeder() {
     // Initialize I2C communication
    Wire.begin(0x04);
    Wire.onReceive(receiveEvent); // Register an event handler for I2C receive events

    calibrateReservoir();
    loadFeedingSchedule();
    checkFeedingSchedule();
}

// Function to calibrate the reservoir
void calibrateReservoir() {
    Serial.println("Calibrating reservoir...");
}

// Function to load the feeding schedule
void loadFeedingSchedule() {
    Serial.println("Loading feeding schedule...");
}

// Function to check the feeding schedule
void checkFeedingSchedule() {
    Serial.println("Checking feeding schedule...");
}

// Function to check if the cat has already eaten
void checkIfAlreadyAte() {
    // Code to check if the cat has already eaten
    Serial.println("Checking if the cat has already eaten...");
    // need to add logic to load food if already ate before
    //if (/* result of checkIfAlreadyAte() */) {
    //    loadFood();
    //}
}

void mainLoop() {
    while (true) {
        // The ESP32 now waits passively for RFID data from the Tiny1614
        checkFeedingSchedule();
        // Add delay to avoid busy-waiting
        delay(1000);
    }
}


