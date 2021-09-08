#include <SoftwareSerial.h>

String IS , VS;
int DPos1, DPos2, CPos, VPos;
char solarByte;
String solar, solar2, solar3;

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

//Find the index of first "D" in the string
  DPos1 = solar.indexOf('D');
//Find the index of second "D" in the string
  DPos2 = solar.indexOf('D', DPos1 + 1);
//Find the index of "C" in the string
  CPos = solar.indexOf('C');
//Find the index of "V" in the string
  VPos = solar.indexOf('V');
//Extract Current value inbetween "C" and first "D" position
  IS = solar.substring(CPos+1, DPos1);
//Extract Voltage value inbetween "V" and second "D" position
  VS = solar.substring(VPos + 1, DPos2);
  
  Serial.println(IS);
  Serial.println(VS);
//Clear the sting
  solar = "";
//Wait for a second before next poll
  delay(1000);


}
