# MotionDriver

**MotionDriver** is a driver developed for the Arduino Nano, used in the Asper V2. This driver is responsible for controlling the motors of Asper, enabling precise movement through serial commands. The driver supports one bipolar stepper motor (controlled via DRV8825) and two servo motors, all managed via serial communication.

## Table of Contents
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Hardware Connections](#hardware-connections)
- [Installation](#installation)
- [Usage](#usage)
  - [Communication Protocol](#communication-protocol)
  - [Example Commands](#example-commands)
  - [Schematic Diagram](#schematic-diagram)
- [Further Development](#further-development)
- [Contributing](#contributing)
- [License](#license)


## Features
- Control one bipolar stepper motor using DRV8825 driver.
- Control two servo motors.
- Simple and intuitive serial communication protocol.
- Commands for turning, centering, and stepping motors.
- Easy integration with other systems via serial port.

## Hardware Requirements
- Arduino Nano
- DRV8825 Stepper Motor Driver
- Bipolar Stepper Motor
- Two Servo Motors
- Connection Cables

## Hardware Connections

### Schematic Diagram
The following describes the connections between the Arduino Nano, DRV8825 stepper motor driver, servo motors, and Jetson Nano:

- **Arduino Nano to Jetson Nano:**
  - Serial port connection
  
- **Power Supply:**
  - 8-12V power supply to DRV8825
  
- **DRV8825 to Arduino Nano:**
  - Step-pin: Pin 2
  - Dir-pin: Pin 3
  - Enable-pin: Pin 4
  
- **DRV8825 to Stepper Motor:**
  - Connect stepper motor wires to the corresponding outputs on the DRV8825
  
- **Servo Motors to Arduino Nano:**
  - X-axis servo: Pin 5
  - Y-axis servo: Pin 6

Here is a simple schematic diagram:

```
         +--------------------+
         | Arduino Nano       |
         |                    |
         | 2   -> Step-pin    |
         | 3   -> Dir-pin     |
         | 4   -> Enable-pin  |
         | 5   -> X Servo     |
         | 6   -> Y Servo     |
         | TX/ -> Serial to   |
         | RX    Jetson Nano  |
         +--------------------+
```

## Installation
**Clone the repository:**
```bash
git clone https://github.com/IshantPundir/MotionDriver.git
```

## Usage

### Communication Protocol
The communication with the **MotionDriver** is performed via serial commands. Each command follows the structure:
```
[MotorType] [Action] [Parameters]
```

#### Motor Types:
- `S` for Stepper motor
- `X` for X-axis servo
- `Y` for Y-axis servo

#### Actions:
- **For Stepper Motor (S):**
  - `T` for Turn: `T angle speed`
  - `R` for Release: `R`
- **For Servos (X, Y):**
  - `C` for Center: `C`
  - `T` for TurnToAngle: `T angle`
  - `S` for Step: `S value`

### Example Commands
- Turn the stepper motor to 90 degrees at speed 100:
  ```
  S T 90 100
  ```
- Release the stepper motor:
  ```
  S R
  ```
- Center the X-axis servo:
  ```
  X C
  ```
- Turn the Y-axis servo to 45 degrees:
  ```
  Y T 45
  ```
- Move the X-axis servo by 10 degrees from the center position:
  ```
  X S 10
  ```

## Further Development
To further develop this project, consider the following:
- Read and Modify configurations via serial communication.
- Implementing more complex motion sequences.
- Enhancing error handling and feedback via serial communication.