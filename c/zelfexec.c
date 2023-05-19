#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <sys/wait.h>
#include <time.h>
#ifndef SYS_memfd_create
  #error "Fatal: linux < 3.17, or memfd_create disabled at build time"
#endif
#ifndef FKINCHONKSBRUH
  #define FKINCHONKSBRUH (8 * 1024)
#endif
#ifndef MYNAMEISWHAT
  #define MYNAMEISWHAT rand_str()
#endif

char* rand_str() {
  static char str[12];
  srand(time(NULL));
  int rand_num = rand();
  sprintf(str, "%d", rand_num);
  return str;
}

int exit_failure(const char* msg){perror(msg);return EXIT_FAILURE;}

int main(int argc, char* argv[]){
  int memfd;
  ssize_t nread, nwrite;
  size_t offset, length;
  char buf[FKINCHONKSBRUH];
  char *fifo_path = getenv("zELFEXECPIPE");
  if (fifo_path == NULL || strlen(fifo_path) == 0) {
    return exit_failure("zELFEXECPIPE not set");
  }
  memfd = (int)syscall(SYS_memfd_create, MYNAMEISWHAT, 0);
  if (memfd == -1)return exit_failure("fail: memfd_create");
  do {
    nread = read(STDIN_FILENO, buf, FKINCHONKSBRUH);
    if (nread == -1)return exit_failure("fail: read");
    offset = 0;
    length = (size_t)nread;
    while (offset < length) {
      nwrite = write(memfd, buf + offset, length - offset);
      if (nwrite == -1)return exit_failure("fail: write");
      offset += (size_t)nwrite;
    }
  } while (nread > 0);
    pid_t pid;
    pid = fork();
    if (pid < 0) {
      return exit_failure("fail: fork");
    } else if (pid == 0) {
      int fifo_fd = open(fifo_path, O_RDONLY);
      if (fifo_fd == -1) {
        return exit_failure("fail: open");
      }
      if (dup2(fifo_fd, STDIN_FILENO) == -1) {
        return exit_failure("fail: dup2");
      }
      char *zELFSPOOF = getenv("zELFSPOOF");
      if (zELFSPOOF != NULL && strlen(zELFSPOOF) > 0) {
        argv[0] = zELFSPOOF;
      }
      extern char** environ;
      if (fexecve(memfd, argv, environ) == -1) {
        return exit_failure("fail: fexecve");
      }
      return EXIT_SUCCESS;
    } else {
      int status;
      waitpid(pid, &status, 0);
    if (WIFEXITED(status)) {
      return WEXITSTATUS(status);
    } else {
      return exit_failure("child process returned non-zero");
    }
  }
}
