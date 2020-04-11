/*!
 * @file
 * @brief
 */

#include "tiny_digital_input.h"
#include "tiny_utils.h"

static bool read(i_tiny_digital_input_t* _self) {
  reinterpret(self, _self, tiny_digital_input_t*);
  return (bool)gpio_pin_get(self->_private.port, self->_private.pin);
}

static const i_tiny_digital_input_api_t api = { read };

void tiny_digital_input_init(tiny_digital_input_t* self, const char* port, gpio_pin_t pin) {
  self->_private.port = device_get_binding(port);
  self->_private.pin = pin;
  self->interface.api = &api;
  gpio_pin_configure(self->_private.port, pin, GPIO_INPUT);
}
