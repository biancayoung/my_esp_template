
# Automated Cat Feeder

This repository contains the code and documentation for an automated cat feeder. The feeder is designed to dispense food at scheduled times and when the cat is detected at the feeding portal. It uses various hardware components controlled by an ESP32 microcontroller.

## Table of Contents

- [Hardware Components](#hardware-components)
- [Phases and Steps](#phases-and-steps)
- [Function List](#function-list)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Hardware Components

1. **Main body (Reservoir and Feed Screw)**
   - **ESP32**: Central processor that communicates with modules and controls the feeding mechanism. Comunicates via I2C to modules.
   - **Stepper Motor 1**: Controls rotation of the reservoir.
   - **Stepper Motor 2**: Controls rotation of the feed screw.
   - **End stop**: homes steppper motor 1, indicates location. 

2. **Module/Food Bay**
   - **RFID Reader**: Detects the cat's presence.
   - **Servo Motor**: Opens the door.
   - **Tiny1614 IC**: Manages local operations and communicates via I2C with the main ESP32.

## Phases and Steps

### Phase 1: Daily Initialization and Calibration

**Event**: Start of Day  
**Trigger**: ESP32 starts the day (e.g., at midnight).  
**Actions**:  
1. **Calibrate the reservoir position**:
   - Move the reservoir towards the left until it hits the endstop switch.
   - Set this position as position 0.
   - Subsequent positions will be calculated from this point.
2. **Scheduled Feeding Check**:
   - At 9 a.m., check if it's time to feed the cat.
   - At 6 p.m., check if it's time to feed the cat.
   - Load food from the reservoir to the feed module.

### Phase 2: Cat Detection and Door Operation

**Event**: Cat Arrives at the Portal  
**Trigger**: RFID reader in the module detects the cat's tag.  
**Actions**:  
1. Tiny1614 sends a signal via I2C to the ESP32 indicating a cat is at the door.
2. **ESP32 Response**:
   - Receives I2C signal from the module.
   - Validates the cat's information and determines the required feeding schedule.
   - Logs the cat's entry time and RFID tag information.
   - Sends a command via I2C to the Tiny1614 to open the door.
   - Tiny1614 activates the servo to open the door.

### Phase 3: Feeding Mechanism

**Actions**:  
1. **Reservoir and Feed Screw Operation**:
   - ESP32 calculates the required amount of food.
   - Sends signals to Stepper Motor 1 to rotate the reservoir to the correct position.
   - Sends signals to Stepper Motor 2 to rotate the feed screw and dispense the required amount of food.
2. **Scheduled Feeding**:
   - At 9 a.m. and 6 p.m., ESP32 checks the schedule.
   - If it's time to feed, ESP32 sends a command to the corresponding module to start the feeding process.
   - Follow the feeding mechanism steps outlined above to dispense food.
   - chack if the cat has entered at all during the day before the second feed
   - if cat has already eaten then feed again
   -if cat has not eaten, don´t feed again

## Function List

### Daily Initialization and Calibration Functions

```cpp
void initializeSystem(); // Initializes the system at the start of the day
void calibrateReservoir(); // Calibrates the reservoir position
void checkScheduledFeeding(); // Checks if it's time to feed the cat
void loadFood(); // Loads food from the reservoir to the feed module
void onCatDetected(); // Triggered when a cat is detected
void validateCatInfo(); // Validates the detected cat's information
void logCatEntry(); // Logs the cat's entry time and RFID tag information
void openDoor(); // Sends command to Tiny1614 to open the door
void activateServo(); // Activates the servo motor to open the door
```

### Cat Detection and Door Operation Functions

```cpp
void onCatDetected(); // Triggered when a cat is detected
void validateCatInfo(); // Validates the detected cat's information
void logCatEntry(); // Logs the cat's entry time and RFID tag information
void openDoor(); // Sends command to Tiny1614 to open the door
void activateServo(); // Activates the servo motor to open the door
```

### Feeding Mechanism Functions

```cpp
void determineFoodAmount(); // Determines the required amount of food
void rotateReservoir(); // Rotates the reservoir to the correct position
void rotateFeedScrew(); // Rotates the feed screw to dispense food
void monitorDispensing(); // Monitors food dispensing status
void communicateStatus(); // Communicates status back to ESP32
```

### Scheduled Feeding Functions

```cpp
void checkFeedingSchedule(); // Checks the feeding schedule at 9 a.m. and 6 p.m.
void checkifalreadyate();  // checks if the cat has already eaten once before the second feed of the day
void startFeedingProcess(); // Starts the feeding process if it's time to feed
void executeFeedingMechanism(); // Executes the feeding mechanism steps to dispense food
```

## Installation

To set up the automated cat feeder, follow these steps:

1. Clone the repository:

```bash
git clone https://github.com/yourusername/automated-cat-feeder.git
cd automated-cat-feeder
```

2. Install dependencies:
   - Install the necessary libraries for the ESP32 and Tiny1614. This can be done using the Arduino Library Manager or PlatformIO, depending on your development environment.

3. Upload the code:
   - Connect your ESP32 and Tiny1614 to your computer and upload the respective codes to each microcontroller.

## Usage

Once the system is set up and the code is uploaded, the automated cat feeder will:
- Initialize and calibrate the reservoir position at the start of each day.
- Check the feeding schedule at 9 a.m. and 6 p.m.
- Detect the presence of the cat using the RFID reader.
- Open the door to the food bay when the cat is detected.
- Dispense the required amount of food based on the feeding schedule.

## Contributing

Contributions are welcome! If you have any suggestions or improvements, please create a pull request or open an issue.

## License

This project is licensed under the MIT License. See the LICENSE file for details.
