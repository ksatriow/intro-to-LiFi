#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrp;

void setup()
{
tmrp.speakerPin=9;
Serial.begin(9600);
if(!SD.begin(SD_ChipSelectPin))
{
  Serial.println("SD fail");
  return;
}
tmrp.setVolume(6);
tmrp.play("makerpro.wav");
}

void loop() {
  // put your main code here, to run repeatedly:
}

/*
 * Speaker Out - pin 9
 * SD Card Wiring 
 * Library (https://github.com/TMRh20/TMRpcm)
 ** CLK - pin 13
 ** CS - pin 4 
 ** MOSI - pin 11
 ** MISO - pin 12
*/

    
