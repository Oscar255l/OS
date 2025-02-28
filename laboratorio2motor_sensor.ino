const int led=13;
const int motor = 12;
float temp;
int sensorValue;

void setup(){
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
  Serial.println("Temperature monitor ###"); 
}

void loop(){
  sensorValue = analogRead(A0);
  Serial.print("Sensor value:");
  Serial.println(sensorValue);
  delay(2000);
  temp = (sensorValue * (500.0 / 1023.0))-50.0;
  Serial.print("Temp value:");
  Serial.println(temp);
  
  
  if (temp > 25) { 
    digitalWrite(led, HIGH);
    digitalWrite(motor, HIGH);
    Serial.println("temperatura alta: LED y motor encendidos...");
  } 
  else if (temp < 5) {  
    digitalWrite(motor, LOW);
    Serial.println("Temperatura baja: LED parpadeando...");
    
    digitalWrite(led, HIGH);
    delay(5);
    digitalWrite(led, LOW);
    delay(5);
  } 
  else { 
    digitalWrite(led, LOW);
    digitalWrite(motor, LOW);
    Serial.println("Temperatura entre 6°C y 25°C: LED y motor apagados.");
  }

  delay(2000); // Esperar 2 segundos antes de la siguiente lectura
}