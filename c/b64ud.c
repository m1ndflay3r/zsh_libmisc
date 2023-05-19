#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <stdbool.h>
#define B64_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
#define B16_CHARS "0123456789abcdef"

void b64tobin(const char *zb64str, char *zb16str) {
  size_t b64_len = strlen(zb64str);
  size_t hex_len = b64_len * 3 / 4;
  uint8_t bytes[hex_len];
  size_t bytes_len = 0;
  for (size_t i = 0; i < b64_len; i += 4) {
    uint32_t b64_block = 0;
    for (size_t j = 0; j < 4; j++) {
      b64_block <<= 6;
      if (zb64str[i+j] != '=') {
        const char* ptr = strchr(B64_CHARS, zb64str[i+j]);
        if (ptr != NULL) {
            b64_block |= (ptr - B64_CHARS);
        } else {
          fprintf(stderr, "Err: %c is not a valid b64 char\n", zb64str[i+j]);
          exit(EXIT_FAILURE);
        }
      }
    }
    for (int j = 2; j >= 0; j--) {
      bytes[bytes_len++] = (b64_block >> (j * 8)) & 0xFF;
    }
  }
  for (size_t i = 0; i < hex_len; i++) {
    zb16str[i * 2] = B16_CHARS[(bytes[i] >> 4) & 0xF];
    zb16str[i * 2 + 1] = B16_CHARS[bytes[i] & 0xF];
  }
  zb16str[hex_len * 2] = '\0';
}

int main(int argc, char *argv[]) {
  char *zb64str = argv[1];
  char zb16str[strlen(zb64str) * 3 / 4 + 1];
  b64tobin(zb64str, zb16str);
  printf("%s\n", zb16str);
  return EXIT_SUCCESS;
}
