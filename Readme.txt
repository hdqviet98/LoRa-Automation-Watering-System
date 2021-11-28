LoRa Automation Watering System

• Learn and study hardware operating principles, features of PIC microcontrollers, LoRa module E22-900T22S, wifi module ATWINC1500, HMI screen Nextion NX3224T024, humidity sensor FS200-SHT20, temperature sensor soil moisture JXBS-3001-TR, wifi security IC ATECC608A, real-time IC DS1307, power IC LM2594 and LM2596.
• Learn about the protocol Modbus, UART, MQTT, I2C, SPI systems.
• Hardware design and construction.
• Write programs for modules of the system.
• Run test.
• Write project report.

HMI: code for HMI use on Nextion Editor free (HMI Nextion NX3224T024).
Master_FJ128_705: Code for Control Center on MPLab X IDE use MCU PICFJ128705.
Slave_F45_42_relay: Code for Node Relay on MPLab X IDE use MCU PICPICF45K42.
Slave_F45_42_sensor:Code for Node Sensor on MPLab X IDE use MCU PICPICF45K42.
The MCU on the Sensor Nodes collects data from the sensors and then sends it through the LoRa module E22-900T22S on this node to that LoRa module in the Main Control via the 16-bit MCU to the Nextion NX3224T024 HMI display. 
The MCU on the Main Control will send automatic control signals based on the collected data or manually (from the HMI screen) via LoRa to the MCU on the Relay Nodes to control the pump system.
