#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
  int i;
  printf("Proces macierzysty: PID=%d, PPID=%d,PGID=%d\n",getpid(),getppid(),getpgrp());
  printf("------------------------------------------------------------\n");
  for(i=0;i<3;i++) {
    switch(fork()) {
      case -1:
        perror("fork error");
        exit(EXIT_FAILURE);
      case 0:
        sleep(5);
        printf("Potomek (iteracja %d): PID=%d, NOWY PPID=%d, PGID=%d\n",i+1,getpid(),getppid(),getpgrp());
        break;
      default:
        break;
    }
  }
  if(getpid()!=0) {
    printf("Proces macierzysty kończy działanie i osieroca potomków\n");
  }
  return 0;
}
