#include "context.h"

#include "Arduino.h"

context_t ctx = {.baChStatus    = "unknown",
                 .axp           = NULL,
                 .pmu_irq       = false,
                 .ssd1306_found = false,
                 .axp192_found  = false};
