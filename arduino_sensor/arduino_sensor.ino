#include <DHT.h>

#define DHTPIN 2      // Pin digital donde está conectado el sensor DHT11
#define DHTTYPE DHT11  // Tipo de sensor DHT

DHT dht(DHTPIN, DHTTYPE); // Inicialización del sensor

void setup() {
  Serial.begin(9600);
  Serial.println("Inicializando sensor DHT11...");
  dht.begin();
}

void loop() {
  delay(2000); // Esperar 2 segundos entre mediciones

  float temperatura = dht.readTemperature(); // Leer temperatura en Celsius
  float humedad = dht.readHumidity();       // Leer humedad

  // Comprobar si la lectura es válida
  if (isnan(temperatura) || isnan(humedad)) {
    Serial.println("Error al leer el sensor DHT11. Verifica las conexiones.");
  } else {
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.println(" °C");

    Serial.print("Humedad: ");
    Serial.print(humedad);
    Serial.println(" %");
  }
}

