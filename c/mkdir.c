#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
  char dir_path[256];
  if (argc > 1) {
    strncpy(dir_path, argv[1], sizeof(dir_path));
  } else {
    if (fgets(dir_path, sizeof(dir_path), stdin) == NULL) {
      perror("Failed to read directory path");
      exit(1);
    }
    dir_path[strcspn(dir_path, "\n")] = '\0';
  }
  if (mkdir(dir_path, 0777) == -1) {
    perror("Failed to create directory");
    exit(1);
  }
  return 0;
}
