#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
  printf("Identyfikatory bieżącego procesu:\n");
  printf("-------------------------------------------\n");
  //Pobieranie identyfikatorów:
  printf("UID: %d\n", getuid());
  printf("GID: %d\n", getgid());
  printf("PID: %d\n", getpid());
  printf("PPID: %d\n", getppid());
  printf("PGID: %d\n", getpgrp());

  return 0;
}
  
  
