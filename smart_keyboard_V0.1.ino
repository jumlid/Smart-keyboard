#include <WiFi.h>
const char* ssid = "Smart Keyboard";
const int led =2;
void setup() {
pinMode(led,OUTPUT);
  WiFi.softAP(ssid);
  
}

void loop() {
  if (WiFi.softAPgetStationNum() > 0) {
    digitalWrite(led, HIGH);
  }else {
    digitalWrite(led, LOW);
  }

}
