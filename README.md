# IoT-Based Gas Leak Detection and Automatic Safety Shutoff System

## Overview
-This project implements an Arduino UNO–based gas leak detection system that continuously monitors gas concentration and automatically shuts down the connected load when unsafe levels are detected.  
-The system enhances safety by providing real-time indication and is designed to support IoT-based remote monitoring.

## Objectives
- Detect hazardous gas leakage in industrial and domestic environments  
- Automatically disconnect power or gas supply to prevent accidents  
- Display gas level and system status in real time  
- Improve safety through automated control and monitoring  

## Components Used
- Arduino UNO  
- MQ-2 Gas Sensor *(simulated using potentiometer in Proteus)*  
- DS3231 Real-Time Clock (RTC)  
- 16×2 LCD Display  
- Relay Module  
- LED  

## Working Principle
The gas sensor output is continuously read by the Arduino through an analog input.  
The current time is obtained from the DS3231 RTC and displayed on the LCD along with the gas level.  
When the gas concentration remains below the threshold, the system operates in a safe state.  
If the gas level exceeds the predefined threshold, the relay is triggered to disconnect the load and a warning indication is activated.

## Simulation
The project is simulated using Proteus Design Suite.  
Since the MQ-2 gas sensor is not natively available in Proteus, a potentiometer is used to simulate varying gas concentration levels.

## IoT Extension
The system is designed for IoT integration.  
By interfacing a Wi-Fi module such as ESP8266 or ESP32 with the Arduino UNO, gas level data can be sent to the cloud for remote monitoring and alert notifications.

## Applications
Industrial safety systems, gas plants, kitchens, laboratories, and hazardous working environments.
