#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <grp.h>

int main(int argc, char **argv) {
  char *path = NULL;
  char *group = NULL;
  gid_t gid;
  path = argv[1];
  group = argv[2];
  if (group[0] >= '0' && group[0] <= '9') {
    gid = (gid_t) atoi(group);
  } else {
    struct group *grp = getgrnam(group);
    gid = grp ? grp->gr_gid : -1;
  }
  if (gid == -1) {
    return 1;
  }
  if (chown(path, -1, gid) != 0) {
    return 1;
  }
  return 0;
}
