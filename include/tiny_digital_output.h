/*!
 * @file
 * @brief Wraps an Zephyr digital output.
 */

#ifndef tiny_digital_output_h
#define tiny_digital_output_h

#include <stdint.h>
#include <device.h>
#include <drivers/gpio.h>
#include "hal/i_tiny_digital_output.h"

typedef struct {
  i_tiny_digital_output_t interface;

  struct {
    struct device* port;
    gpio_pin_t pin;
  } _private;
} tiny_digital_output_t;

void tiny_digital_output_init(tiny_digital_output_t* self, const char*port, gpio_pin_t pin);

#endif
