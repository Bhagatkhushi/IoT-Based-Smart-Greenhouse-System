# IoT Based Greenhouse Monitoring and Control System

## Overview

This project is an IoT-based system that monitors and controls environmental conditions in a greenhouse using Arduino.

## Features

* Temperature Monitoring (DHT11)
* Humidity Monitoring
* Soil Moisture Detection
* Light Intensity Detection (LDR)
* Automatic Control (Fan, Pump, Light)
* LCD Display Output

## Hardware Components

* Arduino UNO
* DHT11 Sensor
* Soil Moisture Sensor
* LDR Sensor
* LCD (I2C)
* Relay Module

## Working

The system continuously monitors environmental conditions inside the greenhouse using multiple sensors.

* The **DHT11 sensor** measures temperature and humidity.
* The **soil moisture sensor** detects the water level in the soil.
* The **LDR sensor** measures light intensity.

All sensor data is sent to the Arduino microcontroller, where it is processed.

Based on predefined threshold values:

* If temperature is high, the fan is turned ON.
* If humidity exceeds the limit, ventilation is activated.
* If soil moisture is low, the water pump is turned ON.
* If light intensity is low, artificial light is switched ON.

The current values of temperature, humidity, soil moisture, and light are displayed on the LCD screen.

This system works automatically without human intervention, helping to maintain optimal conditions for plant growth.


## Code

The Arduino code is included in this repository.

## Project Images

<p align="center">
  <img src="images/1.jpeg" width="400"/>
  <img src="images/3.jpeg" width="400"/>
  <img src="images/4.jpeg" width="400"/>
</p>

## Applications

* Smart Agriculture
* Greenhouse Automation
* IoT Monitoring Systems

## Author

Khushi Bhagat
