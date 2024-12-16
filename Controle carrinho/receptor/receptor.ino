#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>
 
 
byte entrada[8];
 
byte rx_endereco[5] = {0xD0,0xD0,0xD0,0xD0,0xD0};
 
uint32_t lastCommandTime = 0;
 
uint8_t data1, data2, data3, data4, data5, data6;

int motor1 = 3;
int motor2 = 4;
int c =0;
 
void setup()
{
pinMode(motor1, OUTPUT);
pinMode(motor2, OUTPUT);

digitalWrite(motor1, LOW);
digitalWrite(motor2, LOW);
  
  Serial.begin(57600);
  
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
    data3 = ~entrada[4];
    data4 = ~entrada[5];
    data5 = ~entrada[6];
    data6 = ~entrada[7];
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
    Serial.print("Data 3 ==> ");
    Serial.println(data3);
    Serial.print("Data 4 ==> ");
    Serial.println(data4);
    Serial.print("Data 5 ==> ");
    Serial.println(data5);
    Serial.print("Data 6 ==> ");
    Serial.println(data6);
    
    Mirf.flushRx();
    lastCommandTime = millis();

    c = data6;

    if(c == 255){
      digitalWrite(motor1, HIGH);
    }

    else{
      digitalWrite(motor1, LOW);
    }

    if(c == 0){
      digitalWrite(motor2, HIGH);
    }

    else{
      digitalWrite(motor2, LOW);
    }

    
  }
 
  if((millis() - lastCommandTime) > 100)
  {
    
    Mirf.flushRx();
    lastCommandTime = millis();
  }
}
 

