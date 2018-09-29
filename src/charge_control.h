#ifndef __CHARGE_CONTROL_H__
#define __CHARGE_CONTROL_H__

#include <stdint.h>
#include "relay.h"

class Charge_control {
public:
void discharge_stop();
void discharge_stop1();
void charge_stop();
void charge_stop1();
void charge();
void charge1 ();
void discharge();
void discharge1();

};
#endif