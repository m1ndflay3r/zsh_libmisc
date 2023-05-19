#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
  int src_fd, dst_fd, n;
  char buf[4096];
  struct stat src_stat;
  if (stat(argv[1], &src_stat) < 0) {
    fprintf(stderr, "Error: Could not get stat for '%s': %s\n", argv[1], strerror(errno));
    return EXIT_FAILURE;
  }
  if ((src_fd = open(argv[1], O_RDONLY)) < 0) {
    fprintf(stderr, "Error: Could not open '%s' for reading: %s\n", argv[1], strerror(errno));
    return EXIT_FAILURE;
  }
  if ((dst_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, src_stat.st_mode)) < 0) {
    fprintf(stderr, "Error: Could not open '%s' for writing: %s\n", argv[2], strerror(errno));
    return EXIT_FAILURE;
  }
  while ((n = read(src_fd, buf, sizeof(buf))) > 0) {
    if (write(dst_fd, buf, n) != n) {
      fprintf(stderr, "Error: Failed to write all bytes to '%s': %s\n", argv[2], strerror(errno));
      close(src_fd);
      close(dst_fd);
      return EXIT_FAILURE;
    }
  }
  if (n < 0) {
    fprintf(stderr, "Error: Failed to read from '%s': %s\n", argv[1], strerror(errno));
    close(src_fd);
    close(dst_fd);
    return EXIT_FAILURE;
  }
  close(src_fd);
  close(dst_fd);
  return EXIT_SUCCESS;
}
