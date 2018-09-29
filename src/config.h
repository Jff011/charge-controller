#ifndef __CONFIG_H__
#define __CONFIG_H__

// ------------------------------
// Battery config

// The number of series cells in the battery pack.
// There should be a cell monitor for each cell.
#define NUM_CELLS 32

// The number of battery packs being monitored
#define NUM_PACKS 2

// The minimum cell voltage (specified in mV) at which over-voltage protection is enabled.
#define OV_ENABLE 3550

// The maximum cell voltage (specified in mV) at which over-voltage protection is disabled.
// This only applies while OV is enabled.
#define OV_DISABLE 3350

// The maximum cell voltage (specified in mV) at which under-voltage proection is enabled.
#define UV_ENABLE 3000

// The minimum cell voltage (specified in mV) at which under-voltage protection is disabled.
// This only applies while UV is enabled.
#define UV_DISABLE 3100

// The nominal battery capacity (specified in mA seconds)
#define NOMINAL_CAPACITY 618750000 // 172Ah

// The maximum error tolerated between the pack voltage reading
// and the sum of the cell voltages (specified in mV)
#define MAX_VOLTAGE_ERROR 200

// The time interval (in milliseconds) during which coulomb-counting values are summed
#define CC_COUNTER_INTERVAL 3600000 // 1 hour

// ------------------------------
// Hardware config

// I2C address of two ADS1115 ADC
#define ADC_ADDRESS 0x48
#define ADCB_ADDRESS 0x49

// ADS1115 channels
#define ADC_CHANNEL_PACK_VOLTAGE 0
#define ADC_CHANNEL_CHARGE_CURRENT 2
#define ADC_CHANNEL_DISCHARGE_CURRENT 3

// ACS758 sensitivity (mV / A)
#define ACS758_SENSITIVITY 20

// RX pin connected to cell monitors
#define RX_PIN 0

// TX pin connection to cell monitors
#define TX_PIN 1

// pin configs change for latching relays

// pin connected to charge relays
#define CHARGE_PIN_0 2
#define CHARGE_CUT_PIN_0 3

#define CHARGE_PIN_1 4
#define CHARGE_CUT_PIN_1 5

// pin connected to discharge relay
#define DISCHARGE_PIN_0 6
#define DISCHARGE_CUT_PIN_0 7

#define DISCHARGE_PIN_1 8
#define DISCHARGE_CUT_PIN_1 9

// voltage divider scaler for reading pack voltage
// 100k / 10k divider
#define PACK_VOLTAGE_DIVIDER 110000 / 10000

//adding pins for boat
//+5v or better read voltage from oil pressure
#define ENGINE_RUN_SENSE_PIN 10
//need to check
#define GENERATOR_SWITCH_PIN 11
#define SHOREPOWER_SENSE_PIN 12
#define SHOREPOWER_SWITCH_PIN 13
#define IGNITION_SWITCH_PIN 14
#define NEUTRAL_SWITCH_PIN 15
#define ACCELERATOR_SWITCHOVER_PIN 16
#define IDLE_PIN 17
//#define RPM_SET_PIN 18
//#define FLASHER 19
//#define FLASHER_1 20
#endif
