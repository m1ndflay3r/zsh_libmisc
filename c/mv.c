#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char src_path[256];
  char dest_path[256];
  if (argc > 2) {
    strncpy(src_path, argv[1], sizeof(src_path));
    strncpy(dest_path, argv[2], sizeof(dest_path));
  } else {
    if (fgets(src_path, sizeof(src_path), stdin) == NULL) {
      perror("Failed to read source path");
      exit(1);
    }
    src_path[strcspn(src_path, "\n")] = '\0';
    if (fgets(dest_path, sizeof(dest_path), stdin) == NULL) {
      perror("Failed to read destination path");
      exit(1);
    }
    dest_path[strcspn(dest_path, "\n")] = '\0';
  }
  if (rename(src_path, dest_path) == -1) {
    perror("Failed to move file");
    exit(1);
  }
  return 0;
}
