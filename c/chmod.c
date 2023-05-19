#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char file_path[256];
  mode_t file_mode;
  if (argc > 2) {
    strncpy(file_path, argv[2], sizeof(file_path));
    file_mode = strtol(argv[1], NULL, 8);
  } else {
    if (fgets(file_path, sizeof(file_path), stdin) == NULL) {
      perror("Failed to read file path");
      exit(1);
    }
    file_path[strcspn(file_path, "\n")] = '\0';
    char mode_str[8];
    if (fgets(mode_str, sizeof(mode_str), stdin) == NULL) {
      perror("Failed to read file mode");
      exit(1);
    }
    mode_str[strcspn(mode_str, "\n")] = '\0';
    file_mode = strtol(mode_str, NULL, 8);
  }
  if (chmod(file_path, file_mode) == -1) {
    perror("Failed to change file mode");
    exit(1);
  }
  return 0;
}
