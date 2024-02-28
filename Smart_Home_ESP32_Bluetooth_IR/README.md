# Home Automation Project with ESP32 and MIT App Inventor

This project allows users to control home appliances such as lights and fans using an Android app developed with MIT App Inventor. The system utilizes an ESP32 microcontroller along with a relay module for controlling the appliances. One of the unique features of this project is its ability to function without the need for a WiFi connection; instead, it relies on Bluetooth connectivity for communication between the app and the ESP32.

## Features

- Control lights and fans remotely using a smartphone app.
- No WiFi connection required; operates via Bluetooth.
- Simple and intuitive user interface designed with MIT App Inventor.
- Easily customizable for adding more appliances or features.

## Hardware Components

- ESP32 microcontroller
- Relay module
- Light and fan circuits
- Smartphone with Bluetooth capability

## Software Components

- Arduino IDE for ESP32 programming
- MIT App Inventor for Android app development
	
## Setup Instructions

1. **Hardware Setup**:
   - Connect the relay module to the ESP32 according to the circuit diagram.
   - Ensure proper connections for lights and fans to the relay module.

2. **Software Setup**:
   - Install the Arduino IDE on your computer if not already installed.
   - Download the necessary libraries for ESP32 Bluetooth communication.
   - Open the Arduino sketch provided in this repository.
   - Upload the sketch to the ESP32.

3. **App Setup**:
   - Import the MIT App Inventor project provided in this repository.
   - Customize the app interface and functionality as needed.
   - Build the app and install it on your Android smartphone.

4. **Usage**:
   - Power up the ESP32 and ensure Bluetooth is enabled.
   - Open the app on your smartphone and connect to the ESP32 via Bluetooth.
   - Use the app to control the lights and fans remotely.

## Circuit Diagram

![Screenshot](/Smart_Home_ESP32_Bluetooth_IR/Reference/esp32.png)


## Contributing

Contributions to this project are welcome. Feel free to open an issue or submit a pull request with any improvements or bug fixes.

## License

This project is licensed under the [MIT License](LICENSE).

---

