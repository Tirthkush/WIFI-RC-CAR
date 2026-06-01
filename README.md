# ESP32 Wi-Fi Controlled RC Car

## Overview

This project converts an old remote-controlled toy car into a Wi-Fi-controlled robotic vehicle using the ESP32 microcontroller and a TB6612FNG motor driver.

Instead of using the original RF remote system, the vehicle is controlled through a custom web interface hosted directly on the ESP32 operating in Wi-Fi Access Point (AP) mode. Any smartphone or laptop can connect to the ESP32 network and control the vehicle through a web browser without requiring an external router or internet connection.

The project focuses on embedded systems, wireless communication, motor control, power management, and practical hardware integration.

---

## Features

* Wi-Fi-based wireless control
* Browser-controlled interface
* ESP32 Access Point mode operation
* TB6612FNG motor driver integration
* Differential drive movement
* Battery-powered operation
* No external router required

---

## Hardware Used

* ESP32 Development Board
* TB6612FNG Motor Driver
* DC Motors
* Modified RC Car Chassis
* 18650 Li-ion Batteries
* Buck Converter
* Breadboard / Prototype Wiring
* Connecting Wires

---

## System Architecture

### ESP32 Controller

The ESP32 acts as both:

* Wireless Access Point
* Embedded Web Server

A smartphone connects directly to the ESP32 network and accesses the control page through a browser.

### Motor Driver

The TB6612FNG motor driver receives movement commands from the ESP32 and drives the left and right motors accordingly.

Supported movements:

* Forward
* Backward
* Left
* Right
* Stop

---

## Working Principle

1. ESP32 creates a Wi-Fi Access Point.
2. User connects a smartphone to the ESP32 network.
3. Browser-based control interface is opened.
4. Movement commands are sent through the webpage.
5. ESP32 processes incoming commands.
6. TB6612FNG drives the motors.
7. Vehicle responds in real time.

---

## Power Architecture

A separate battery supply was used for the ESP32 and motor system to improve stability.

### Why Separate Supplies?

Wi-Fi transmission on the ESP32 creates sudden current spikes. When combined with motor startup currents, voltage drops can occur, causing:

* Brownout resets
* System instability
* Unexpected reboots

To prevent this:

* ESP32 was powered separately
* Motors used an independent power path
* Buck converter provided regulated voltage

This improved reliability and reduced noise-related issues.

---

## Why TB6612FNG Instead of L298N?

The TB6612FNG motor driver was selected because it offers:

* Higher efficiency
* Lower voltage drop
* MOSFET-based design
* Reduced heat generation
* Better battery utilization
* Compact size

Compared to the L298N, it is significantly more suitable for modern low-voltage embedded systems.

---

## ESP32 Features Utilized

* Wi-Fi Access Point Mode
* Embedded Web Server
* GPIO Control
* PWM Motor Control
* Real-Time Wireless Communication

---

## Challenges Encountered

### Power Stability

Motor startup currents introduced voltage fluctuations that occasionally affected system stability.

### Brownout Resets

The ESP32 experienced brownout conditions during Wi-Fi transmission when power delivery was insufficient.

### Electrical Noise

Motor noise introduced disturbances into the system, requiring careful power management and grounding.

### Mechanical Constraints

Integrating modern electronics into an old RC car chassis required modifications and mechanical adjustments.

---

## Results

The RC car was successfully converted into a Wi-Fi-controlled robotic platform capable of real-time browser-based control.

The system demonstrated reliable wireless communication, responsive vehicle movement, and practical implementation of embedded control concepts.

---

## Key Learnings

* ESP32 Wi-Fi Networking
* Embedded Web Servers
* Motor Driver Interfacing
* Differential Drive Systems
* Battery Power Management
* Brownout Prevention Techniques
* Hardware Debugging and Integration

---

## Future Improvements

* PWM Speed Control
* Obstacle Avoidance Sensors
* ESP-NOW Communication
* Camera Streaming
* Mobile Application Interface
* Custom PCB Design
* Autonomous Navigation Features

---

## Applications

* Educational Robotics
* IoT-Based Vehicles
* Remote-Controlled Platforms
* Embedded Systems Learning
* Wireless Automation Systems

---

## Author

Tirth Kushwaha

Electronics & Telecommunication Engineering

Embedded Systems | IoT | Robotics
