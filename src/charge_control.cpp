#include "charge_control.h"
#include "measurements.h"
#include "relay.h"


Relay chargeon(CHARGE_PIN_0);
Relay chargestop(CHARGE_CUT_PIN_0);
Relay chargeon1(CHARGE_PIN_1);
Relay chargestop1(CHARGE_CUT_PIN_1);
Relay dischargeon(DISCHARGE_PIN_0);
Relay dischargeoff(DISCHARGE_CUT_PIN_0);
Relay dischargeon1(DISCHARGE_PIN_1);
Relay dischargeoff1(DISCHARGE_CUT_PIN_1);
Relay shorepower (SHOREPOWER_SWITCH_PIN);
Relay generator(GENERATOR_SWITCH_PIN);
Relay cut ();
Relay enable();
Relay disable ();

bool waiting_to_charge = 0;
bool waiting_to_charge1 = 0;

//Stop charging first pack
void Charge_control::charge_stop() {
  //Stop charge source
 shorepower.cut();
  generator.cut();

delay (10);
//cut relay
chargestop.enable();
waiting_to_charge = false;
}

//Stop charging second pack
void Charge_control::charge_stop1() {
  //Stop charge source
 shorepower.cut();
 generator.cut();
  delay (10);
chargestop1.enable();
waiting_to_charge1 = false;
}
//Start charging first pack
void Charge_control::charge() {
  //Stop charge source
  shorepower.enable();
  generator.enable();
delay (10);
//cut relay
chargeon.enable();
}

//Start charging second pack
void Charge_control::charge1() {
  //Stop charge source
 shorepower.enable();
 generator.enable();

delay (10);

 chargeon1.enable();
}

//Stop discharging first pack
void Charge_control::discharge_stop() {
//Switch to second pack
  dischargeon1.enable();   
 delay (20);
//cut the relay
  dischargeoff.enable();
  waiting_to_charge = true;
}


//Stop discharging second pack
void Charge_control::discharge_stop1() {
//Switch to first pack
  dischargeon.enable();    
  delay (150);
  dischargeoff1.enable();
  waiting_to_charge1 = true;
}

//Start discharge first pack
void Charge_control::discharge() {
  dischargeon.enable();    
}

//Start discharge first pack
void Charge_control::discharge1() {
  dischargeon1.enable();    
}