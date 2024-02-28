# Project Title: ESP32 Magnetic Door Sensor Integration

## Description:
This project utilizes an ESP32 microcontroller in combination with a magnetic door sensor to monitor the state of a door. The door sensor detects whether the door is open or closed, and the ESP32 captures this information and sends it to various platforms for monitoring and logging purposes. The states of the door are transmitted to WhatsApp and Telegram messaging platforms for real-time notifications, and the data is also logged in a Google Sheet along with timestamps for further analysis.

## Features:
- **Door State Detection**: The magnetic door sensor detects whether the door is open or closed.
- **ESP32 Integration**: The ESP32 microcontroller processes the signals from the door sensor.
- **Real-time Notifications**: Door states are sent to WhatsApp and Telegram for immediate notifications.
- **Data Logging**: Door states along with timestamps are logged into a Google Sheet for historical tracking and analysis.

## Components:
- ESP32 Microcontroller
- Magnetic Door Sensor
- [WhatsApp API](https://randomnerdtutorials.com/esp32-send-messages-whatsapp/)
- [Telegram Bot API](https://randomnerdtutorials.com/telegram-esp32-motion-detection-arduino/)
- [Google Sheets API](https://iotdesignpro.com/articles/esp32-data-logging-to-google-sheets-with-google-scripts)

## Important Note

- Follow The Google Sheets instructions but use sheet_script.txt Script.
- Replace the BOT_TOKEN, CHAT_ID, scriptId with yours, The instruction is in the components section check it out.
![Screenshot](/Smart_Home_Door_Sensor/Reference/Screenshot-2024-02-28-215610.png)
-  Also check the sheet name
-  Write your Wifi SSID and password and Arduino iot cloud secret key
![Screenshot](/Smart_Home_Door_Sensor/Reference/Screenshot-2024-02-28-205036.png)

## Instructions:
- Connect the magnetic door sensor to the ESP32 microcontroller.
- Set up the ESP32 environment and upload the code provided in this repository.
- Configure the WhatsApp and Telegram APIs to receive messages and generate necessary authentication tokens.
- Integrate the WhatsApp and Telegram APIs with the ESP32 code to send door-state notifications.
- Set up the Google Sheets API and obtain the necessary credentials.
- Integrate the Google Sheets API with the ESP32 code to log door states along with timestamps.
- Test the system to ensure proper functionality.
- Document any troubleshooting tips or common issues encountered during setup.
 
## Circuit Diagram

![Screenshot](/Smart_Home_Door_Sensor/Reference/esp32.png)

## Usage:
- Install the necessary libraries and dependencies as mentioned in the repository.
-  Connect the ESP32 board to power and ensure it has internet connectivity.
-   Open the WhatsApp or Telegram application to receive door state notifications.
-     cess the Google Sheet linked in the repository to view logged door states and timestamps.

## Contributing:
Contributions to this project are welcome. If you encounter any bugs or have suggestions for improvements, please submit a pull request or open an issue on GitHub.

## License:
This project is licensed under the [MIT License](link-to-license-file), allowing for modification and distribution under certain terms. Please refer to the license file in the repository for more details.


## Acknowledgments:
- Mention any libraries, tutorials, or resources used in developing this project.
- Acknowledge any contributors or inspirations for the project.


