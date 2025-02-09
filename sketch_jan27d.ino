#include <OneWire.h>
#include <DallasTemperature.h>

// Number of sensors
#define ONE_WIRE_BUS_COUNT 4

// Sensor pin assignments
int oneWirePins[ONE_WIRE_BUS_COUNT] = {A0, A1, A2, A3};

// Arrays to hold OneWire and DallasTemperature objects
OneWire* oneWire[ONE_WIRE_BUS_COUNT];
DallasTemperature* sensors[ONE_WIRE_BUS_COUNT];

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  
  // Initialize sensors
  for (int i = 0; i < ONE_WIRE_BUS_COUNT; i++) {
    oneWire[i] = new OneWire(oneWirePins[i]);
    sensors[i] = new DallasTemperature(oneWire[i]);
    sensors[i]->begin();
  }
}

void loop() {
  // Request temperature readings
  for (int i = 0; i < ONE_WIRE_BUS_COUNT; i++) {
    sensors[i]->requestTemperatures();
  }

  // Read and transmit temperature data
  for (int i = 0; i < ONE_WIRE_BUS_COUNT; i++) {
    float temp = sensors[i]->getTempCByIndex(0);
    
    // Send data with labels
    if (i == 0) {
      Serial.print("AirIn:");
    } else if (i == 1) {
      Serial.print("AirRadiator:");
    } else if (i == 2) {
      Serial.print("AirCase:");
    } else if (i == 3) {
      Serial.print("AirPowerSupply:");
    }
    Serial.print(temp);
    
    // Format output
    if (i != ONE_WIRE_BUS_COUNT - 1) {
      Serial.print("\t");
    } else {
      Serial.println();
    }
  }

  delay(1000);  // Wait 1 second before next loop
}
