// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID           ""
#define BLYNK_DEVICE_NAME           ""
#define BLYNK_AUTH_TOKEN            ""


// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

BlynkTimer timer;
char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "";
char pass[] = "";


int flag = 0;

void notifyOnFire()
{
  double tempValue = analogRead(A0);
  Serial.println(tempValue);
  if (tempValue>800 && flag == 0) {
    Serial.println("Fire in the House");
    Blynk.logEvent("fire","Alert : Fire in the House");
    flag=1;
  }else if(tempValue<800){
     flag = 0;
  }
}

void setup()
{  
  // Debug console
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
  
  timer.setInterval(1000L,notifyOnFire); 
}

void loop()
{
  Blynk.run();
  timer.run();
}
