
#include <WiFiManager.h>
#include "thingProperties.h"
#include <ESP32Servo.h>

char ssid[32]; // SSID char limit
char pass[63];


const int resetButtonPin = 26;

#define IR_RECV_PIN         35
#define RelayPin1 23  //D23
#define RelayPin2 22  //D22
#define RelayPin3 21  //D21
#define RelayPin4 19  //D19
int servoPin=18;
int myservo2;
int survo;
Servo myservo;
#define SwitchPin1 13  //D13
#define SwitchPin2 12  //D12
#define SwitchPin3 14  //D14
#define SwitchPin4 27  //D27

  IRrecv irrecv(IR_RECV_PIN);
  decode_results results;
  
int toggleState_1 = 0; //Define integer to remember the toggle state for relay 1
int toggleState_2 = 0; //Define integer to remember the toggle state for relay 2
int toggleState_3 = 0; //Define integer to remember the toggle state for relay 3
int toggleState_4 = 0; //Define integer to remember the toggle state for relay 4

// Switch State
bool SwitchState_1 = LOW;
bool SwitchState_2 = LOW;
bool SwitchState_3 = LOW;
bool SwitchState_4 = LOW;



void onSwitch1Change();
void onSwitch2Change();
void onSwitch3Change();
void onSwitch4Change();
void onSurvoChange();

CloudSwitch switch1;
CloudSwitch switch2;
CloudSwitch switch3;
CloudSwitch switch4;



void initProperties(){
  const char DEVICE_LOGIN_NAME[]  = "e762f4bf-01fd-4457-8a39-b9482920e574";
  const char DEVICE_KEY[]         = "WQYKWRQEXRRWCAZ34OXF";
  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  //ArduinoCloud.setThingId(THING_ID);
  ArduinoCloud.addProperty(switch1, READWRITE, ON_CHANGE, onSwitch1Change);
  ArduinoCloud.addProperty(switch2, READWRITE, ON_CHANGE, onSwitch2Change);
  ArduinoCloud.addProperty(switch3, READWRITE, ON_CHANGE, onSwitch3Change);
  ArduinoCloud.addProperty(switch4, READWRITE, ON_CHANGE, onSwitch4Change);
  ArduinoCloud.addProperty(survo, READWRITE, ON_CHANGE, onSurvoChange);
 
}

void ir_remote_control(){

  if (irrecv.decode(&results)) {
    
      switch(results.value){
          case 0x11D9D827:  relayOnOff(1); switch1 = toggleState_1; break; //update the HEX-code
          case 0x11D99867:  relayOnOff(2); switch2 = toggleState_2; break; //update the HEX-code
          case 0x11D9906F:  relayOnOff(3); switch3 = toggleState_3; break; //update the HEX-code
          case 0x11D930CF:  relayOnOff(4); switch4 = toggleState_4; break; //update the HEX-code
          case 0x11D9807F:  // Volume Up
            myservo2 += 30;
            if (myservo2 > 180) {
              myservo2  = 180;  // Limit the servo position to 180 degrees
            }
            myservo.write(myservo2);
            
            break;
          case 0x11D9B04F:  // Volume Down
            myservo2 -= 30;
            if (myservo2 < 0) {
              myservo2 = 0;  // Limit the servo position to 0 degrees
            }
            myservo.write(myservo2);
            
            break;
          default : break;         
        }   
        Serial.println(results.value, HEX);
        irrecv.resume();   
  } 
}

void relayOnOff(int relay) {

  switch (relay) {
    case 1:
      if (toggleState_1 == 0) {
        digitalWrite(RelayPin1, LOW); // turn on relay 1
        toggleState_1 = 1;
        switch1 = toggleState_1;
        onSwitch1Change(); // Trigger the callback to update the Arduino IoT Cloud
        Serial.println("Device1 ON");
      } else {
        digitalWrite(RelayPin1, HIGH); // turn off relay 1
        toggleState_1 = 0;
        switch1 = toggleState_1;
        onSwitch1Change(); // Trigger the callback to update the Arduino IoT Cloud
        Serial.println("Device1 OFF");
      }
      delay(100);
      break;
    case 2:
       if (toggleState_2 == 0) {
        digitalWrite(RelayPin2, LOW); // turn on relay 1
        toggleState_2 = 1;
        switch2 = toggleState_2;
        onSwitch2Change(); // Trigger the callback to update the Arduino IoT Cloud
        Serial.println("Device1 ON");
      } else {
        digitalWrite(RelayPin2, HIGH); // turn off relay 1
        toggleState_2 = 0;
        switch2 = toggleState_2;
        onSwitch2Change(); // Trigger the callback to update the Arduino IoT Cloud
        Serial.println("Device1 OFF");
      }
      delay(100);
      break;
    case 3:
       if (toggleState_3 == 0) {
        digitalWrite(RelayPin3, LOW); // turn on relay 1
        toggleState_3 = 1;
        switch3 = toggleState_3;
        onSwitch3Change(); // Trigger the callback to update the Arduino IoT Cloud
        Serial.println("Device1 ON");
      } else {
        digitalWrite(RelayPin3, HIGH); // turn off relay 1
        toggleState_3 = 0;
        switch3 = toggleState_3;
        onSwitch3Change(); // Trigger the callback to update the Arduino IoT Cloud
        Serial.println("Device1 OFF");
      }
      delay(100);
      break;
    case 4:
       if (toggleState_4 == 0) {
        digitalWrite(RelayPin4, LOW); // turn on relay 1
        toggleState_4 = 1;
        switch4 = toggleState_4;
        onSwitch4Change(); // Trigger the callback to update the Arduino IoT Cloud
        Serial.println("Device1 ON");
      } else {
        digitalWrite(RelayPin4, HIGH); // turn off relay 1
        toggleState_4 = 0;
        switch4 = toggleState_4;
        onSwitch4Change(); // Trigger the callback to update the Arduino IoT Cloud
        Serial.println("Device1 OFF");
      }
      delay(100);
      break;
    default : break;
  }
}

void manual_control()
{
  if (digitalRead(SwitchPin1) == LOW && SwitchState_1 == LOW) {
    digitalWrite(RelayPin1, LOW);
    toggleState_1 = 1;
    SwitchState_1 = HIGH;
    switch1 = toggleState_1;
    Serial.println("Switch-1 on");
  }
  if (digitalRead(SwitchPin1) == HIGH && SwitchState_1 == HIGH) {
    digitalWrite(RelayPin1, HIGH);
    toggleState_1 = 0;
    SwitchState_1 = LOW;
    switch1 = toggleState_1;
    Serial.println("Switch-1 off");
  }
  if (digitalRead(SwitchPin2) == LOW && SwitchState_2 == LOW) {
    digitalWrite(RelayPin2, LOW);
    toggleState_2 = 1;
    SwitchState_2 = HIGH;
    switch2 = toggleState_2;
    Serial.println("Switch-2 on");
  }
  if (digitalRead(SwitchPin2) == HIGH && SwitchState_2 == HIGH) {
    digitalWrite(RelayPin2, HIGH);
    toggleState_2 = 0;
    SwitchState_2 = LOW;
    switch2 = toggleState_2;
    Serial.println("Switch-2 off");
  }
  if (digitalRead(SwitchPin3) == LOW && SwitchState_3 == LOW) {
    digitalWrite(RelayPin3, LOW);
    toggleState_3 = 1;
    SwitchState_3 = HIGH;
    switch3 = toggleState_3;
    Serial.println("Switch-3 on");
  }
  if (digitalRead(SwitchPin3) == HIGH && SwitchState_3 == HIGH) {
    digitalWrite(RelayPin3, HIGH);
    toggleState_3 = 0;
    SwitchState_3 = LOW;
    switch3 = toggleState_3;
    Serial.println("Switch-3 off");
  }
  if (digitalRead(SwitchPin4) == LOW && SwitchState_4 == LOW) {
    digitalWrite(RelayPin4, LOW);
    toggleState_4 = 1;
    SwitchState_4 = HIGH;
    switch4 = toggleState_4;
    Serial.println("Switch-4 on");
  }
  if (digitalRead(SwitchPin4) == HIGH && SwitchState_4 == HIGH) {
    digitalWrite(RelayPin4, HIGH);
    toggleState_4 = 0;
    SwitchState_4 = LOW;
    switch4 = toggleState_4;
    Serial.println("Switch-4 off");
  }
}  


void doThisOnConnect(){
 
  Serial.println("Board successfully connected to Arduino IoT Cloud");
  
  
}
void doThisOnSync(){
 
  Serial.println("Thing Properties synchronised");
}

void doThisOnDisconnect(){
 
  Serial.println("Board disconnected from Arduino IoT Cloud"); 
}




void setup() {
    // Initialize serial and wait for port to open:
  Serial.begin(115200);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);
  myservo.attach(servoPin);
  pinMode(resetButtonPin, INPUT_PULLUP);

  // Check if the reset button is pressed during startup
  if (digitalRead(resetButtonPin) == LOW) {
    Serial.println(F("Reset button pressed during startup"));
    WiFiManager wifiManager;
    wifiManager.resetSettings();  // Reset WiFi settings
    //Serial.println("WiFi settings reset");
  } else {
    // Create an instance of WiFiManager
    WiFiManager wifiManager;
    
    // Try to connect to saved WiFi credentials.
    // If not found, enter the configuration mode.
    if (!wifiManager.autoConnect("AutoConnectAP")) {
      Serial.println(F("Failed to connect and hit timeout"));
      // Reset and try again, or maybe put it to deep sleep
      //ESP.restart();
      delay(1000);
    }
       if (wifiManager.autoConnect("AutoConnectAP")) {
       Serial.println(F("Connected to WiFi!"));
        initProperties();
        //Serial.println("connected...yeey :)");
      String str_ssid = wifiManager.getWiFiSSID(false);
      int len = str_ssid.length() + 1;
      str_ssid.toCharArray(ssid,len);
      //Serial.println(ssid);
      String str_pass = wifiManager.getWiFiPass(false);
      len = str_pass.length() + 1;
      str_pass.toCharArray(pass,len);
      //Serial.println(pass);
      preferredConnectionHandler(ssid, pass);

      
  
      irrecv.enableIRIn(); // Start the receiver
      // Connect to Arduino IoT Cloud
      ArduinoCloud.begin(ArduinoIoTPreferredConnection);
    
      ArduinoCloud.addCallback(ArduinoIoTCloudEvent::CONNECT, doThisOnConnect);
      ArduinoCloud.addCallback(ArduinoIoTCloudEvent::SYNC, doThisOnSync);
      ArduinoCloud.addCallback(ArduinoIoTCloudEvent::DISCONNECT, doThisOnDisconnect);
    
      setDebugMessageLevel(2);
      ArduinoCloud.printDebugInfo();

    }

  }

   pinMode(RelayPin1, OUTPUT);
  pinMode(RelayPin2, OUTPUT);
  pinMode(RelayPin3, OUTPUT);
  pinMode(RelayPin4, OUTPUT);


  pinMode(SwitchPin1, INPUT_PULLUP);
  pinMode(SwitchPin2, INPUT_PULLUP);
  pinMode(SwitchPin3, INPUT_PULLUP);
  pinMode(SwitchPin4, INPUT_PULLUP);

  //During Starting all Relays should TURN OFF
  digitalWrite(RelayPin1, HIGH);
  digitalWrite(RelayPin2, HIGH);
  digitalWrite(RelayPin3, HIGH);
  digitalWrite(RelayPin4, HIGH);
}

void loop() {
    
      ArduinoCloud.update();
  
  manual_control();     //Manual Control
  ir_remote_control();
}

void onSwitch1Change() {
  //Control the device
  if (switch1 == 1)
  {
    digitalWrite(RelayPin1, LOW);
    Serial.println("Device1 ON");
    toggleState_1 = 1;
  }
  else
  {
    digitalWrite(RelayPin1, HIGH);
    Serial.println("Device1 OFF");
    toggleState_1 = 0;
  }
}

void onSwitch2Change() {
  if (switch2 == 1)
  {
    digitalWrite(RelayPin2, LOW);
    Serial.println("Device2 ON");
    toggleState_2 = 1;
  }
  else
  {
    digitalWrite(RelayPin2, HIGH);
    Serial.println("Device2 OFF");
    toggleState_2 = 0;
  }
}

void onSwitch3Change() {
  if (switch3 == 1)
  {
    digitalWrite(RelayPin3, LOW);
    Serial.println("Device3 ON");
    toggleState_3 = 1;
  }
  else
  {
    digitalWrite(RelayPin3, HIGH);
    Serial.println("Device3 OFF");
    toggleState_3 = 0;
  }
}

void onSwitch4Change() {
  if (switch4 == 1)
  {
    digitalWrite(RelayPin4, LOW);
    Serial.println("Device4 ON");
    toggleState_4 = 1;
  }
  else
  {
    digitalWrite(RelayPin4, HIGH);
    Serial.println("Device4 OFF");
    toggleState_4 = 0;
  }
}
 void onSurvoChange()  {
  // Add your code here to act upon Survo change
    myservo.write(survo);
}