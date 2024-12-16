#include <Psx.h>
#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>

#define dataPin 4
#define cmndPin 3
#define attPin 2
#define clockPin 5

Psx Psx;

byte envio[8];
byte tx_endereco[5] = {0xD0,0xD0,0xD0,0xD0,0xD0};

void setup()
{
	Serial.begin(57600);
	Psx.setupPins(dataPin, cmndPin, attPin, clockPin, 10);

	Mirf.spi = &MirfHardwareSpi;
	Mirf.init();
	Mirf.payload = 8;
	Mirf.config();
}

void loop()
{
	Psx.read();

	if(Psx.psxID != 0x00)
	{
		envio[0] = Psx.psxID; // DIGITAL (82) , ANALOGICO (CE)
		envio[1] = Psx.psxStatus;
		envio[2] = Psx.psxThumbL; // SETAS, SELECT, DIGITAL L
		envio[3] = Psx.psxThumbR; // (x,[],/\,O), START, DIGITAL R, (L1,L2,R1,R2)
		envio[4] = Psx.psxJoyRX; // EIXO ANALOGICO "X" DO "R"
		envio[5] = Psx.psxJoyRY; // EIXO ANALOGICO "Y" DO "R"
		envio[6] = Psx.psxJoyLX; // EIXO ANALOGICO "X" DO "L"
		envio[7] = Psx.psxJoyLY; // EIXO ANALOGICO "Y" DO "L"

   
      Serial.print("Data 0 ==> ");
      Serial.println(envio[2]);
      Serial.print("Data 1 ==> ");
      Serial.println(envio[3]);
      Serial.print("Data 2 ==> ");
      Serial.println(envio[4]);
      Serial.print("Data 3 ==> ");
      Serial.println(envio[5]);
      Serial.print("Data 4 ==> ");
      Serial.println(envio[6]);
      Serial.print("Data 5 ==> ");
      Serial.println(envio[7]);

		Mirf.setTADDR(tx_endereco);
		Mirf.send(envio);
		while(Mirf.isSending());
	}

	delay(50);
}
