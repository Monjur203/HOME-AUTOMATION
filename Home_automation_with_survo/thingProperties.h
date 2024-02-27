 
#include <ArduinoIoTCloud.h>
 
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

char SSID[32];    // Network SSID (name)
char PASS[63];

void preferredConnectionHandler(char* ssid, char* pass) {
  char SSID[32];    // Network SSID (name)
char PASS[63];
  strcpy(SSID, ssid);
  strcpy(PASS, pass);
}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);