int ledPin = 13; // Usaremos el pin 13 para el LED
char option;
unsigned long previousMillis = 0; // Variable para el temporizador
const long interval500ms = 500; // Intervalo de 500ms
const long interval1000ms = 1000; // Intervalo de 1000ms (1 segundo)
bool blinking500ms = false; // Estado para el parpadeo a 500ms
bool blinking1000ms = false; // Estado para el parpadeo a 1000ms
bool ledState = LOW; // Estado actual del LED

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  mostrarMenu(); // Mostramos el menú al iniciar
}

void loop() {
  if (Serial.available() > 0) {
    option = Serial.read();

    switch (option) {
      case '1':
        blinking500ms = false;
        blinking1000ms = false;
        digitalWrite(ledPin, HIGH);
        Serial.println("LED encendido.");
        break;

      case '2':
        blinking500ms = false;
        blinking1000ms = false;
        digitalWrite(ledPin, LOW);
        Serial.println("LED apagado.");
        break;

      case '3':
        blinking500ms = true;
        blinking1000ms = false;
        Serial.println("LED en modo intermitente a 500ms.");
        break;

      case '4':
        blinking500ms = false;
        blinking1000ms = true;
        Serial.println("LED en modo intermitente a 1000ms.");
        break;

      default:
        Serial.println("Opción inválida. Por favor elige entre 1, 2, 3 o 4.");
        break;
    }

    mostrarMenu(); // Mostramos el menú después de cada instrucción
  }

  // Gestionar el modo intermitente a 500ms
  if (blinking500ms) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval500ms) {
      previousMillis = currentMillis;
      ledState = !ledState; // Cambiar el estado del LED
      digitalWrite(ledPin, ledState);
    }
  }

  // Gestionar el modo intermitente a 1000ms
  if (blinking1000ms) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval1000ms) {
      previousMillis = currentMillis;
      ledState = !ledState; // Cambiar el estado del LED
      digitalWrite(ledPin, ledState);
    }
  }
}

// Función para mostrar el menú
void mostrarMenu() {
  Serial.println("- Menú -");
  Serial.println("{1}. Encender LED");
  Serial.println("{2}. Apagar LED");
  Serial.println("{3}. LED en modo intermitente a 500ms");
  Serial.println("{4}. LED en modo intermitente a 1000ms");
}
