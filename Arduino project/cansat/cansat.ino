#include <SimpleDHT.h>
#include <jsdhbfj.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>

int pinDHT11 = 2;
Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);


void displaySensorDetails(void)
{
  sensor_t sensor;
  bmp.getSensor(&sensor);
  Serial.println("----------Space development nexus satellite miniature----Lets bring Space down to Earth--------------");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" hPa");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" hPa");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" hPa");  
  Serial.println("----------SDNx real time scientific data---------------");
  Serial.println("");
  delay(500);
}

void setup() {
  Serial.begin(115200);
  Serial.begin(9600);
  Serial.println("Pressure Sensor Test"); Serial.println("");
  if(!bmp.begin())
  {
    /* There was a problem detecting the BMP085 ... check your connections */
    Serial.print(" SDNx says Ooops, no BMP085 detected ... Check your circuit some errors are there!");
    while(1);
  }
  
  /* Display some basic information on this sensor */
  displaySensorDetails();

}

void loop() {
  
  Serial.println("=======Space Development Nexus satellite miniature===real time scientific data====");
  Serial.println("Sample DHT11...");
  
 
  byte temperature = 0;
  byte humidity = 0;
  byte data[40] = {0};
  if (simple_dht11_read(pinDHT11, &temperature, &humidity, data)) {
    Serial.print("Read DHT11 failed");
    return;
  }
  
  Serial.print("Sample RAW Bits: ");
  simple_dht11_serial_print(data);
  
  Serial.print("SDNx says you are genius and every thing is OK: ");
  Serial.print((int)temperature); Serial.print(" *C, ");
  Serial.print((int)humidity); Serial.println(" %");
  
  // DHT11 sampling rate is 1HZ.
  delay(1000);

  sensors_event_t event;
  bmp.getEvent(&event);
 
  if (event.pressure)
  {
   
    Serial.print("Pressure:    ");
    Serial.print(event.pressure);
    Serial.println(" hPa");
    
    
    float temperature;
    bmp.getTemperature(&temperature);
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");

    
    float seaLevelPressure = SENSORS_PRESSURE_SEALEVELHPA;
    Serial.print("Altitude:    "); 
    Serial.print(bmp.pressureToAltitude(seaLevelPressure,
                                        event.pressure)); 
    Serial.println(" m");
    Serial.println("");
  }
  else
  {
    Serial.println("Sensor error");
  }
  delay(1000);
}

