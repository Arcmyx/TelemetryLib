#include <stdio.h>
#include <inttypes.h>
typedef struct {
  int64_t time : 62;
  int64_t res : 2;
} Timestamp;

typedef enum {
  RES_SEC = 0,
  RES_MS = 1,
  RES_US = -2,
  RES_NS = -1
} TimeResolution;

typedef enum {
  LOG_EMERG, LOG_ALERT, LOG_CRIT, LOG_ERR, LOG_WARNING, LOG_NOTICE, LOG_INFO, LOG_DEBUG
} LogLevel;
typedef struct {
  uint8_t severity : 3; // Follows Syslog standard
  uint8_t facility : 5; // Custom stuff - no enum, user's choice
} Priority;
typedef struct {
  uint64_t magicnumber;
  uint8_t version;
  Timestamp inital_time;
  Priority priority;
} LogHeaderOld;
int main() {
  uint8_t LogHeader[18] = {0x7f, 0x4C, 0x4F, 0x47, 0x46, 0x55, 0x4E, 0x19}; // ?LOGFUN?
  printf("Size of Timestamp: %zu bytes\n", sizeof(Timestamp));
  printf("Size of LogLevel: %zu bytes\n", sizeof(LogLevel));
  printf("Size of old LogHeader: %zu bytes\n", sizeof(LogHeaderOld));
  printf("Size LogHeader should be: %zu bytes\n", sizeof(uint64_t) + sizeof(uint8_t) + sizeof(Timestamp) + sizeof(Priority));
  printf("Size of new LogHeader: %zu bytes\n", sizeof(LogHeader));
  return 0;
}