#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char file_path[256];
  if (argc > 1) {
    strncpy(file_path, argv[1], sizeof(file_path));
  } else {
    if (fgets(file_path, sizeof(file_path), stdin) == NULL) {
      perror("Failed to read file path");
      exit(1);
    }
    file_path[strcspn(file_path, "\n")] = '\0';
  }
  if (unlink(file_path) == -1) {
    perror("Failed to remove file");
    exit(1);
  }
  return 0;
}
