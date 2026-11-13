#ifndef LIB_H
#define LIB_H

#include "config.h"
#include "temperature/temperature.h"
typedef struct {
  uint16_t major : 6;
  uint16_t minor : 5;
  uint16_t patch : 5;
} Version;

typedef enum {
  TIMERES_SEC = 0,
  TIMERES_MS = 1,
  TIMERES_US = 2,
  TIMERES_NS = 3
} TimeResolution;

typedef enum {
  UNIX_EPOCH = 0,
  Y2K = 1,
  Y2K26 = 2
} Epoch;

typedef enum {
  LOG_EMERG, LOG_ALERT, LOG_CRIT, LOG_ERR, LOG_WARNING, LOG_NOTICE, LOG_INFO, LOG_DEBUG
} LogLevel;

typedef struct {
  uint8_t severity : 3; // Follows Syslog standard - enum LogLevel
  uint8_t facility : 5; // Custom stuff - no enum, user's choice
} Priority;

typedef struct {
  int64_t timestamp;
  Version version;
  uint8_t config_resolution;
  uint8_t config_epoch;
} Header;

typedef union {
  #if TEMPERATURE_64BIT
  int64_t temperature_hiprec;
  #else
  int32_t temperature_loprec;
  #endif
} Message;
typedef struct {
  uint64_t timestamp;
  Priority priority;
  Message message;
} Entry;

#endif