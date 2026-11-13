#ifndef CONFIG_H
#define CONFIG_H
// All in Celsius

#define TEMPERATURE_64BIT              1
#define CONFIG_BASE_TEMPERATURE_SCALE  SCALE_PICO
#define CONFIG_USE_SCALE_CHANGING      1
#define INCLUDE_TEMPERATURE_CONVERSION 1



#if TEMPERATURE_64BIT
    typedef int64_t temp_t;
#else
    typedef int32_t temp_t;
#endif

#if INCLUDE_TEMPERATURE_CONVERSION
#define TEMP_FAHREN_OFFSET  32
#define TEMP_KELVIN_OFFSET  27315
#endif

#define SCALE_UNIT   1L          // 10^0
#define SCALE_MILLI  1000L       // 10^3
#define SCALE_MICRO  1000000L    // 10^6
#define SCALE_NANO   1000000000L // 10^9
#define SCALE_PICO   1000000000000L // 10^12

#endif