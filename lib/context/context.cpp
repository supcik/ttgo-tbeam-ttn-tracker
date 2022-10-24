#include "Arduino.h"
#include "context.h"

context_t ctx = {
    .baChStatus = "unknown",
    .axp = NULL,
    .pmu_irq = false,
    .ssd1306_found = false,
    .axp192_found = false
};
