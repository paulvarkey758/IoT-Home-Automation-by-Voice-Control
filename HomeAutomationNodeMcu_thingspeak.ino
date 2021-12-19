#include "ThingSpeak.h"
#include <ESP8266WiFi.h>

//Replace your wifi credentials here
const char* ssid     = "MyWiFi";//Replace with your Wifi Name
const char* password = "12345678";// Replace with your wifi Password

//change your channel number here
unsigned long channel =1605380;//Replace with your own ThingSpeak Account Channle ID

//1,2 and 3 are channel fields.
unsigned int Light1 = 1;
unsigned int Light2 = 2;
unsigned int Fan = 3;

WiFiClient  client;


void setup() {
  Serial.begin(115200);
  delay(100);
  
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D8, OUTPUT);
  digitalWrite(D5, 0);
  digitalWrite(D6, 0);
  digitalWrite(D7, 0);
  // We start by connecting to a WiFi network
 
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Netmask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());
  ThingSpeak.begin(client);

}

void loop() {
 
  //get the last data of the fields
  int light_1 = ThingSpeak.readFloatField(channel, Light1);
  int light_2 = ThingSpeak.readFloatField(channel, Light2);
  int fan = ThingSpeak.readFloatField(channel, Fan);
 
  if(light_1 == 1){
    digitalWrite(D5, HIGH);
    Serial.println("Light 1 is On..!");
  }
  else if(light_1 == 0){
    digitalWrite(D5, LOW);
    Serial.println("Light 1 is Off..!");
  }
 
  if(light_2 == 1){
    digitalWrite(D6, HIGH);
    Serial.println("Light 2 is On..!");
  }
  else if(lIGHT_2 == 0){
    digitalWrite(D6, LOW);
    Serial.println("Light 2 is Off..!");
  }
 
  if(fan == 1){
    digitalWrite(D7, HIGH);
    digitalWrite(D8, LOW);
    Serial.println("Fan is On..!");
  }
  else if(fan == 0){
    digitalWrite(D7, LOW);
    digitalWrite(D8, LOW);
    Serial.println("Fan is Off..!");
  }
    
  Serial.println(light_1);
  Serial.println(light_2);
  //Serial.println(fan);
  delay(5000);
 
}
