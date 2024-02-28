#include "arduino_secrets.h"
#include "thingProperties.h"
#define DOOR_SENSOR_PIN  19  // ESP32 pin GPIO19 connected to door sensor's pin
#include <HTTPClient.h>
#include <UrlEncode.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

#define BOT_TOKEN "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"

// Use @myidbot (IDBot) to find out the chat ID of an individual or a group
// Also note that you need to click "start" on a bot before it can
// message you
#define CHAT_ID "xxxxxxxxxxxxxxxxxxxxxxxx"

WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);

int doorState;
bool doorStateChangeDetected = false;
bool wasDoorOpen = false;
bool dataSent = false;
const char* scriptId = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
const char* sheetName = "Sensor_Data";
float sensor2Value = 0.0;

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
  */
  secured_client.setCACert(TELEGRAM_CERTIFICATE_ROOT);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  pinMode(DOOR_SENSOR_PIN, INPUT_PULLUP);
}

void loop() {
  ArduinoCloud.update();
  // Your code here
  doorState = digitalRead(DOOR_SENSOR_PIN); // read state
  delay(1000);
  if (doorState == HIGH) {
    if (!doorStateChangeDetected) {
      if (!dataSent) {
        Serial.println("The door is open");
        bot.sendMessage(CHAT_ID, "The door is open", "");
        sendMessage("The door is open");
        door = true;
        doorStateChangeDetected = true;
        String sensor1Value = "open";
        sendGoogle(sensor1Value, sensor2Value);
        dataSent = true;
      }
    }
  } else {
    doorStateChangeDetected = false;
    if (wasDoorOpen) {
      Serial.println("The door is closed");
      bot.sendMessage(CHAT_ID, "The door is closed", "");
      sendMessage("The door is closed");
      door = false;
      wasDoorOpen = false;
      String sensor1Value = "closed";
      sendGoogle(sensor1Value, sensor2Value);
      dataSent = false;
    }
  }

  if (doorState == HIGH) {
    wasDoorOpen = true;
  }

  delay(1000);
}

void sendGoogle(String sensor1, float sensor2) {
  HTTPClient http;

  String url = "https://script.google.com/macros/s/" + String(scriptId) + "/exec?id=" + sheetName;
  url += "&Sensor1=" + String(sensor1);
  url += "&Sensor2=" + String(sensor2);

  http.begin(url);

  int httpCode = http.GET();


  http.end();
}
void sendMessage(String message) {

  // Data to send with HTTP POST
  String url = "https://api.callmebot.com/whatsapp.php?phone=917557899105&text=" + urlEncode(message) + "&apikey=4720753" ;
  HTTPClient http;
  http.begin(url);

  // Specify content-type header
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  // Send HTTP POST request
  int httpResponseCode = http.POST(url);


  // Free resources
  http.end();
}

/*
  Since Servo is READ_WRITE variable, onServoChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onServoChange()  {
  // Add your code here to act upon Servo change
}
