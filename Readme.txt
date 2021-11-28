HMI: code for HMI use on Nextion Editor free (HMI Nextion NX3224T024).
Master_FJ128_705: Code for Control Center on MPLab X IDE use MCU PICFJ128705.
Slave_F45_42_relay: Code for Node Relay on MPLab X IDE use MCU PICPICF45K42.
Slave_F45_42_sensor:Code for Node Sensor on MPLab X IDE use MCU PICPICF45K42.
The MCU on the Sensor Nodes collects data from the sensors and then sends it through the LoRa module E22-900T22S on this node to that LoRa module in the Main Control via the 16-bit MCU to the Nextion NX3224T024 HMI display. 
The MCU on the Main Control will send automatic control signals based on the collected data or manually (from the HMI screen) via LoRa to the MCU on the Relay Nodes to control the pump system.