#include <WiFi.h>
#include <WebServer.h>
const char* ssid = "Smart Keyboard";
const int led = 2;
const int keyboard = 15;
 bool mode_3 = false;
WebServer server(80);  // this line open a server in port 80
void setup() {
  pinMode(led, OUTPUT);
  pinMode(keyboard, OUTPUT);
  WiFi.softAP(ssid);  // This method is use to create a wifi network it uses two parameter (ssid,password) SSID refer to the network name and password while password can be emty for no password
  server.on("/", []() {
    server.send(200, "text/html", R"rawliteral(<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <div class="container">
        <div class="box">
            <h1>Smart Keyboard</h1>
            <div class="button">
                <button onclick="Mode_1()">Mode 1</button>
                <button onclick="Mode_2()">Mode 2</button> <br>
                <button onclick="Mode_3()">Mode 3</button>
            </div>
        </div>

        <style>
            * {
                margin: 0%;
                padding: 0%;
                color: white;
            }

            .container {
                background-color: rgba(12, 12, 12, 0.988);
              
                height: 100vh;
                display: flex;
                justify-content: center;
                align-items: center;
            }

            .box {
                background-color: rgba(12, 12, 12, 0.988);
                text-align: center;
                padding: 20px;
                height: fit-content;
                width: fit-content;

            }

            .button {
                margin-top: 50px;
               
                height: fit-content;
            }

            button {
                border-radius: 15px;
                border: none;
                cursor: pointer;
                width: 100px;
                height: 100px;
                margin: 20px;
                background-color: rgb(255, 0, 51);
            }
        </style>
        <script>
            function Mode_1() {
                fetch("Mode_1")
                .then(()=>{})
                .then(data=>{

                })
                
            }
            function Mode_2() {
                 fetch("Mode_2")
                .then(()=>{})
                .then(data=>{
                    
                })
                
            }
            function Mode_3() {
                 fetch("Mode_3")
                .then(()=>{})
                .then(data=>{
                    
                })
                
            }
        </script>

</body>

</html>
    )rawliteral");
  });
  server.on("/Mode_1", []() {
    mode_3 = false;
    digitalWrite(led, HIGH);
    digitalWrite(keyboard, HIGH);
    server.send(200, "text/plain", "LED is ON");
  });

  server.on("/Mode_2", []() {
    mode_3 = false;
    digitalWrite(led, LOW);
    digitalWrite(keyboard, LOW);
    server.send(200, "text/plain", "LED is OFF");
  });
  server.on("/Mode_3", []() {
    mode_3 = true;
    server.send(200, "text/plain", "LED is OFF");
  });

  server.begin();
}

void loop() {
  if (mode_3) {
    digitalWrite(keyboard, HIGH);
    delay(500);
    digitalWrite(keyboard, LOW);
  }
  server.handleClient();
}
