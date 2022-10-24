#ifndef LIB_CONTEXT_CONTEXT_H_
#define LIB_CONTEXT_CONTEXT_H_

#include <Arduino.h>
#include "axp20x.h"

typedef struct {
    String baChStatus;
    AXP20X_Class *axp;
    bool pmu_irq;
    bool ssd1306_found;
    bool axp192_found;
} context_t;

extern context_t ctx;

#endif /* LIB_CONTEXT_CONTEXT_H_ */
