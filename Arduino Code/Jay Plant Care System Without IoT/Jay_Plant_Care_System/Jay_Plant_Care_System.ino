// Humid and temperature sensor
#include <dht11.h>
#include <DHT.h>
#define dht_apin A4 // Analog Pin sensor is connected to
dht11 dhtObject;

//Soil Sensor 1&2 Declaration 
int AnalogPin2 = A2; 
int AnalogPin3 = A3; 
int SoilMValue1;
int SoilMValue2; 



void setup() 
{

 Serial.begin(9600);

 //Humid and temperature sensor
 delay(500);//Delay to let system boot
 Serial.println("Jay's Plant Care System\n\n");
 delay(1000);//Wait before accessing Sensor

}



void loop() 
{

// Humidity and temaperature sensor
//Temperature
dhtObject.read(dht_apin);
Serial.print("Temperature(C)= ");
int temp = dhtObject.temperature;
Serial.println(temp);
//Humidity
dhtObject.read(dht_apin);
Serial.print("Humidity in %=");
int humidity = dhtObject.humidity;
Serial.println(humidity);

//Soil Sensor 1
 SoilMValue1 = analogRead(AnalogPin2); 
 Serial.println("Soiln Humid Value 1: ");
 Serial.println(SoilMValue1);

//Soil Sensor 2
 SoilMValue2 = analogRead(AnalogPin3); 
 Serial.println("Soil Humid Value 2: ");
 Serial.println(SoilMValue2);
 
//LDR Sensor
 unsigned int LDRValue;
 LDRValue = analogRead(A5);
 Serial.println("Light Intensity Value");
 Serial.println(LDRValue);
 Serial.println("\n\n");//Gap
 
 delay(3000); 

}
