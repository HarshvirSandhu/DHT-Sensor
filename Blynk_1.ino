#define BLYNK_PRINT Serial
#include<DHT.h>
#include<BlynkSimpleEsp8266.h>
DHT sensor(D1, DHT11);
char ssid[] = " "; //Netword SSID
char pass[] = " "; //WiFi Password
char auth[] = " "; //Authentication code
float hum, temp;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  // put your main code here, to run repeatedly:
  hum = sensor.readHumidity();
  temp = sensor.readTemperature();
  Serial.println(hum);
  Blynk.run();
  Blynk.virtualWrite(V0,hum);
  delay(200);

}
