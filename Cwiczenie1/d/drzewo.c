#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    int i;
    // Wypisujemy dane lidera na samym początku
    printf("POKOLENIE 0 (Rodzic): PID=%d, PPID=%d, PGID=%d\n", getpid(), getppid(), getpgrp());
    printf("---------------------------------------------------------------------------\n");

    for (i = 0; i < 3; i++) {
        switch (fork()) {
            case -1:
                perror("fork error");
                exit(1);

            case 0:
                // Potomek zasypia na chwilę, aby rodzic/starsze pokolenie wypisało się pierwsze
                // Każde kolejne pokolenie (i) czeka o 1 sekundę dłużej
                sleep(i + 1);
                printf("POKOLENIE %d: PID=%d, PPID=%d, PGID=%d\n", i + 1, getpid(), getppid(), getpgrp());
                // Zgodnie z (d) nie używamy wait, ale musimy pozwolić na dalsze forki
                break;

            default:
                // Rodzic nie może skończyć się przed dziećmi (zgodnie z instrukcją d)
                // więc na samym końcu damy mu długi sleep
                break;
        }
    }

    // Aby proces macierzysty (i starsze pokolenia) poczekały na najmłodszych:
    sleep(5); 

    return 0;
}
