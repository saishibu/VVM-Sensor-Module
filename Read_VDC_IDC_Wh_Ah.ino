//Not tested. May have issues. Report them in issues section

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
//Find the index of third "D" in the string
  DPos3 = solar.indexOf('D', DPos2 + 1);
//Find the index of fourth "D" in the string
  DPos4 = solar.indexOf('D', DPos3 + 1);
//Find the index of "C" in the string
  CPos = solar.indexOf('C');
//Find the index of "AH" in the string
  VPos = solar.indexOf('V');
//Find the index of "V" in the string
  WHPos = solar.indexOf('Wh');
//Find the index of "V" in the string
  AHPos = solar.indexOf('Ah');
//Extract Current value inbetween "C" and first "D" position
  IS = solar.substring(CPos+1, DPos1);
//Extract Voltage value inbetween "V" and second "D" position
  VS = solar.substring(VPos + 1, DPos2);
//Extract Ah value inbetween "Ah" and third "D" position
  AH = solar.substring(AHPos + 1, DPos3);
//Extract Wh value inbetween "Wh" and fourth "D" position
  WH = solar.substring(WHPos + 1, DPos4);

//Print all values
  Serial.println(IS);
  Serial.println(VS);
  Serial.println(AH);
  Serial.println(WH);

//Clear the sting
  solar = "";
//Wait for a second before next poll
  delay(1000);


}
