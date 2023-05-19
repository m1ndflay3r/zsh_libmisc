#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  char file_path[256];
  struct stat file_info;
  struct passwd *owner_info;
  struct group *group_info;
  time_t mod_time;
  char *mod_time_str;
  if (argc > 1) {
    strncpy(file_path, argv[1], sizeof(file_path));
  } else {
    if (fgets(file_path, sizeof(file_path), stdin) == NULL) {
      perror("Fatal: fetch file path failed");
      exit(1);
    }
    file_path[strcspn(file_path, "\n")] = '\0';
  }
  if (stat(file_path, &file_info) == -1) {
    perror("Fatal: fetch file info failed");
    exit(1);
  }
  owner_info = getpwuid(file_info.st_uid);
  group_info = getgrgid(file_info.st_gid);
  mod_time = file_info.st_mtime;
  mod_time_str = ctime(&mod_time);
  printf("Path : %s\n", file_path);
  printf("Size : %ld bytes\n", file_info.st_size);
  printf("Mode : %o\n", file_info.st_mode & 0777);
  printf("Owner: %s (UID=%d)\n", owner_info->pw_name, file_info.st_uid);
  printf("Group: %s (GID=%d)\n", group_info->gr_name, file_info.st_gid);
  printf("Modif: %s", mod_time_str);
  printf("Inode: %ld\n", file_info.st_ino);
  printf("Hrdln: %u\n", file_info.st_nlink);
  printf("FSID : %ld\n", file_info.st_dev);
  printf("BlkSi: %d bytes\n", file_info.st_blksize);
  printf("Blknm: %ld\n", file_info.st_blocks);
  return 0;
}
