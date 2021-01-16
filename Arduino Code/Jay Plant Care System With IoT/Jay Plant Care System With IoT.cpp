#define BLYNK_PRINT Serial
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

char auth[] = "UuQJaHifpsEw2sQhttNCvlIZ1p4h6zD9";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "JGML WiFi";
char pass[] = "29280720mtjm";

#include <SoftwareSerial.h>
SoftwareSerial EspSerial(2, 3); // RX, TX

// Your ESP8266 baud rate:
#define ESP8266_BAUD 115200                                    

ESP8266 wifi(&EspSerial);

// Humid and temperature sensor
#include <dht11.h>
#include <DHT.h>
#define dht_apin A4 // Analog Pin sensor is connected to
dht11 dhtObject;


int temperature;

int humid;

//Soil Sensor 1&2 Declaration 
int AnalogPin2 = A2; 
int AnalogPin3 = A3; 
int SoilMValue1;
int SoilMValue2; 

//LDR Sensor
unsigned int LDRValue;

BlynkTimer timer;

void sendSensor()
{
  Blynk.virtualWrite(V0, humid);
  Blynk.virtualWrite(V1, temperature);
  Blynk.virtualWrite(V2, SoilMValue1);
  Blynk.virtualWrite(V3, SoilMValue2);
  Blynk.virtualWrite(V4, LDRValue);

}

void setup()
{
  // Debug console
  Serial.begin(9600);

  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Blynk.begin(auth, wifi, ssid, pass);

  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);

  Serial.println("Jay's Plant Care System\n\n");
}

void loop()
{
 // Humidity and temaperature sensor
 //Temperature
 dhtObject.read(dht_apin);//Temperature
 Serial.print("Temperature(C)= ");
 int temp = dhtObject.temperature;
 Serial.println(temp);
 temperature = temp;
 delay(10);


 //Humidity
 dhtObject.read(dht_apin);//Humidity
 Serial.print("Humidity in %=");
 int humidity = dhtObject.humidity;
 Serial.println(humidity);
 humid = humidity;
 delay(10);
 
 //Soil Sensor 1
 SoilMValue1 = analogRead(AnalogPin2); 
 Serial.println("Soiln Humid Value 1: ");
 Serial.println(SoilMValue1);
 delay(10);

 //Soil Sensor 2
 SoilMValue2 = analogRead(AnalogPin3); 
 Serial.println("Soil Humid Value 2: ");
 Serial.println(SoilMValue2);
 delay(10);
 
 //LDR Sensor
 LDRValue = analogRead(A5);
 Serial.println("Light Intensity Value");
 Serial.println(LDRValue);
 Serial.println("\n\n");//Gap
 delay(10);

  Blynk.run();
  timer.run();
   
  return(temperature, humid, SoilMValue1, SoilMValue2,LDRValue);
}