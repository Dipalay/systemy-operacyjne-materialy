#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int i;

    if (argc < 2) {
        printf("Użycie: %s program_potomny\n", argv[0]);
        exit(1);
    }

    printf("Proces macierzysty: PID=%d\n", getpid());
    printf("--------------------------------------\n");

    for (i = 0; i < 3; i++) {
        switch (fork()) {
            case -1:
                perror("fork error");
                exit(1);

            case 0:
                // uruchamiamy zewnętrzny program
                execlp(argv[1], argv[1], NULL);

                // jeśli execlp się nie uda
                perror("execlp error");
                _exit(2);

            default:
                break;
        }
    }

    for (i = 0; i < 3; i++) {
        wait(NULL);
    }

    return 0;
}
