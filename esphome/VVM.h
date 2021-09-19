//Header file to create custome component in esphome.

#include "esphome.h"

class VVM : public PollingComponent, public UARTDevice {
 public:
  VVM(UARTComponent *parent) : PollingComponent(2000), UARTDevice(parent) {}
  Sensor *IS_sensor = new Sensor();
  Sensor *VS_sensor = new Sensor();
  Sensor *PSC_sensor = new Sensor();
  Sensor *PSD_sensor = new Sensor();
 
  float IS;
  float VS;
  float PSC;
  float PSD;
  

  void setup() override {
  }
  void update() override {
    String solar = readStringUntil('\n');
    int DPos1 = solar.indexOf('D');
    int DPos2 = solar.indexOf('D', DPos1 + 1);
    int CPos = solar.indexOf('C');
    int VPos = solar.indexOf('V');
    String I = solar.substring(CPos+1, DPos1);
    String V = solar.substring(VPos + 1, DPos2);
    IS = I.toFloat();
    VS = V.toFloat();
    if(IS > 0)
       PSC = I.toFloat() * V.toFloat() * 0.001;
    else
       PSD = I.toFloat() * V.toFloat() * 0.001 * -1;
    IS_sensor->publish_state(IS);
    VS_sensor->publish_state(VS);
    PSC_sensor->publish_state(PSC);
    PSD_sensor->publish_state(PSD);
    IS = 0;
    VS = 0;
    PSC = 0;
    PSD = 0;
    I = "";
    V = "";
  }
};
