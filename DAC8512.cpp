#include "Arduino.h"
#include "DAC8512.h"


 DAC8512 :: DAC8512()
{

}

void DAC8512 :: setupDAC(uint8_t clrPin, uint8_t csPin, uint8_t ldPin)
{
	_clrPin=clrPin;
	_csPin=csPin;
	_ldPin=ldPin;
	
	pinMode(clrPin, OUTPUT);
	pinMode(csPin, OUTPUT);
	pinMode(ldPin, OUTPUT);
	
	digitalWrite(ldPin, HIGH);
	digitalWrite(csPin, HIGH);
	digitalWrite(clrPin, HIGH);
	digitalWrite(csPin, LOW);
	
	 SPI.begin();
	 SPI.setClockDivider(SPI_CLOCK_DIV2);
	 SPI.beginTransaction(SPISettings(16000000, MSBFIRST, SPI_MODE0));
/* 	 SPI.setDataMode(SPI_MODE3);
	 SPI.setBitOrder(MSBFIRST); */
	
	del=0;
}

void DAC8512 :: convert(uint16_t outputValue)
{
	//outputValue=constrain(outputValue,0 , MAX_VALUE);
	digitalWrite(_ldPin, HIGH);
	digitalWrite(_csPin, LOW);
	
	data=highByte(outputValue);
	SPI.transfer(data);
	
	data=lowByte(outputValue);
	SPI.transfer(data);
	
	digitalWrite(_csPin, HIGH);
	digitalWrite(_ldPin, LOW);
	//digitalWrite(_ldPin, LOW);
}
 void DAC8512 :: setValue(unsigned int value)
 {
	 
	 SPI.transfer(value>>8);
	 SPI.transfer(value & 0xff);
	 
 }
 
 void DAC8512 :: toggleLD()
 {
	 
	 digitalWrite(_ldPin, HIGH);
	 digitalWrite(_ldPin, LOW);
 }
 
 void DAC8512 :: selectChip()
 {
	 digitalWrite(_csPin, LOW);
 }
 
 void DAC8512 :: deselectChip()
 {
	 digitalWrite(_csPin, HIGH);
 }
