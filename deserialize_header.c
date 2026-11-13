#include <stdio.h>
#include <inttypes.h>
#include "lib.h"

void deserializeVersion(Version xVersion, uint8_t *header) {
  uint16_t versionpacked = (((uint16_t)(xVersion.major & 0x3F)) << 10) |
                           (((uint16_t)(xVersion.minor & 0x1F)) << 5)  |
                           ((uint16_t)(xVersion.patch & 0x1F));
  // printf("%" PRIu16 "\n", versionpacked);
  header[6] = versionpacked & 0xFF;
  header[7] = (versionpacked >> 8) & 0xFF;
}

void deserializeTimestamp(int64_t xTimestamp, uint8_t *header) {
  uint64_t packed = (uint64_t)xTimestamp;
  header[8]  = (packed >> 0)  & 0xFF;
  header[9]  = (packed >> 8)  & 0xFF;
  header[10] = (packed >> 16) & 0xFF;
  header[11] = (packed >> 24) & 0xFF;
  header[12] = (packed >> 32) & 0xFF;
  header[13] = (packed >> 40) & 0xFF;
  header[14] = (packed >> 48) & 0xFF;
  header[15] = (packed >> 56) & 0xFF;
}

int mainDH() {
  Version version = {1, 0, 0};
  uint8_t LogHeader[16] = {0x7f, 0x4C, 0x47, 0x46, 0x4E, 0x19}; // ?LGFN?
  int64_t timestamp = 0xCAFEBABE;
  deserializeVersion(version, LogHeader);
  deserializeTimestamp(timestamp, LogHeader);
  for(int i = 0; i < 16; i++) {
    printf("%" PRIu8 ", ", LogHeader[i]);
  }
  printf("\nSize of new LogHeader: %zu bytes", sizeof(LogHeader));
  return 0;
}