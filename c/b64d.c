#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "b64.h"

void b16tobin(const char *zb16str, unsigned char *bytes, size_t len) {
  for (size_t i = 0; i < len; i++) {
    sscanf(zb16str + 2 * i, "%2hhx", &bytes[i]);
  }
}

void bintob64(const unsigned char *bytes, size_t len, char *zb64str) {
  size_t i, j;
  unsigned char a, b, c;
  for (i = 0, j = 0; i < len; i += 3, j += 4) {
    a = bytes[i];
    b = (i + 1 < len) ? bytes[i + 1] : 0;
    c = (i + 2 < len) ? bytes[i + 2] : 0;
    zb64str[j] = lookup[a >> 2];
    zb64str[j + 1] = lookup[((a & 0x03) << 4) | ((b & 0xf0) >> 4)];
    zb64str[j + 2] = (i + 1 < len) ? lookup[((b & 0x0f) << 2) | ((c & 0xc0) >> 6)] : '=';
    zb64str[j + 3] = (i + 2 < len) ? lookup[c & 0x3f] : '=';
  }
  zb64str[j] = '\0';
}

int main() {
  char zb16str[1024];
  unsigned char bytes[512];
  char zb64str[1024];
  size_t len;
  len = fread(zb16str, 1, sizeof(zb16str), stdin);
  b16tobin(zb16str, bytes, len / 2);
  bintob64(bytes, len / 2, zb64str);
  printf("%s\n", zb64str);
  return 0;
}
