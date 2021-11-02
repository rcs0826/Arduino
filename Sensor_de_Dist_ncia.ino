int HC_SR04Trigger = 6;
int HC_SR04Echo =7;
int distancia = 0;
int tiempo = 0;
int ledVer = 9;
int ledAma = 10;
int ledVed = 11;

void setup() {
  pinMode(HC_SR04Trigger, OUTPUT);
  pinMode(HC_SR04Echo, INPUT);
  pinMode(ledVer, OUTPUT);
  pinMode(ledAma, OUTPUT);
  pinMode(ledVed, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  digitalWrite(HC_SR04Trigger,LOW); //Estabilizamos el sensor
  delayMicroseconds(2);
  digitalWrite(HC_SR04Trigger, HIGH); //Se envia un pulso ultrasonico
  delayMicroseconds(10); 
  tiempo = pulseIn(HC_SR04Echo, HIGH);/* Función para medir la longitud del pulso entrante. Mide el tiempo que transcurrido entre el envío
  del pulso ultrasónico y cuando el sensor recibe el rebote, es decir: desde que el pin 12 empieza a recibir el rebote, HIGH, hasta que
  deja de hacerlo, LOW, la longitud del pulso entrante*/
  distancia = int(tiempo*0.017);
  Serial.print(distancia);
  Serial.println("cm");
  
  if(distancia >= 80){    
    digitalWrite(ledVer, LOW);
    digitalWrite(ledAma, LOW);
    digitalWrite(ledVed, HIGH);
  }
  
  else if(distancia <= 30){
    digitalWrite(ledVer, HIGH);
    digitalWrite(ledAma, LOW);
    digitalWrite(ledVed, LOW);
  }
  else{    
    digitalWrite(ledVer, LOW);
    digitalWrite(ledAma, HIGH);
    digitalWrite(ledVed, LOW);
  }
    
  
}
/* Com o sensor de frente, segue a sequencia
 *  1) 5V - VCC
 *  2) pino 6 - TRIG
 *  3) pino 7 - ECHO
 *  4) Terra - GND

*/
