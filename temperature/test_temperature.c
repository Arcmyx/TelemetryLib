#include <stdio.h>
#include <inttypes.h>
#include "temperature.h"
int mainn() {
    printf("%" PRId64 "\n", temp_c_to_f(25000000000000, SCALE_PICO, SCALE_UNIT));
    return 0;
}