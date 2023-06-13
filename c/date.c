#include <stdio.h>
#include <time.h>

int main() {
  time_t current_time;
  struct tm *local_time;
  char time_buffer[80];
  current_time = time(NULL);
  local_time = localtime(&current_time);
  strftime(time_buffer, sizeof(time_buffer), "%a %b %d %H:%M:%S %Z %Y", local_time);
  printf("%s\n", time_buffer);
  return 0;
}
