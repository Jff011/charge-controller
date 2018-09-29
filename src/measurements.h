#ifndef __MEASUREMENTS_H__
#define __MEASUREMENTS_H__

#include <stdint.h>

#include "adc.h"
#include "cell_monitors.h"
#include "config.h"

class Measurements {
public:
  Measurements(CellMonitors *cell_monitors, Adc *adc, Adcb *adcb);
  bool update();
  void zero_current();
  uint16_t cell_voltage(uint8_t index);
  uint16_t pack_voltage();
  int32_t charge_current();
  int32_t discharge_current();
  uint16_t pack1_voltage();
  int32_t charge1_current();
  int32_t discharge1_current();

private:
  CellMonitors *_cell_monitors;
  Adc *_adc;
  Adcb *_adcb;
  // the most recent cell volage readings in mV
  uint16_t _cell_voltages[NUM_CELLS];

  // the most recent pack voltage reading in mV
  uint16_t _pack_voltage;
  uint16_t _pack1_voltage;

  // the most recent charge current reading in mA
  int32_t _charge_current;
  int32_t _charge1_current;

  // the ADC value expected for 0mA charge current
  uint16_t _charge_adc_zero;
  uint16_t _charge1_adc_zero;
  // the most recent discharge current reading in mA
  int32_t _discharge_current;
  int32_t _discharge1_current;
  // the ADC value expected for 0mA discharge current
  uint16_t _discharge_adc_zero; 
  uint16_t _discharge1_adc_zero;


};

#endif
