#include <ArduinoHttpClient.h>

#include<ESP8266WiFi.h>
#include<Adafruit_MQTT_Client.h>



int val=0;
int inputPin= 17 ; 
#define wifi "Soha" 
#define password "alohomora"
#define server "io.adafruit.com"
#define port 1883
#define user "Shahidhar Dalal"
#define pass "Vraj@Adafruit"
#define key "38166731a75c44c4bf0a9c825e5b673f"


//WiFiServer server(80);
WiFiClient esp;

Adafruit_MQTT_Client mqtt(&esp,server,port,user,key);

Adafruit_MQTT_Publish feed1= Adafruit_MQTT_Publish(&mqtt,user "/feeds/TiltSwitch");

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(10);
  Serial.println(wifi);

  WiFi.begin(wifi,password);
  Serial.print("Connecting");
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

Serial.println("WiFi connected");
Serial.println("IP Address:");
Serial.println(WiFi.localIP());
Serial.println("Connecting to MQTT");
while(mqtt.connect())
  Serial.print(".");
   pinMode(inputPin, INPUT); 
}

void loop() {

 val=analogRead(inputPin);
 Serial.println(val);

  // put your main code here, to run repeatedly:
if(mqtt.connected())
{
  if(feed1.publish(val))
    Serial.println("Success");
  else
    Serial.println("Fail!!");
  delay(1000);
}

}

