#ifndef DAC8512_H
 #define DAC8512_H
 #if ARDUINO>=100
	#include "Arduino.h"
	#else 
		#include "WProgram.h"
 #endif
 #include "SPI.h"
 
 #define MAX_VALUE 4095
 
 class DAC8512
 {
	 public :
	 DAC8512 ();
	 void convert(uint16_t outputValue);
	 void setValue(unsigned int value);
	 void toggleLD();
	 void setupDAC(uint8_t clrPin, uint8_t csPin, uint8_t ldPin);
	 void selectChip();
	 void deselectChip();
	
    

	 
	 private :
	 
	 uint8_t _clrPin;
	 uint8_t _csPin;
	 uint8_t _ldPin;
	 int del;
	 uint8_t data;
	 
 };

 #endif
	
	