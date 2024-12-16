/*********************************************************
****************  Mapeamento dos pinos  ******************
**********************************************************
* Cartão SD  X Arduino
* 1) CS  : pino 10
* 2) SDK : pino 13
* 3) MOSI: pino 11
* 4) MISO: pino 12
* 5) VCC : pino 5V
* 6) GND : pino GND
**********************************************************/
#include <SPI.h> //INCLUSÃO DE BIBLIOTECA
#include <SD.h> //INCLUSÃO DE BIBLIOTECA
 
const int chipSelect = 10; //PINO DIGITAL UTILIZADO PELO TERMINAL CS DO MÓDULO
 
void setup(){
  Serial.begin(9600); //INICIALIZA A SERIAL
   while(!Serial){ //ESPERA PELA CONEXÃO DA PORTA SERIAL (APENAS PARA O ARDUINO LEONARDO)
    ;
  }
  Serial.println("Inicializando o cartão de memória..."); //IMPRIME O TEXTO NO MONITOR SERIAL
  Serial.println("********************************************"); //IMPRIME NO MONITOR SERIAL
  pinMode(SS, OUTPUT); //DEFINE O PINO COMO SAÍDA
  
  if(!SD.begin(chipSelect)){ //SE O CARTÃO DE MEMÓRIA NÃO ESTIVER PRESENTE OU FALHAR, FAZ
    Serial.println("Cartão de memória falhou ou não está presente!"); //IMPRIME O TEXTO NO MONITOR SERIAL
    return; //NÃO FAZ MAIS NADA
  }
  Serial.println("Cartão de memória inicializado com sucesso!"); //IMPRIME O TEXTO NO MONITOR SERIAL
  Serial.println("********************************************"); //IMPRIME NO MONITOR SERIAL
  Serial.println("Mensagem do arquivo de texto que está no cartão de memória:"); //IMPRIME O TEXTO NO MONITOR SERIAL
  Serial.println(); //QUEBRA DE LINHA NO MONITOR SERIAL
   
  SDFile dataFile = SD.open("arquivo.txt"); //dataFile RECEBE O CONTEÚDO DO ARQUIVO DE TEXTO (ABRIR UM ARQUIVO POR VEZ)
 
  if(dataFile){ //SE EXISTIREM DADOS A SEREM LIDOS, FAZ
    while(dataFile.available()){ //ENQUANTO HOUVER CONTEÚDO A SER LIDO, FAZ
      Serial.write(dataFile.read()); //ESCREVE NA SERIAL AS INFORMAÇÕES DO ARQUIVO DE TEXTO
    }
    dataFile.close(); //ENCERRA A LEITURA (SEMPRE FECHAR O ARQUIVO ATUAL PARA ABRIR UM OUTRO ARQUIVO)
  }
  else{ //SENÃO, FAZ
    Serial.println("Erro ao abrir o arquivo!"); //IMPRIME O TEXTO NO MONITOR SERIAL
  } 
}
void loop(){
}
