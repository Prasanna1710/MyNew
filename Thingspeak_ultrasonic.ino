#include<WiFi.h>
#include "ThingSpeak.h"
#define ECHO 22
#define TRIGG 23
#define CHANNEL_ID 1944780
#define WRITE_API "N7C8GIM1C8668HX4"


float duration;
float distance;
const char* ssid = "Prasanna";
const char* password = "cricket0";
int counter = 0;

WiFiClient client;


void setup() {
  Serial.begin(9600);
  delay(10);
  Serial.println("\n");

  WiFi.begin(ssid, password);
  Serial.print("Connecting to");
  Serial.print(ssid); 

  pinMode(TRIGG, OUTPUT);
  pinMode(ECHO, INPUT);

  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }

  Serial.println("\n");
  Serial.println("Connection established");
  Serial.println(WiFi.localIP());

  ThingSpeak.begin(client);

}

void loop() {
  digitalWrite(TRIGG, LOW);
  delay(10);
  digitalWrite(TRIGG, HIGH);
  delay(10);
  digitalWrite(TRIGG, LOW);

  duration = pulseIn(ECHO, HIGH);
  distance = duration*0.017;

  Serial.print("distance = ");
  Serial.print(distance);
  Serial.print("cm");
  Serial.println("");

  ThingSpeak.writeField(CHANNEL_ID, 1, distance, WRITE_API);

  delay(15000);


}
