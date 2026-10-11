# Vest-Firmware

Work in Progress (WIP): This is an active development repository. Some features may be unstable or broken at times as core functionality is prioritised.

# Features

* Low-Latency Bluetooth (BLE): Uses the NimBLE-Arduino stack to maintian maximum efficiency, responsiveness, and small overhead.
* Dynamic Motor Mapping: Implements a clean array-index based architecture to dynamically map software commands to motor channels via motor drivers.
* Modular Architecture: Designed to scale from basic motor testing to full scale haptic systems.
* Battery Monitoring: SOC battery monitoring *Currently not configured as I had lost it during assembly :(*
* User Interaction: Includes a button for user config and 2 LEDs for battery life and debug.

# Tech Stack & Requirements
* MCU: ESP32-S3
* Environment: PlatformIO / Arduino
* Dependencies: 'NimBLE-Arduino', 'Adafruit_PWMServoDriver' *Subject to change at any time*
