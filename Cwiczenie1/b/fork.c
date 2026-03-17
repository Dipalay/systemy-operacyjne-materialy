#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
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
        exit(1);
      case 0:
        printf("Potomek (iteracja %d): PID=%d, PPID=%d, PGID=%d\n",i+1,getpid(),getppid(),getpgrp());
        break;
      default:
        break;
    }
  }
  for(i=0;i<3;i++) {
    if(wait(NULL)==-1) {
      perror("wait error");
    }
  }
  return 0;
}
