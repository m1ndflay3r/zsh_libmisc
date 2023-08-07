#define _ALL_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
  if (argc < 3 || argc > 4) {
    fprintf(stderr, "Usage: %s [-s] source target\n", argv[0]);
    return 1;
  }
  int symbolic = 0;
  if (argc == 4 && strcmp(argv[1], "-s") == 0) {
    symbolic = 1;
    argv++;
  }
  const char *source = argv[1];
  const char *target = argv[2];
  struct stat source_stat;
  if (lstat(source, &source_stat) == -1) {
    perror("lstat");
    return 1;
  }
  if (symbolic) {
    if (symlink(source, target) == -1) {
      perror("symlink");
      return 1;
    }
  } else {
    if (link(source, target) == -1) {
      perror("link");
      return 1;
    }
  }
  return 0;
}
