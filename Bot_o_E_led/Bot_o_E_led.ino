// Teste de botão
int bt = 9;
int lVd = 3;
int lAm = 4;
int lVm = 5;
int cont = 0;
int temp =1000;

void setup() {
  // pinMode
  pinMode(bt,INPUT);
  Serial.begin(9600); 
  pinMode(lVd,OUTPUT);
  //pinMode(lAm,OUTPUT);
  pinMode(lVm,OUTPUT);
}

void loop() {
  //digitalWrite
  //int btState = analogRead(A5); 
  int btState = digitalRead(bt); 
 // cont = cont;
Serial.print("btState: ");
 Serial.println(btState);
  
  if(btState == HIGH){ 
    digitalWrite(lVd, HIGH);
    digitalWrite(lVm, LOW);
  }
  else{
    digitalWrite(lVd, LOW);
    digitalWrite(lVm, HIGH); 
  }
     
    //delay(temp);  
}
