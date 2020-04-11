/*!
 * @file
 * @brief Wraps a Zephyr digital input.
 */

#ifndef tiny_digital_input_h
#define tiny_digital_input_h

#include <stdint.h>
#include <device.h>
#include <drivers/gpio.h>
#include "hal/i_tiny_digital_input.h"

typedef struct {
  i_tiny_digital_input_t interface;

  struct {
    struct device* port;
    gpio_pin_t pin;
  } _private;
} tiny_digital_input_t;

void tiny_digital_input_init(tiny_digital_input_t* self, const char*port, gpio_pin_t pin);

#endif
