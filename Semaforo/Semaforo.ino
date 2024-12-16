//  Tutorial #3 - Semáforo
 
//  Declaração de Variáveis do Pinos dos LEDs
int Vermelho = 12;  //Declara o pino 12 para o LED Vermelho
int Amarelo = 8;    //Declara o pino 8 para o LED Amarelo
int Verde = 4;      //Declara o pino 4 para o LED Verde
 
// Função de Configuração
void setup(){
  pinMode(Vermelho, OUTPUT);    //Define o pino Vermelho como de Saída
  pinMode(Amarelo, OUTPUT);     //Define o pino Amarelo como de Saída
  pinMode(Verde, OUTPUT);       //Define o pino Verde como de Saída   
}
 
// Função de Repetição
void loop(){
  digitalWrite(Vermelho, HIGH);  //Liga o LED Vermelho
  digitalWrite(Amarelo, LOW);    //Desliga o LED Amarelo
  digitalWrite(Verde, LOW);      //Desliga o LED Verde
  delay(5000);                   //Atraso de 5 segundos (5000 milisegundos)
 
  digitalWrite(Vermelho, LOW);   //Desliga o LED Vermelho
  digitalWrite(Amarelo, LOW);    //Desliga o LED Amarelo
  digitalWrite(Verde, HIGH);     //Liga o LED Verde
  delay(5000);                   //Atraso de 5 segundos (5000 milisegundos)
 
  digitalWrite(Vermelho, LOW);   //Desliga o LED Vermelho
  digitalWrite(Amarelo, HIGH);   //Liga o LED Amarelo
  digitalWrite(Verde, LOW);      //Desliga o LED Verde
  delay(1000);                   //Atraso de 1 segundo (1000 milisegundos)
}
