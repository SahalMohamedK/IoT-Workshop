#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#ifndef APSSID
#define APSSID "Iot Workshop"
#define APPSK  "sahalmohamed"
#endif

/* Set these to your desired credentials. */
const char *ssid = APSSID;
const char *password = APPSK;

ESP8266WebServer server(80);

int ledPin = 13;

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

void setup() {
  pinMode(ledPin, OUTPUT);
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", root);
  server.on("/led-on", ledOn);
  server.on("/led-off", ledOff);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
