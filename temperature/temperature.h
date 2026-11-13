#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "../config.h"
#if INCLUDE_TEMPERATURE_CONVERSION
// 1. Celsius -> Fahrenheit
static inline temp_t temp_c_to_f(temp_t c_val
#if CONFIG_USE_SCALE_CHANGING
    , temp_t src_scale, temp_t dst_scale
#endif
) {
#if CONFIG_USE_SCALE_CHANGING
    temp_t scaled_offset = 32 * dst_scale;
    return ((c_val * 9 * dst_scale) / (5 * src_scale)) + scaled_offset;
#else
    return ((c_val * 9) / 5) + (32 * CONFIG_BASE_TEMPERATURE_SCALE);
#endif
}

// 2. Fahrenheit -> Celsius
static inline temp_t temp_f_to_c(temp_t f_val
#if CONFIG_USE_SCALE_CHANGING
    , temp_t src_scale, temp_t dst_scale
#endif
) {
#if CONFIG_USE_SCALE_CHANGING
    temp_t unscaled_offset = 32 * src_scale;
    return ((f_val - unscaled_offset) * 5 * dst_scale) / (9 * src_scale);
#else
    return ((f_val - (32 * CONFIG_BASE_TEMPERATURE_SCALE)) * 5) / 9;
#endif
}

// 3. Celsius -> Kelvin
static inline temp_t temp_c_to_k(temp_t c_val
#if CONFIG_USE_SCALE_CHANGING
    , temp_t src_scale, temp_t dst_scale
#endif
) {
#if CONFIG_USE_SCALE_CHANGING
    temp_t scaled_offset = (27315 * dst_scale) / 100;
    return ((c_val * dst_scale) / src_scale) + scaled_offset;
#else
    return c_val + ((27315 * CONFIG_BASE_TEMPERATURE_SCALE) / 100);
#endif
}

// 4. Kelvin -> Celsius
static inline temp_t temp_k_to_c(temp_t k_val
#if CONFIG_USE_SCALE_CHANGING
    , temp_t src_scale, temp_t dst_scale
#endif
) {
#if CONFIG_USE_SCALE_CHANGING
    temp_t unscaled_offset = (27315 * src_scale) / 100;
    return ((k_val - unscaled_offset) * dst_scale) / src_scale;
#else
    return k_val - ((27315 * CONFIG_BASE_TEMPERATURE_SCALE) / 100);
#endif
}

// 5. Fahrenheit -> Kelvin
static inline temp_t temp_f_to_k(temp_t f_val
#if CONFIG_USE_SCALE_CHANGING
    , temp_t src_scale, temp_t dst_scale
#endif
) {
#if CONFIG_USE_SCALE_CHANGING
    temp_t unscaled_f_offset = 32 * src_scale;
    temp_t scaled_k_offset   = (27315 * dst_scale) / 100;
    return (((f_val - unscaled_f_offset) * 5 * dst_scale) / (9 * src_scale)) + scaled_k_offset;
#else
    temp_t unscaled_f_offset = 32 * CONFIG_BASE_TEMPERATURE_SCALE;
    temp_t scaled_k_offset   = (27315 * CONFIG_BASE_TEMPERATURE_SCALE) / 100;
    return (((f_val - unscaled_f_offset) * 5) / 9) + scaled_k_offset;
#endif
}

// 6. Kelvin -> Fahrenheit
static inline temp_t temp_k_to_f(temp_t k_val
#if CONFIG_USE_SCALE_CHANGING
    , temp_t src_scale, temp_t dst_scale
#endif
) {
#if CONFIG_USE_SCALE_CHANGING
    temp_t unscaled_k_offset = (27315 * src_scale) / 100;
    temp_t scaled_f_offset   = 32 * dst_scale;
    return (((k_val - unscaled_k_offset) * 9 * dst_scale) / (5 * src_scale)) + scaled_f_offset;
#else
    temp_t unscaled_k_offset = (27315 * CONFIG_BASE_TEMPERATURE_SCALE) / 100;
    temp_t scaled_f_offset   = 32 * CONFIG_BASE_TEMPERATURE_SCALE;
    return (((k_val - unscaled_k_offset) * 9) / 5) + scaled_f_offset;
#endif
}
#endif

#endif