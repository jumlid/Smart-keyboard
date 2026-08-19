#include <WiFi.h>
#include <WebServer.h>
const char* ssid = "Smart Keyboard";
const int led = 2;
WebServer server(80);  // this line open a server in port 80
void setup() {
  pinMode(led, OUTPUT);
  WiFi.softAP(ssid);  // This method is use to create a wifi network it uses two parameter (ssid,password) SSID refer to the network name and password while password can be emty for no password
  server.on("/", []() {
    server.send(200, "text/html", R"rawliteral(
      <!DOCTYPE html>
      <html>
      <head>
        <title>ESP32</title>
      </head>
      <body>
        <h1>Hello from ESP32!</h1>
        <button onclick="turnOn()">ON</button>
           <button onclick="turnOff()">OFF</button>
         <script>
        function turnOn() {
            fetch("Mode1")
                .then(response => response.text())
                .then(data => {
                    console.log(data);
                });
        }

        function turnOff() {
            fetch("/Mode2")
                .then(response => response.text())
                .then(data => {
                });
        }
    </script>
      </body>
      </html>
    )rawliteral");
  });
  server.on("/Mode1", []() {
    digitalWrite(led, HIGH);
    server.send(200, "text/plain", "LED is ON");
  });

server.on("/Mode2", []() {
  digitalWrite(led, LOW);
  server.send(200, "text/plain", "LED is OFF");
});
server.begin();
}

void loop() {
  server.handleClient();
}
