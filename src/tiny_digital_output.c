/*!
 * @file
 * @brief
 */

#include "tiny_digital_output.h"
#include "tiny_utils.h"

static void write(i_tiny_digital_output_t* _self, bool value) {
  reinterpret(self, _self, tiny_digital_output_t*);
  gpio_pin_set(self->_private.port, self->_private.pin, value);
}

static const i_tiny_digital_output_api_t api = { write };

void tiny_digital_output_init(tiny_digital_output_t* self, const char* port, gpio_pin_t pin) {
  self->_private.port = device_get_binding(port);
  self->_private.pin = pin;
  self->interface.api = &api;
  gpio_pin_configure(self->_private.port, pin, GPIO_OUTPUT);
}
