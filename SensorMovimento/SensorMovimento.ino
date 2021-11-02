int led = 3;
int sen = 2;
int qtd = 0;
boolean cont = true;


void setup() {
  pinMode(led, OUTPUT);
  pinMode(sen, INPUT);  
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(sen)){
    if(cont == true){
      qtd++;
      cont = false;
    }    
    delay(500);
  }
  else{    
    cont = true;
    delay(500);
  }
  digitalWrite(led,!cont);
  Serial.print("Qtd: ");
  Serial.println(qtd);  
   
  delay(10);
}
