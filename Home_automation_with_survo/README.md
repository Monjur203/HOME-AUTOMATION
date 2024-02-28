
# Home Automation Project with ESP32, Arduino IoT Cloud, and Alexa Integration

This project utilizes ESP32 microcontroller along with Arduino IoT Cloud to create a comprehensive home automation system. It allows users to control home appliances such as lights and fans remotely using various interfaces including an Android app, a website, a remote control, and integration with Amazon Alexa voice commands. Additionally, it incorporates a servo motor to enable control of the fan regulator for added functionality and convenience.

## Features

- Control lights and fans remotely using ESP32 microcontroller.
- Integration with Arduino IoT Cloud for seamless connectivity and management.
- Compatibility with Amazon Alexa for voice-controlled operations.
- Android app for easy control via smartphones.
- Web interface for remote access from any browser.
- Remote control option for traditional operation.
- Servo motor integration for precise control of the fan regulator.

## Components Used

- ESP32 microcontroller
- Relay module
- Servo motor
- IR sensors 
- Android smartphone (for app control)
- Amazon Alexa device (for voice control)
- Remote control (optional)
## Setup Instructions

![App Screenshot](https://i.ibb.co/3C0nGqM/esp32-servo.png)

### 1.	Hardware Setup:

- Connect the ESP32 microcontroller to the relay module and servo motor according to the circuit diagram.
- Ensure all connections are secure and properly soldered.
- Power up the ESP32 and relay module.

### 2.	Software Setup:

- Install the necessary libraries for ESP32, Arduino IoT Cloud, and servo motor control.
- Set up the Arduino IoT Cloud account and configure your devices.
- Upload the provided Arduino sketch to the ESP32 microcontroller.

### 3.	Integration with Amazon Alexa:

- Follow the instructions to integrate the project with Amazon Alexa for voice control. [Click here](https://docs.arduino.cc/arduino-cloud/guides/alexa/#alexa-setup)

### 4.	Android App Setup:
- Install the provided Android app on your smartphone.
- Configure the app to connect to your ESP32 device.
### 5.	Web Interface:
- Access the provided web interface and configure it to connect to your ESP32 device.
### 6.	Remote Control (Optional):
- If using a remote control, ensure it's synced with the ESP32 device.
### 7.	Test and Calibration:
- Test each functionality (light control, fan control, servo motor) to ensure proper operation.
- Calibrate the servo motor for precise control of the fan regulator.

## Usage

- **Android App:** Open the app and select the desired appliance (light or fan) and adjust settings as needed.
- **Web Interface:** Access the web interface from any browser, login, and control appliances remotely.
- **Amazon Alexa:** Issue voice commands to Alexa to control appliances.
- **Remote Control:** Use the provided remote control for traditional operation.
- **Servo Motor Control:** Adjust the fan regulator using the servo motor control feature.
## Importent Note

- Change the device ID and Secret key.
![App Screenshot](https://i.ibb.co/0BnSvZp/Screenshot-2024-02-28-104720.png)

- Flowe the instructions to create an Arduino id account and get the Device ID and Secret key. [Click here](https://iotcircuithub.com/arduino-iot-cloud-tutorial-esp8266-esp32/)

- Follow the instructions top to the “Sketch for Arduino IoT Cloud projects” part after this the information is outdated.

- When creating a Variable in Arduino iot cloud the name of the variable should match with the photo name.
![App Screenshot](https://i.ibb.co/KhrZR0J/Screenshot-2024-02-28-105024.png)
![App Screenshot](https://i.ibb.co/s2jWR81/Screenshot-2024-02-28-105114.png)




## Contributing

Contributions are welcome! If you have any suggestions, improvements, or feature additions, feel free to submit a pull request.


## License

This project is licensed under the [MIT License.](https://choosealicense.com/licenses/mit/)


## Acknowledgements

- Thanks to the Arduino community for their valuable resources and support.
- Inspiration from various open-source home automation projects.
- Gratitude to contributors and users who help improve and test the project.
