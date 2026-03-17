#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Potomek: PID=%d, PPID=%d, PGID=%d\n",
           getpid(), getppid(), getpgrp());
    return 0;
}
