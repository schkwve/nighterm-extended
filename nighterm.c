/**
 * @brief This file implements public Nighterm API.
 */

#include "nighterm.h"

static struct nighterm_config config = { 0 };

/**
 * @brief Default font if the one supplied is inavlid or NULL.
 */
static unsigned char nighterm_default_font[] = {
  0x72, 0xb5, 0x4a, 0x86, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x01,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x00,
  0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x42, 0x00, 0x42, 0x42,
  0x42, 0x00, 0x42, 0x42, 0x66, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00, 0x10, 0x10,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x24, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x24, 0x24, 0x7e,
  0x24, 0x24, 0x7e, 0x24, 0x24, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10,
  0x7c, 0x92, 0x90, 0x90, 0x7c, 0x12, 0x12, 0x92, 0x7c, 0x10, 0x10, 0x00, 0x00,
  0x00, 0x00, 0x64, 0x94, 0x68, 0x08, 0x10, 0x10, 0x20, 0x2c, 0x52, 0x4c, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x24, 0x24, 0x18, 0x30, 0x4a, 0x44, 0x44,
  0x44, 0x3a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x10, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x10,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x10, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x20, 0x10, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x10, 0x20, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x18, 0x7e, 0x18, 0x24, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x7c,
  0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x08, 0x08, 0x10, 0x10, 0x20,
  0x20, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x46,
  0x4a, 0x52, 0x62, 0x42, 0x42, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08,
  0x18, 0x28, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x3e, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x3c, 0x42, 0x42, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x7e, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x02, 0x1c, 0x02, 0x02, 0x42,
  0x42, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x0a, 0x12, 0x22,
  0x42, 0x7e, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x40,
  0x40, 0x40, 0x7c, 0x02, 0x02, 0x02, 0x42, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x1c, 0x20, 0x40, 0x40, 0x7c, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x7e, 0x02, 0x02, 0x04, 0x04, 0x08, 0x08, 0x10, 0x10,
  0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x42, 0x3c, 0x42,
  0x42, 0x42, 0x42, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x42, 0x42,
  0x42, 0x42, 0x3e, 0x02, 0x02, 0x04, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x10, 0x10, 0x00, 0x00, 0x00, 0x10, 0x10, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x00, 0x00, 0x00, 0x10, 0x10,
  0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x08, 0x10, 0x20, 0x40, 0x20,
  0x10, 0x08, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e,
  0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x40, 0x20, 0x10, 0x08, 0x04, 0x08, 0x10, 0x20, 0x40, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x3c, 0x42, 0x42, 0x42, 0x04, 0x08, 0x08, 0x00, 0x08, 0x08, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x82, 0x9e, 0xa2, 0xa2, 0xa2, 0xa6, 0x9a,
  0x80, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x42, 0x42,
  0x7e, 0x42, 0x42, 0x42, 0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x42,
  0x42, 0x42, 0x7c, 0x42, 0x42, 0x42, 0x42, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x3c, 0x42, 0x42, 0x40, 0x40, 0x40, 0x40, 0x42, 0x42, 0x3c, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x78, 0x44, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x44,
  0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x40, 0x40, 0x40, 0x78, 0x40,
  0x40, 0x40, 0x40, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x40, 0x40,
  0x40, 0x78, 0x40, 0x40, 0x40, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x3c, 0x42, 0x42, 0x40, 0x40, 0x4e, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x42, 0x42, 0x42, 0x42, 0x7e, 0x42, 0x42, 0x42, 0x42, 0x42,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x10, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x04, 0x04, 0x04,
  0x04, 0x04, 0x04, 0x44, 0x44, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x42,
  0x44, 0x48, 0x50, 0x60, 0x60, 0x50, 0x48, 0x44, 0x42, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x7e, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x82, 0xc6, 0xaa, 0x92, 0x92, 0x82, 0x82, 0x82,
  0x82, 0x82, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x42, 0x42, 0x62, 0x52,
  0x4a, 0x46, 0x42, 0x42, 0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x42,
  0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x7c, 0x42, 0x42, 0x42, 0x42, 0x7c, 0x40, 0x40, 0x40, 0x40, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x4a,
  0x3c, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x42, 0x42, 0x42, 0x42, 0x7c,
  0x50, 0x48, 0x44, 0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x42, 0x40,
  0x40, 0x3c, 0x02, 0x02, 0x42, 0x42, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xfe, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x42, 0x42, 0x42, 0x42, 0x24, 0x24,
  0x24, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x82, 0x82, 0x82, 0x82,
  0x82, 0x92, 0x92, 0xaa, 0xc6, 0x82, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x42,
  0x42, 0x24, 0x24, 0x18, 0x18, 0x24, 0x24, 0x42, 0x42, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x82, 0x82, 0x44, 0x44, 0x28, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x02, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40,
  0x40, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40,
  0x20, 0x20, 0x10, 0x10, 0x08, 0x08, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x38, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x38, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x10, 0x28, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x10, 0x08, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x3c, 0x02, 0x3e, 0x42, 0x42, 0x42, 0x3e, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x40, 0x40, 0x40, 0x7c, 0x42, 0x42, 0x42, 0x42, 0x42, 0x7c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x42, 0x40, 0x40,
  0x40, 0x42, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x3e,
  0x42, 0x42, 0x42, 0x42, 0x42, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x3c, 0x42, 0x42, 0x7e, 0x40, 0x40, 0x3c, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x0e, 0x10, 0x10, 0x7c, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x42, 0x42, 0x42, 0x42,
  0x42, 0x3e, 0x02, 0x02, 0x3c, 0x00, 0x00, 0x00, 0x40, 0x40, 0x40, 0x7c, 0x42,
  0x42, 0x42, 0x42, 0x42, 0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10,
  0x00, 0x30, 0x10, 0x10, 0x10, 0x10, 0x10, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x04, 0x04, 0x00, 0x0c, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x44, 0x44,
  0x38, 0x00, 0x00, 0x00, 0x40, 0x40, 0x40, 0x42, 0x44, 0x48, 0x70, 0x48, 0x44,
  0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x10, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x10, 0x10, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xfc, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7c, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x42, 0x42, 0x42,
  0x42, 0x42, 0x7c, 0x40, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e,
  0x42, 0x42, 0x42, 0x42, 0x42, 0x3e, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x5e, 0x60, 0x40, 0x40, 0x40, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x40, 0x40, 0x3c, 0x02, 0x02, 0x7c, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x10, 0x7c, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x42,
  0x42, 0x42, 0x42, 0x42, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x42, 0x42, 0x42, 0x24, 0x24, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x82, 0x82, 0x92, 0x92, 0x92, 0x92, 0x7c, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x42, 0x24, 0x18, 0x24, 0x42,
  0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x42, 0x42,
  0x42, 0x42, 0x42, 0x3e, 0x02, 0x02, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x7e, 0x04, 0x08, 0x10, 0x20, 0x40, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x0c, 0x10, 0x10, 0x10, 0x20, 0x10, 0x10, 0x10, 0x10, 0x0c, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x08, 0x08, 0x08, 0x04, 0x08, 0x08,
  0x08, 0x08, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x62, 0x92, 0x8c, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x00,
  0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x10, 0x10, 0x7c, 0x92, 0x90, 0x90, 0x90, 0x92, 0x7c, 0x10, 0x10, 0x00,
  0x00, 0x00, 0x00, 0x18, 0x24, 0x20, 0x20, 0x78, 0x20, 0x20, 0x20, 0x22, 0x7e,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x44, 0x38, 0x44, 0x44, 0x44,
  0x38, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x82, 0x82, 0x44, 0x28,
  0x10, 0x7c, 0x10, 0x7c, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10,
  0x10, 0x10, 0x10, 0x00, 0x00, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x38, 0x44, 0x40, 0x30, 0x48, 0x44, 0x44, 0x24, 0x18, 0x04, 0x44, 0x38,
  0x00, 0x00, 0x00, 0x24, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x81, 0x99, 0xa5,
  0xa1, 0xa5, 0x99, 0x81, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x04, 0x3c,
  0x44, 0x3c, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x12, 0x24, 0x48, 0x90, 0x48, 0x24, 0x12, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x02, 0x02, 0x02, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x81,
  0xb9, 0xa5, 0xb9, 0xa9, 0xa5, 0x81, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x18, 0x24, 0x24, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x7c, 0x10,
  0x10, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x24, 0x04, 0x08, 0x10,
  0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x04,
  0x18, 0x04, 0x04, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x08, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x42, 0x42, 0x42, 0x42,
  0x46, 0x7a, 0x40, 0x40, 0x40, 0x00, 0x00, 0x00, 0x7e, 0x92, 0x92, 0x92, 0x92,
  0x72, 0x12, 0x12, 0x12, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10,
  0x20, 0x00, 0x00, 0x10, 0x30, 0x10, 0x10, 0x10, 0x38, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x44, 0x44, 0x44, 0x38, 0x00, 0x7c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x90, 0x48, 0x24, 0x12, 0x24, 0x48, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20,
  0x60, 0x20, 0x22, 0x24, 0x08, 0x10, 0x22, 0x46, 0x8a, 0x1e, 0x02, 0x02, 0x00,
  0x00, 0x00, 0x20, 0x60, 0x20, 0x22, 0x24, 0x08, 0x10, 0x20, 0x4c, 0x92, 0x04,
  0x08, 0x1e, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x60, 0x12, 0xe4, 0x08, 0x10, 0x22,
  0x46, 0x8a, 0x1e, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x00, 0x10,
  0x10, 0x20, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x10, 0x08, 0x00,
  0x3c, 0x42, 0x42, 0x42, 0x7e, 0x42, 0x42, 0x42, 0x42, 0x00, 0x00, 0x00, 0x00,
  0x08, 0x10, 0x00, 0x3c, 0x42, 0x42, 0x42, 0x7e, 0x42, 0x42, 0x42, 0x42, 0x00,
  0x00, 0x00, 0x00, 0x18, 0x24, 0x00, 0x3c, 0x42, 0x42, 0x42, 0x7e, 0x42, 0x42,
  0x42, 0x42, 0x00, 0x00, 0x00, 0x00, 0x32, 0x4c, 0x00, 0x3c, 0x42, 0x42, 0x42,
  0x7e, 0x42, 0x42, 0x42, 0x42, 0x00, 0x00, 0x00, 0x00, 0x24, 0x24, 0x00, 0x3c,
  0x42, 0x42, 0x42, 0x7e, 0x42, 0x42, 0x42, 0x42, 0x00, 0x00, 0x00, 0x00, 0x18,
  0x24, 0x18, 0x3c, 0x42, 0x42, 0x42, 0x7e, 0x42, 0x42, 0x42, 0x42, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x7e, 0x90, 0x90, 0x90, 0xfc, 0x90, 0x90, 0x90, 0x90,
  0x9e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x40, 0x40, 0x40,
  0x40, 0x42, 0x42, 0x3c, 0x10, 0x10, 0x20, 0x00, 0x10, 0x08, 0x00, 0x7e, 0x40,
  0x40, 0x40, 0x78, 0x40, 0x40, 0x40, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x08, 0x10,
  0x00, 0x7e, 0x40, 0x40, 0x40, 0x78, 0x40, 0x40, 0x40, 0x7e, 0x00, 0x00, 0x00,
  0x00, 0x18, 0x24, 0x00, 0x7e, 0x40, 0x40, 0x40, 0x78, 0x40, 0x40, 0x40, 0x7e,
  0x00, 0x00, 0x00, 0x00, 0x24, 0x24, 0x00, 0x7e, 0x40, 0x40, 0x40, 0x78, 0x40,
  0x40, 0x40, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x20, 0x10, 0x00, 0x38, 0x10, 0x10,
  0x10, 0x10, 0x10, 0x10, 0x10, 0x38, 0x00, 0x00, 0x00, 0x00, 0x08, 0x10, 0x00,
  0x38, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x38, 0x00, 0x00, 0x00, 0x00,
  0x18, 0x24, 0x00, 0x38, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x38, 0x00,
  0x00, 0x00, 0x00, 0x44, 0x44, 0x00, 0x38, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x44, 0x42, 0x42, 0xf2,
  0x42, 0x42, 0x42, 0x44, 0x78, 0x00, 0x00, 0x00, 0x00, 0x32, 0x4c, 0x00, 0x42,
  0x42, 0x62, 0x52, 0x4a, 0x46, 0x42, 0x42, 0x42, 0x00, 0x00, 0x00, 0x00, 0x10,
  0x08, 0x00, 0x3c, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00,
  0x00, 0x00, 0x08, 0x10, 0x00, 0x3c, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42,
  0x3c, 0x00, 0x00, 0x00, 0x00, 0x18, 0x24, 0x00, 0x3c, 0x42, 0x42, 0x42, 0x42,
  0x42, 0x42, 0x42, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x32, 0x4c, 0x00, 0x3c, 0x42,
  0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x24, 0x24,
  0x00, 0x3c, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x43, 0x42, 0x46, 0x4a, 0x52, 0x62,
  0x42, 0xc2, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x10, 0x08, 0x42, 0x42, 0x42, 0x42,
  0x42, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x08, 0x10, 0x42,
  0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00, 0x00, 0x00,
  0x18, 0x24, 0x00, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00,
  0x00, 0x00, 0x00, 0x24, 0x24, 0x00, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42,
  0x42, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x08, 0x10, 0x82, 0x82, 0x44, 0x44, 0x28,
  0x10, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40,
  0x7c, 0x42, 0x42, 0x42, 0x42, 0x7c, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x38, 0x44, 0x44, 0x48, 0x7c, 0x42, 0x42, 0x42, 0x62, 0x5c, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x10, 0x08, 0x00, 0x3c, 0x02, 0x3e, 0x42, 0x42, 0x42,
  0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x10, 0x00, 0x3c, 0x02, 0x3e,
  0x42, 0x42, 0x42, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x24, 0x00,
  0x3c, 0x02, 0x3e, 0x42, 0x42, 0x42, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x32, 0x4c, 0x00, 0x3c, 0x02, 0x3e, 0x42, 0x42, 0x42, 0x3e, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x24, 0x24, 0x00, 0x3c, 0x02, 0x3e, 0x42, 0x42, 0x42, 0x3e,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x24, 0x18, 0x3c, 0x02, 0x3e, 0x42,
  0x42, 0x42, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6c,
  0x12, 0x72, 0x9e, 0x90, 0x90, 0x6c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x3c, 0x42, 0x40, 0x40, 0x40, 0x42, 0x3c, 0x10, 0x10, 0x20, 0x00,
  0x00, 0x00, 0x10, 0x08, 0x00, 0x3c, 0x42, 0x42, 0x7e, 0x40, 0x40, 0x3c, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x10, 0x00, 0x3c, 0x42, 0x42, 0x7e, 0x40,
  0x40, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x24, 0x00, 0x3c, 0x42,
  0x42, 0x7e, 0x40, 0x40, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x24,
  0x00, 0x3c, 0x42, 0x42, 0x7e, 0x40, 0x40, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x20, 0x10, 0x00, 0x30, 0x10, 0x10, 0x10, 0x10, 0x10, 0x38, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x08, 0x10, 0x00, 0x30, 0x10, 0x10, 0x10, 0x10, 0x10,
  0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x48, 0x00, 0x30, 0x10, 0x10,
  0x10, 0x10, 0x10, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x48, 0x00,
  0x30, 0x10, 0x10, 0x10, 0x10, 0x10, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x28, 0x10, 0x28, 0x3c, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x32, 0x4c, 0x00, 0x7c, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x08, 0x00, 0x3c, 0x42, 0x42, 0x42,
  0x42, 0x42, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x10, 0x00, 0x3c,
  0x42, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18,
  0x24, 0x00, 0x3c, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x32, 0x4c, 0x00, 0x3c, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x24, 0x00, 0x3c, 0x42, 0x42, 0x42, 0x42,
  0x42, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x00,
  0x7c, 0x00, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x02, 0x3c, 0x46, 0x4a, 0x52, 0x62, 0x42, 0xbc, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x10, 0x08, 0x00, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3e, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x08, 0x10, 0x00, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42,
  0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x24, 0x00, 0x42, 0x42, 0x42,
  0x42, 0x42, 0x42, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x24, 0x00,
  0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x08, 0x10, 0x00, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3e, 0x02, 0x02, 0x3c,
  0x00, 0x00, 0x00, 0x40, 0x40, 0x40, 0x7c, 0x42, 0x42, 0x42, 0x42, 0x42, 0x7c,
  0x40, 0x40, 0x40, 0x00, 0x00, 0x00, 0x24, 0x24, 0x00, 0x42, 0x42, 0x42, 0x42,
  0x42, 0x42, 0x3e, 0x02, 0x02, 0x3c, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0x20, 0xff, 0x21, 0xff, 0x22, 0xff, 0x23, 0xff, 0x24, 0xff, 0x25, 0xff, 0x26,
  0xff, 0x27, 0xff, 0x28, 0xff, 0x29, 0xff, 0x2a, 0xff, 0x2b, 0xff, 0x2c, 0xff,
  0x2d, 0xff, 0x2e, 0xff, 0x2f, 0xff, 0x30, 0xff, 0x31, 0xff, 0x32, 0xff, 0x33,
  0xff, 0x34, 0xff, 0x35, 0xff, 0x36, 0xff, 0x37, 0xff, 0x38, 0xff, 0x39, 0xff,
  0x3a, 0xff, 0x3b, 0xff, 0x3c, 0xff, 0x3d, 0xff, 0x3e, 0xff, 0x3f, 0xff, 0x40,
  0xff, 0x41, 0xff, 0x42, 0xff, 0x43, 0xff, 0x44, 0xff, 0x45, 0xff, 0x46, 0xff,
  0x47, 0xff, 0x48, 0xff, 0x49, 0xff, 0x4a, 0xff, 0x4b, 0xff, 0x4c, 0xff, 0x4d,
  0xff, 0x4e, 0xff, 0x4f, 0xff, 0x50, 0xff, 0x51, 0xff, 0x52, 0xff, 0x53, 0xff,
  0x54, 0xff, 0x55, 0xff, 0x56, 0xff, 0x57, 0xff, 0x58, 0xff, 0x59, 0xff, 0x5a,
  0xff, 0x5b, 0xff, 0x5c, 0xff, 0x5d, 0xff, 0x5e, 0xff, 0x5f, 0xff, 0x60, 0xff,
  0x61, 0xff, 0x62, 0xff, 0x63, 0xff, 0x64, 0xff, 0x65, 0xff, 0x66, 0xff, 0x67,
  0xff, 0x68, 0xff, 0x69, 0xff, 0x6a, 0xff, 0x6b, 0xff, 0x6c, 0xff, 0x6d, 0xff,
  0x6e, 0xff, 0x6f, 0xff, 0x70, 0xff, 0x71, 0xff, 0x72, 0xff, 0x73, 0xff, 0x74,
  0xff, 0x75, 0xff, 0x76, 0xff, 0x77, 0xff, 0x78, 0xff, 0x79, 0xff, 0x7a, 0xff,
  0x7b, 0xff, 0x7c, 0xff, 0x7d, 0xff, 0x7e, 0xff, 0xff, 0xe2, 0x82, 0xac, 0xff,
  0xff, 0xe2, 0x80, 0x9a, 0xff, 0xc6, 0x92, 0xff, 0xe2, 0x80, 0x9e, 0xff, 0xe2,
  0x80, 0xa6, 0xff, 0xe2, 0x80, 0xa0, 0xff, 0xe2, 0x80, 0xa1, 0xff, 0xcb, 0x86,
  0xff, 0xe2, 0x80, 0xb0, 0xff, 0xc5, 0xa0, 0xff, 0xe2, 0x80, 0xb9, 0xff, 0xc5,
  0x92, 0xff, 0xff, 0xc5, 0xbd, 0xff, 0xff, 0xff, 0xe2, 0x80, 0x98, 0xff, 0xe2,
  0x80, 0x99, 0xff, 0xe2, 0x80, 0x9c, 0xff, 0xe2, 0x80, 0x9d, 0xff, 0xe2, 0x80,
  0xa2, 0xff, 0xe2, 0x80, 0x93, 0xff, 0xe2, 0x80, 0x94, 0xff, 0xcb, 0x9c, 0xff,
  0xe2, 0x84, 0xa2, 0xff, 0xc5, 0xa1, 0xff, 0xe2, 0x80, 0xba, 0xff, 0xc5, 0x93,
  0xff, 0xff, 0xc5, 0xbe, 0xff, 0xc5, 0xb8, 0xff, 0xc2, 0xa0, 0xff, 0xc2, 0xa1,
  0xff, 0xc2, 0xa2, 0xff, 0xc2, 0xa3, 0xff, 0xc2, 0xa4, 0xff, 0xc2, 0xa5, 0xff,
  0xc2, 0xa6, 0xff, 0xc2, 0xa7, 0xff, 0xc2, 0xa8, 0xff, 0xc2, 0xa9, 0xff, 0xc2,
  0xaa, 0xff, 0xc2, 0xab, 0xff, 0xc2, 0xac, 0xff, 0xc2, 0xad, 0xff, 0xc2, 0xae,
  0xff, 0xc2, 0xaf, 0xff, 0xc2, 0xb0, 0xff, 0xc2, 0xb1, 0xff, 0xc2, 0xb2, 0xff,
  0xc2, 0xb3, 0xff, 0xc2, 0xb4, 0xff, 0xc2, 0xb5, 0xff, 0xc2, 0xb6, 0xff, 0xc2,
  0xb7, 0xff, 0xc2, 0xb8, 0xff, 0xc2, 0xb9, 0xff, 0xc2, 0xba, 0xff, 0xc2, 0xbb,
  0xff, 0xc2, 0xbc, 0xff, 0xc2, 0xbd, 0xff, 0xc2, 0xbe, 0xff, 0xc2, 0xbf, 0xff,
  0xc3, 0x80, 0xff, 0xc3, 0x81, 0xff, 0xc3, 0x82, 0xff, 0xc3, 0x83, 0xff, 0xc3,
  0x84, 0xff, 0xc3, 0x85, 0xff, 0xc3, 0x86, 0xff, 0xc3, 0x87, 0xff, 0xc3, 0x88,
  0xff, 0xc3, 0x89, 0xff, 0xc3, 0x8a, 0xff, 0xc3, 0x8b, 0xff, 0xc3, 0x8c, 0xff,
  0xc3, 0x8d, 0xff, 0xc3, 0x8e, 0xff, 0xc3, 0x8f, 0xff, 0xc3, 0x90, 0xff, 0xc3,
  0x91, 0xff, 0xc3, 0x92, 0xff, 0xc3, 0x93, 0xff, 0xc3, 0x94, 0xff, 0xc3, 0x95,
  0xff, 0xc3, 0x96, 0xff, 0xc3, 0x97, 0xff, 0xc3, 0x98, 0xff, 0xc3, 0x99, 0xff,
  0xc3, 0x9a, 0xff, 0xc3, 0x9b, 0xff, 0xc3, 0x9c, 0xff, 0xc3, 0x9d, 0xff, 0xc3,
  0x9e, 0xff, 0xc3, 0x9f, 0xff, 0xc3, 0xa0, 0xff, 0xc3, 0xa1, 0xff, 0xc3, 0xa2,
  0xff, 0xc3, 0xa3, 0xff, 0xc3, 0xa4, 0xff, 0xc3, 0xa5, 0xff, 0xc3, 0xa6, 0xff,
  0xc3, 0xa7, 0xff, 0xc3, 0xa8, 0xff, 0xc3, 0xa9, 0xff, 0xc3, 0xaa, 0xff, 0xc3,
  0xab, 0xff, 0xc3, 0xac, 0xff, 0xc3, 0xad, 0xff, 0xc3, 0xae, 0xff, 0xc3, 0xaf,
  0xff, 0xc3, 0xb0, 0xff, 0xc3, 0xb1, 0xff, 0xc3, 0xb2, 0xff, 0xc3, 0xb3, 0xff,
  0xc3, 0xb4, 0xff, 0xc3, 0xb5, 0xff, 0xc3, 0xb6, 0xff, 0xc3, 0xb7, 0xff, 0xc3,
  0xb8, 0xff, 0xc3, 0xb9, 0xff, 0xc3, 0xba, 0xff, 0xc3, 0xbb, 0xff, 0xc3, 0xbc,
  0xff, 0xc3, 0xbd, 0xff, 0xc3, 0xbe, 0xff, 0xff
};

/**
 * @brief Initializes Nighterm terminals and configuration.
 *
 * @param       font
 *              Pointer to a PSF2 font buffer
 *
 * @param       framebuffer_addr
 *              Framebuffer address
 *
 * @param       framebuffer_width
 *              Framebuffer width in pixels
 *
 * @param       framebuffer_height
 *              Framebuffer height in pixelss
 *
 * @param       framebuffer_pitch
 *              Framebuffer Pitch
 *
 * @param       framebuffer_bpp
 *              Framebuffer's Bits per Pixel
 *
 * @param [out] custom_malloc
 *              Pointer to a malloc() function
 *              provided by the host OS
 *
 * @return      NIGHTERM_SUCCESS if the initialization was successful;
 *              error code otherwise. All error codes are defined in nighterm.h.
 */
int
nighterm_initialize(void* font,
                    void* framebuffer_addr,
                    uint64_t framebuffer_width,
                    uint64_t framebuffer_height,
                    uint64_t framebuffer_pitch,
                    uint16_t framebuffer_bpp,
                    void* (*custom_malloc)(size_t))
{
  if (font == NULL) {
    /* No font supplied. */
    font = &nighterm_default_font;
  }

  if (framebuffer_addr == NULL) {
    /* No framebuffer specified, or invalid address. */
    return NIGHTERM_INVALID_FRAMEBUFFER_ADDRESS;
  }

  if (framebuffer_width < 1 || framebuffer_height < 1) {
    /* Invalid framebuffer dimensions. */
    return NIGHTERM_INVALID_FRAMEBUFFER_SIZE;
  }

  if (framebuffer_pitch < 1) {
    /* Invalid framebuffer pitch. */
    return NIGHTERM_INVALID_FRAMEBUFFER_PITCH;
  }

  if (framebuffer_bpp != 32) {
    /* Invalid framebuffer BPP. */
    return NIGHTERM_INVALID_FRAMEBUFFER_BPP;
  }

  char* psf2buf = font;
  psf2Hdr hdr = *(psf2Hdr*)font;
  psf2buf += hdr.headerSize;

  if (PSF_MODE == 2 || PSF_MODE == 1
        ? (hdr.magic[0] != PSF_MAGIC0 || hdr.magic[1] != PSF_MAGIC1 ||
           hdr.magic[2] != PSF_MAGIC2 || hdr.magic[3] != PSF_MAGIC3)
        : 0) {
    return NIGHTERM_FONT_INVALID;
  }

  config.fb_addr = framebuffer_addr;
  config.fb_width = framebuffer_width;
  config.fb_height = framebuffer_height;
  config.fb_pitch = framebuffer_pitch;
  config.fb_bpp = framebuffer_bpp;

  config.current_terminal = 0;
  config.terminal_rows = (config.fb_height / hdr.height);
  config.terminal_cols = (config.fb_width / hdr.width);
  config.terminal[config.current_terminal].font_header = hdr;
  config.terminal[config.current_terminal].font_data = psf2buf;
  config.terminal[config.current_terminal].cur_x = 0;
  config.terminal[config.current_terminal].cur_y = 0;
  config.terminal[config.current_terminal].title = "Nighterm Extended";
  config.terminal[config.current_terminal].fg_color = 0xFFFFFFFF;
  config.terminal[config.current_terminal].bg_color = 0xFF000000;

#ifdef NIGHTERM_MALLOC_IS_AVAILABLE
  if (nighterm_malloc == NULL) {
    return NIGHTERM_MALLOC_IS_NULL;
  }
  nighterm_malloc = custom_malloc;
  config.terminal[config.current_terminal].buffer = nighterm_malloc(
    framebuffer_height * framebuffer_width * (framebuffer_bpp >> 3));
#else
  (void)custom_malloc;
#endif

  return NIGHTERM_SUCCESS;
}

/**
 * @brief Sets foreground (text) color for the currently selected terminal.
 *
 * @param       r
 *              Red color value (0-255)
 *
 * @param       g
 *              Green color value (0-255)
 *
 * @param       b
 *              Blue color value (0-255)
 */
void
nighterm_set_fg_color(uint8_t r, uint8_t g, uint8_t b)
{
  config.terminal[config.current_terminal].fg_color =
    (0xFF << 24) | (r << 16) | (g << 8) | b;
}

/**
 * @brief Sets background color for the currently selected terminal.
 *
 * @param       r
 *              Red color value (0-255)
 *
 * @param       g
 *              Green color value (0-255)
 *
 * @param       b
 *              Blue color value (0-255)
 */
void
nighterm_set_bg_color(uint8_t r, uint8_t g, uint8_t b)
{
  config.terminal[config.current_terminal].bg_color =
    (0xFF << 24) | (r << 16) | (g << 8) | b;
}

/**
 * @brief Sets the cursor to an absolute position.
 *
 * @param       x
 *              Absolute x position
 *
 * @param       y
 *              Absolute y position
 *
 * @todo Check if the coordinates exceed the framebuffer's width/height
 */
void
nighterm_set_cursor_position(uint32_t x, uint32_t y)
{
  config.terminal[config.current_terminal].cur_x = x;
  config.terminal[config.current_terminal].cur_y = y;
}

/**
 * @brief Sets the cursor to a relative position from its current position.
 *
 * @param       x
 *              Relative x position
 *
 * @param       y
 *              Relative y position
 *
 * @todo Check if the coordinates exceed the framebuffer's width/height
 */
void
nighterm_move_cursor(int32_t x, int32_t y)
{
  config.terminal[config.current_terminal].cur_x += x;
  config.terminal[config.current_terminal].cur_y += y;
}

/**
 * @brief Gets the current cursor's coordinates
 *
 * @param ptr   x
 *              X position
 *
 * @param ptr   y
 *              Y position
 */
void
nighterm_get_cursor_position(uint32_t* x, uint32_t* y)
{
  *x = config.terminal[config.current_terminal].cur_x;
  *y = config.terminal[config.current_terminal].cur_y;
}

/**
 * @brief Draws a pixel to the framebuffer.
 *
 * @param       x
 *              X position
 *
 * @param       y
 *              Y position
 *
 * @param       r
 *              Red color value (0-255)
 *
 * @param       g
 *              Green color value (0-255)
 *
 * @param       b
 *              Blue color (0-255)
 */
void
nighterm_priv___putpixel(uint64_t x,
                         uint64_t y,
                         uint8_t r,
                         uint8_t g,
                         uint8_t b)
{
  *(uint32_t*)(config.fb_addr + x * (config.fb_bpp >> 3) +
               y * config.fb_pitch) = (0xFF << 24) | (r << 16) | (g << 8) | b;
}

/**
 * @brief Clears the screen with a single color
 *
 * @param       r
 *              Red color value (0-255)
 *
 * @param       g
 *              Green color value (0-255)
 *
 * @param       b
 *              Blue color value (0-255)
 */
void
nighterm_flush(uint8_t r, uint8_t g, uint8_t b)
{
  for (uint64_t y = 0; y < config.fb_height; y++) {
    for (uint64_t x = 0; x < config.fb_width; x++) {
      nighterm_priv___putpixel(x, y, r, g, b);
    }
  }
}

/**
 * @brief Draws a single character using the currently selected font.
 *
 * @param       row
 *              Character's row
 *
 * @param       col
 *              Character's column
 *
 * @param       c
 *              Character to be drawn
 */
void
nighterm_render_char(int row, int col, char c)
{
  int rounding =
    ((config.terminal[config.current_terminal].font_header.width % 8) != 0) ^
    (config.terminal[config.current_terminal].font_header.width == 9);
  uint8_t* glyph =
    config.terminal[config.current_terminal].font_data +
    c * config.terminal[config.current_terminal].font_header.charSize;

  for (size_t y = 0;
       y < config.terminal[config.current_terminal].font_header.height;
       y++) {
    for (size_t x = 0;
         x < config.terminal[config.current_terminal].font_header.width;
         x++) {
      if ((glyph[y * ((config.terminal[config.current_terminal]
                         .font_header.width /
                       8) +
                      rounding) +
                 x / 8] >>
           (7 - x % 8)) &
          1) {
        uint8_t r =
          (uint8_t)(config.terminal[config.current_terminal].fg_color >> 16) &
          0xFF;
        uint8_t g =
          (uint8_t)(config.terminal[config.current_terminal].fg_color >> 8) &
          0xFF;
        uint8_t b = (uint8_t)config.terminal[config.current_terminal].fg_color;
        nighterm_priv___putpixel(
          col * config.terminal[config.current_terminal].font_header.width + x,
          row * config.terminal[config.current_terminal].font_header.height + y,
          r,
          g,
          b);
      } else {
        uint8_t r =
          (uint8_t)(config.terminal[config.current_terminal].bg_color >> 16) &
          0xFF;
        uint8_t g =
          (uint8_t)(config.terminal[config.current_terminal].bg_color >> 8) &
          0xFF;
        uint8_t b = (uint8_t)config.terminal[config.current_terminal].bg_color;
        nighterm_priv___putpixel(
          col * config.terminal[config.current_terminal].font_header.width + x,
          row * config.terminal[config.current_terminal].font_header.height + y,
          r,
          g,
          b);
      }
    }
  }
}

/**
 * @brief Parses a single character for escape sequences and draws it
 *
 * @param       c
 *              Character to be drawn
 */
void
nighterm_write(char c)
{
  switch (c) {
    case '\n':
      config.terminal[config.current_terminal].cur_x = 0;
      config.terminal[config.current_terminal].cur_y++;
      break;
    case '\t':
      config.terminal[config.current_terminal].cur_x += INDENT_AMOUNT;
      break;
    case '\b':
      nighterm_render_char(config.terminal[config.current_terminal].cur_y,
                           config.terminal[config.current_terminal].cur_x,
                           ' ');

      // this should be handled better
      // for now, try not to use \b.
      config.terminal[config.current_terminal].cur_x -= 1;
      break;
    case 0:
      break; // ignore termination
    default:
      // Why does this not work???
      if (config.terminal[config.current_terminal].cur_x >=
          config.terminal_cols) {
        config.terminal[config.current_terminal].cur_x = 0;
        config.terminal[config.current_terminal].cur_y++;
      }
      nighterm_render_char(config.terminal[config.current_terminal].cur_y,
                           config.terminal[config.current_terminal].cur_x,
                           c);
      config.terminal[config.current_terminal].cur_x++;
      break;
  }
}
