#include <Arduino.h>
#include "relay.h"
#include "config.h"




Relay::Relay(uint8_t pin) : _pin(pin) {
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, LOW);
}

void Relay::enable() {
  digitalWrite(_pin, HIGH);
  delay (120);
  digitalWrite(_pin, LOW);
}
//changed for latching relay
void Relay::disable() {
  digitalWrite(_pin, HIGH);
  delay (120);
  digitalWrite(_pin, LOW); 
}
void Relay::cut() {
  digitalWrite(_pin, LOW);
}
