// Sketch Hello.ino 

int const LED = 13;

void setup(){
  pinMode(LED, OUTPUT);
  Serial.begin(9600);  //Baudios
  digitalWrite(LED, LOW);
  Serial.print("Hello");

}

void loop(){

}
