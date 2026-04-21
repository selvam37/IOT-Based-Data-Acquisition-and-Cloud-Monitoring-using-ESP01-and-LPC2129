IOT-Based-Data-Acquisition-and-Cloud-Monitoring-using-ESP01-and-LPC2129

Overview

This project implements a real-time IoT-based temperature monitoring system using the LPC2129 microcontroller. The temperature is measured using an LM35 sensor, converted into digital form using the MCP3208 (12-bit SPI ADC), and transmitted to the ThingSpeak cloud platform via the ESP-01 Wi-Fi module.
The system demonstrates integration of analog sensing, SPI communication, UART-based Wi-Fi control, and cloud data visualization.

Features

Accurate temperature sensing using LM35
12-bit analog-to-digital conversion using MCP3208
SPI communication between LPC2129 and ADC
UART communication with ESP-01 using AT commands
Real-time cloud monitoring via ThingSpeak
Technologies Used
Microcontroller: LPC2129 (ARM7)
Sensor: LM35 Temperature Sensor
ADC: MCP3208 12-bit ADC
Wi-Fi Module: ESP-01 ESP8266 Wi-Fi Module
Communication Protocols:
SPI (ADC interface)
UART (ESP-01 communication)
HTTP over TCP/IP (ThingSpeak upload)
Programming Language: Embedded C

System Architecture

LM35 senses ambient temperature and outputs analog voltage
MCP3208 converts analog voltage into 12-bit digital data
LPC2129 reads ADC data via SPI
Temperature value is calculated from ADC output
Data is formatted into HTTP request
ESP-01 receives AT commands via UART
Data is sent to ThingSpeak server
User monitors temperature remotely
Simple Flow Diagram

[ LM35 Sensor ]
        ↓ 
(Analog Voltage)
[ MCP3208 ADC ]
        ↓ 
(SPI Communication)
[ LPC2129 Microcontroller ]
        ↓
(UART - AT Commands)
[ ESP-01 Wi-Fi Module ]
        ↓
(Internet - HTTP)
[ ThingSpeak Cloud ]
        ↓
[ User Dashboard ]

Working Logic (Step-by-Step)

LM35 outputs 10mV per °C
MCP3208 converts this analog signal into a digital value (0–4095)
LPC2129 reads this value using SPI protocol
Temperature is calculated using conversion formula
UART sends AT commands to ESP-01
ESP-01 connects to Wi-Fi and sends data using HTTP GET
ThingSpeak displays the temperature in graphical form
Hardware Components
LPC2129 Microcontroller
LM35 Temperature Sensor
MCP3208 ADC
ESP-01 Wi-Fi Module
3.3V Regulated Power Supply
Connecting wires and supporting components

Conclusion

This project successfully integrates analog sensing, digital conversion, embedded processing, and cloud communication. It provides a complete end-to-end IoT solution and demonstrates strong fundamentals in SPI, UART, and embedded networking.
