#include <stdio.h>

int main(void) {
  char buffer[1024];
  size_t len;
  while ((len = fread(buffer, sizeof(char), sizeof(buffer), stdin)) > 0) {
    fwrite(buffer, sizeof(char), len, stdout);
  }
  return 0;
}
