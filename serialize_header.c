#include <stdio.h>
#include <inttypes.h>
#include "lib.h"

void print_bin(unsigned int n, int num_bits) {
    for (int i = num_bits - 1; i >= 0; i--) {
        int bit = (n >> i) & 1;
        putchar(bit ? '1' : '0');
    }
    putchar('\n');
}

void serializeVersion(Version xVersion, uint8_t *header) {
  uint16_t versionpacked = (((uint16_t)(xVersion.major & 0x3F)) << 10) |
                           (((uint16_t)(xVersion.minor & 0x1F)) << 5)  |
                           ((uint16_t)(xVersion.patch & 0x1F));
  // printf("%" PRIu16 "\n", versionpacked);
  header[6] = versionpacked & 0xFF;
  header[7] = (versionpacked >> 8) & 0xFF;
}

void serializeTimestamp(int64_t timestamp, uint8_t *header) {
  uint64_t packed = (uint64_t)timestamp;
  header[8]  = (packed >> 0)  & 0xFF;
  header[9]  = (packed >> 8)  & 0xFF;
  header[10] = (packed >> 16) & 0xFF;
  header[11] = (packed >> 24) & 0xFF;
  header[12] = (packed >> 32) & 0xFF;
  header[13] = (packed >> 40) & 0xFF;
  header[14] = (packed >> 48) & 0xFF;
  header[15] = (packed >> 56) & 0xFF;
}

void serializeConfig(uint8_t resolution, uint8_t epoch, uint8_t *header) {
    uint8_t config = 0b00000000;
    config |= ((resolution & 0b11) << 0); 
    config |= ((epoch & 0b11) << 2);      
    print_bin(config, 8);
    header[5] = config;
}


int mainSH() {
  Version version = {1, 0, 0};
  uint8_t SerializedHeader[16] = {0x7f, 0x4C, 0x47, 0x53, 0x19}; // ?LGS?
  int64_t timestamp = 1793894085;
  serializeVersion(version, SerializedHeader);
  serializeTimestamp(timestamp, SerializedHeader);
  serializeConfig(TIMERES_MS, Y2K, SerializedHeader);
  for(int i = 0; i < 16; i++) {
    printf("%" PRIu8 ", ", SerializedHeader[i]);
  }
  // printf("\nSize of new SerializedHeader: %zu bytes", sizeof(SerializedHeader));
  return 0;
}