/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID ""
#define BLYNK_DEVICE_NAME ""
#define BLYNK_AUTH_TOKEN "="


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "";
char pass[] = "";

//this fuction will execute on change in the vertual pin V0
BLYNK_WRITE(V0){
  //read vertual pin V0's values
  int pinValue = param.asInt();
  //write the value into digital pin 2 
  digitalWrite(2, pinValue);
}

void setup()
{
  //configure pin 2 as output
  pinMode(2, OUTPUT);
  
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}
