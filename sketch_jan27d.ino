#include <OneWire.h>
#include <DallasTemperature.h>

// Define the sensor pins
const int sensorPins[] = {A0, A1, A2, A3};
const char* sensorNames[] = {
    "Air Intake", 
    "Radiator", 
    "Enclosure", 
    "Power Supply"
};
const int numSensors = sizeof(sensorPins) / sizeof(sensorPins[0]);

// OneWire and DallasTemperature objects for each sensor
OneWire* oneWire[numSensors];
DallasTemperature* sensors[numSensors];

void setup() {
    Serial.begin(9600);

    // Initialize sensors
    for (int i = 0; i < numSensors; i++) {
        oneWire[i] = new OneWire(sensorPins[i]);
        sensors[i] = new DallasTemperature(oneWire[i]);
        sensors[i]->begin();
    }
}

void loop() {
    Serial.println("\nReading temperatures...");

    // Request temperature readings from all sensors
    for (int i = 0; i < numSensors; i++) {
        sensors[i]->requestTemperatures();
    }

    // Read and print temperatures
    for (int i = 0; i < numSensors; i++) {
        float temperature = sensors[i]->getTempCByIndex(0);

        Serial.print(sensorNames[i]);
        Serial.print(": ");

        // Check if the reading is valid
        if (temperature == DEVICE_DISCONNECTED_C) {
            Serial.println("ERROR (Sensor Disconnected)");
        } else {
            Serial.print(temperature);
            Serial.println(" °C");
        }
    }

    Serial.println("----------------------");
    delay(2000); // Wait before the next reading cycle
}
