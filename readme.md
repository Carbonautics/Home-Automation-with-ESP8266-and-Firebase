# Home Automation using ESP8266 and Firebase

> A simple automation project code to control few AC appliances using the ESP8266 NodeMCU and Google Firebase (RTDB)

## Table of Contents

- [Home Automation using ESP8266 and Firebase](#home-automation-using-esp8266-and-firebase)
  - [Table of Contents](#table-of-contents)
  - [General Information](#general-information)
  - [Technologies Used](#technologies-used)
  - [Dependencies](#dependencies)
  - [Features](#features)
  - [Room for improvements](#room-for-improvements)
  - [Working](#working)
  - [Project Status](#project-status)

## General Information

- Basically the MCU will manipulate the control signals and store them in the FirebaseRTDB and control appliances using the signals from the RTDB.
- Purpose of the project? This code was developed as a course project for an elective course 'Robotics and Automation' in my 6th Semester at college. The idea was to create an automation project using actual hardware while others used software simulations to do similar projects.
  
## Technologies Used

- [Platform IO (PIO)](https://platformio.org/) [inside Visual Studio Code Insiders](https://docs.platformio.org/en/latest/integration/ide/pioide.html#platformio-for-vscode)
- ESP8266 NodeMCU - [Software](https://docs.platformio.org/en/latest/boards/espressif8266/nodemcuv2.html): Board Package Version (in PIO): v2.6.3 | Hardware: NodeMCU 1.0 (ESP-12E Module)
  
- [Google Firebase(RTDB)](https://firebase.google.com/docs/guides)
- [MIT App Inventor](https://appinventor.mit.edu/)

## Dependencies

- Arduino (automatically included by PIO)
- [ESP8266WiFi & ESP8266HTTPClient](https://docs.platformio.org/en/latest/boards/espressif8266/nodemcuv2.html) (should be included when installing board firmware in PIO) - v2.6.3
- [FirebaseESP8266](https://github.com/mobizt/Firebase-ESP8266) - v3.2.2

## Features

Ready Features:

- Connect to wifi by added your SSID and Password.
- Control max. of 3 devices (switchable).
- LDR support for automatic lighting controls. (includes manual override) (un-tested)
- Android app to control the appliances.

## Room for improvements

- LDR feature has to be tested yet.
- Will have to create Firebase RTDB manually, doesn't work directly without it.
- Dynamically provide feature to change SSID and password on a mobile perhaps.

## Working

The nodeMCU turns on, connects to the hard-coded SSID. Then the connection with Firebase begins, assuming, Firebase RTDB setup was done correctly, it will proceed to fetch the previous states from the cloud after successful connection.

Appliance state changes to whatever was fetched from the cloud. The state of appliances in the cloud is changed using the manual switch which acts as an override in-case of system failure or using the mobile app.

**Summary:**

- Mobile app or the manual switch changes the state in the cloud. (Manual switch takes precedence over app).

- The MCU fetches states data from the cloud and sets the appliances to that state, again depends on the manual switch (switch takes precedence over cloud for redundancy purposes).

[_Actual Code_](https://github.com/Carbonautics/Home-Automation-with-ESP8266-and-Firebase/blob/main/src/main.cpp)

## Project Status

Project is completed and no longer being worked on since the project was submitted to the professor as the course project for that semester and currently (as of uploading this readme) placements season has officialy taken over my life.
