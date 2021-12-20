#include <SoftwareSerial.h>

String IS;
int APos, CPos;
char solarByte;
String solar;

SoftwareSerial mySerial(D2, D1); // RX, TX

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Native USB only
  }

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
}

void loop() // run over and over
{// Read all data from VVM sensor and store to string "solar"
  while (mySerial.available()) {
    solarByte = mySerial.read();
    solar.concat(solarByte);
  }

//Find the index of first "A" in the string
  APos = solar.indexOf('A');
//Find the index of "C" in the string
  CPos = solar.indexOf('C');
//Extract Current value inbetween "C" and first "A" position
  IS = solar.substring(CPos+1, APos);
  
  Serial.println(IS);
//Clear the sting
  solar = "";
//Wait for a second before next poll
  delay(1000);


}
