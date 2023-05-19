#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv) {
  char *fifo_name = argv[1];
  int ret = mkfifo(fifo_name, 0755);
  if (ret == -1) {
    perror("mkfifo");
    exit(EXIT_FAILURE);
  }
  return 0;
}
