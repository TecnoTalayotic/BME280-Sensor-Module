/*Sensor BME280
En este programa configuraremos el sensor BME280
para leer los datos en el terminal serie. 
Creado por Adafruit
Modificado por TecnoTalayotic
https://www.instagram.com/tecnotalayotic
https://www.thingiverse.com/TecnoTalayotic
https://github.com/TecnoTalayotic
Más información del proyecto en:
https://github.com/TecnoTalayotic/BME280-Sensor-Module
*/

#include <Wire.h>
#include <SPI.h>

#include <Adafruit_BME280.h>

Adafruit_BME280 bme; // use I2C interface
Adafruit_Sensor *bme_temp = bme.getTemperatureSensor();
Adafruit_Sensor *bme_pressure = bme.getPressureSensor();
Adafruit_Sensor *bme_humidity = bme.getHumiditySensor();

int conta = 0;

void setup() {
  Serial.begin(9600);
  inici();

  if (!bme.begin()) {
    Serial.println(F("Error sensor BME280"));
    while (1) delay(10);
  }
  
  bme_temp->printSensorDetails();
  bme_pressure->printSensorDetails();
  bme_humidity->printSensorDetails();
}

void loop() {
  conta++;
  delay(1000);
  if (conta = 10000){
    temp();
    conta=0;
  }
}

//Imprimimos Iniciando y una línea de puntos
void inici(){
  Serial.println("Iniciando");
  delay(100);
  Serial.print(" . ");
  delay(100);
  Serial.print(" . ");
  delay(100);
  Serial.print(" . ");
  delay(100);
  Serial.print(" . ");
  delay(100);
  Serial.print(" . ");
  delay(100);
  Serial.print(" . ");
  delay(100);
  Serial.print(" . ");
  delay(100);
  Serial.print(" . ");
  delay(100);
  Serial.print(" . ");
  delay(100);
  Serial.print(" . ");
  delay(100);
  Serial.print(" . ");
  delay(100);
  Serial.println(" . ");
  delay(100);
}

void temp(){
  sensors_event_t temp_event, pressure_event, humidity_event;
  bme_temp->getEvent(&temp_event);
  bme_pressure->getEvent(&pressure_event);
  bme_humidity->getEvent(&humidity_event);
  
  Serial.print(F("Temperatura = "));
  Serial.print(temp_event.temperature);
  Serial.println(" *C");

  Serial.print(F("Humitat = "));
  Serial.print(humidity_event.relative_humidity);
  Serial.println(" %");

  Serial.print(F("Pressió = "));
  Serial.print(pressure_event.pressure);
  Serial.println(" hPa");

  Serial.println();
}
