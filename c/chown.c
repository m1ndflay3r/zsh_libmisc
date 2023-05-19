#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char file_path[256];
  uid_t user_id;
  gid_t group_id;
  if (argc > 2) {
    strncpy(file_path, argv[2], sizeof(file_path));
    user_id = strtol(argv[1], NULL, 10);
    group_id = strtol(argv[2], NULL, 10);
  } else {
    if (fgets(file_path, sizeof(file_path), stdin) == NULL) {
      perror("Failed to read file path");
      exit(1);
    }
    file_path[strcspn(file_path, "\n")] = '\0';
    char user_id_str[16];
    if (fgets(user_id_str, sizeof(user_id_str), stdin) == NULL) {
      perror("Failed to read user ID");
      exit(1);
    }
    user_id_str[strcspn(user_id_str, "\n")] = '\0';
    user_id = strtol(user_id_str, NULL, 10);
    char group_id_str[16];
    if (fgets(group_id_str, sizeof(group_id_str), stdin) == NULL) {
      perror("Failed to read group ID");
      exit(1);
    }
    group_id_str[strcspn(group_id_str, "\n")] = '\0';
    group_id = strtol(group_id_str, NULL, 10);
  }
  if (chown(file_path, user_id, group_id) == -1) {
    perror("Failed to change file owner/group");
    exit(1);
  }
  return 0;
}
