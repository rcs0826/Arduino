/*
  Mapeamentos dos pinos
    Potenciometro A0 = Cabo Marrom
    Garra         3  = Outro Cabo Marrom
    Braço (E)     5  = Cabo Laranja
    Braço (D)     6  = Cabo Roxo
    Mesa          9  = Cabo Branco
  Alimentação
    Vermelo = 5V
    Preto   = GND
*/
#include <Servo.h> //INCLUSÃO DA BIBLIOTECA NECESSÁRIA

const int pinoServo = 6; //PINO DIGITAL UTILIZADO PELO SERVO  
const int pinoMesa = 9;
const int pinoGarra = 3;
Servo garras; //OBJETO DO TIPO SERVO
Servo mesa;

int potencio = A0; // Inicializa o pino analógico para o potenciômetro
int angulo = 0;
void setup (){
  pinMode(potencio,INPUT);
  Serial.begin(9600);
  mesa.attach(pinoMesa);
  garras.attach(pinoGarra);
  //garras.write(0);  
  mesa.write(10);
  //delay(1000); 
  Serial.println("Inicio");
}
void loop(){
  angulo = analogRead(potencio); // Faz a leitura do valor do potenciômetro
  angulo = map(angulo, 0, 1023, 0, 179); // Associa o valor do potenciômetro ao valor do ângulo
  Serial.println(angulo); 
  mesa.write(100);
  //delay(20);
  // Limite da garra para fechar 30
  if(angulo > 30){
        angulo = 30;
  }  
  garras.write(angulo);
  //garras.write(10);
  //s.write(40);
}