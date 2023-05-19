#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE* fp;
  if (argc == 1) {
    fp = stdin;
  } else if (argc == 2) {
    fp = fopen(argv[1], "rb");
    if (fp == NULL) {
      perror("Could not open file");
      exit(EXIT_FAILURE);
    }
  } else {
    fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  int c;
  while ((c = fgetc(fp)) != EOF) {
    if (putchar(c) == EOF) {
      perror("Error writing to stdout");
      exit(EXIT_FAILURE);
    }
  }
  if (ferror(fp)) {
    perror("Error reading input");
    exit(EXIT_FAILURE);
  }
  if (argc == 2) {
    fclose(fp);
  }
  return 0;
}
