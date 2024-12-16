#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>
 
 
byte entrada[8];
 
byte rx_endereco[5] = {0xD0,0xD0,0xD0,0xD0,0xD0};
 
uint32_t lastCommandTime = 0;
 
uint8_t data1, data2, data3;
 
void setup()
{
 
 
  Serial.begin(57600);
 
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
  
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  Mirf.setRADDR(rx_endereco);
  Mirf.payload = 8;
  Mirf.config();
}
 
void loop()
{
  if(!Mirf.isSending() && Mirf.dataReady())
  {
    Mirf.getData(entrada);
    
    data1 = ~entrada[2];
    data2 = ~entrada[3];
        /*    data 1
     * 1 = Seta para esquerda / analogico L para esquerda
     * 2 = Seta para baixo / analogico L para baixo
     * 4 = seta para direita / analogico L para direita
     * 8 = seta para cima / analogico L para cima
    */
    /*   data 2
     * 1 = [] / analogico R para esquerda 
     * 2 = X / analogico R para baixo 
     * 4 = O / analogico R para direita 
     * 8 = /\ / analogico R para cima 
     * 16 = R1
     * 32 = L1
     * 64 = R2
     * 128 = L2
    */
    
    Serial.print("Data 1 ==> ");
    Serial.println(data1);
    Serial.print("Data 2 ==> ");
    Serial.println(data2);
    

    if( data1 == 8){
      digitalWrite(4,HIGH);
    }
    if (data1 == 2){
      digitalWrite(4,LOW);
    }
    if( data1 == 4){
      digitalWrite(3,HIGH);
    }
    if (data1 == 1){
      digitalWrite(3,LOW);
    }
 
   
    Mirf.flushRx();
    lastCommandTime = millis();
  }
 
  if((millis() - lastCommandTime) > 100)
  {
    
    Mirf.flushRx();
    lastCommandTime = millis();
  }
}
 

