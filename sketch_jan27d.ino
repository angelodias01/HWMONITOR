#include <OneWire.h>
#include <DallasTemperature.h>

// Define os pinos dos sensores
const int sensorPins[] = {A0, A1, A2, A3};
const char* sensorNomes[] = {
    "Entrada de Ar", 
    "Radiador", 
    "Caixa", 
    "Fonte de Alimentação"
};
const int numSensores = sizeof(sensorPins) / sizeof(sensorPins[0]);

// Objetos OneWire e DallasTemperature
OneWire* oneWire[numSensores];
DallasTemperature* sensores[numSensores];

void setup() {
    Serial.begin(9600);
    
    // Inicializa os sensores
    for (int i = 0; i < numSensores; i++) {
        oneWire[i] = new OneWire(sensorPins[i]);
        sensores[i] = new DallasTemperature(oneWire[i]);
        sensores[i]->begin();
    }
}

void loop() {
    Serial.println("\nLendo temperaturas...");

    // Solicita a leitura de todos os sensores
    for (int i = 0; i < numSensores; i++) {
        sensores[i]->requestTemperatures();
    }

    // Lê e imprime as temperaturas
    for (int i = 0; i < numSensores; i++) {
        float temperatura = sensores[i]->getTempCByIndex(0);

        // Verifica se a leitura é válida
        Serial.print(sensorNomes[i]);
        Serial.print(": ");

        if (temperatura == DEVICE_DISCONNECTED_C) {
            Serial.println("ERRO (Sensor desconectado)");
        } else {
            Serial.print(temperatura);
            Serial.println(" °C");
        }
    }

    Serial.println("----------------------");
    delay(2000);
}
