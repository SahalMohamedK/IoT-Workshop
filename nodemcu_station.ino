#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#ifndef STASSID
#define STASSID ""
#define STAPSK  ""
#endif

const char* ssid = STASSID;
const char* password = STAPSK;
int ledPin = 13;

ESP8266WebServer server(80);

void root() {
  server.send(200, "text/html", "<h1><a href='/led-on'>LED ON</a><br><br><a href='/led-off'>LED OFF</a></h1>");
}

void ledOn() {
  digitalWrite(ledPin, HIGH);
  server.send(200, "text/html", "<h1><a href='/led-on'>LED ON</a><br><br><a href='/led-off'>LED OFF</a></h1>");
}

void ledOff() {
  digitalWrite(ledPin, LOW);
  server.send(200, "text/html", "<h1><a href='/led-on'>LED ON</a><br><br><a href='/led-off'>LED OFF</a></h1>");
}

void setup(void) {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", root);
  server.on("/led-on", ledOn);
  server.on("/led-off", ledOff);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
}
