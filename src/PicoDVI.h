#pragma once

#include "pico/stdlib.h"   // In Pico SDK
#include "hardware/vreg.h" // In Pico SDK
#include "libdvi/dvi.h"    // Requires soft link in src to ../software/libdvi
#include "libdvi/dvi_timing.h"
#include "../software/include/common_dvi_pin_configs.h"
// Also, one must build PicoDVI via the usual route (mkdir build & cmake, etc.)
// and copy dvi_serialiser.pio.h to libdvi. 'build' is in .gitignore and
// doesn't get included w/push.

class PicoDVI {
public:
  PicoDVI(uint16_t w, uint16_t h, vreg_voltage v, const struct dvi_timing &t, const struct dvi_serialiser_cfg &c);
  ~PicoDVI(void);
  bool begin(void);
private:
  uint16_t *framebuf = NULL;
  uint16_t framebuf_width;
  uint16_t framebuf_height;
  struct dvi_inst dvi0;
  const struct dvi_timing *timing;
  vreg_voltage voltage;
  const struct dvi_serialiser_cfg *cfg;
};