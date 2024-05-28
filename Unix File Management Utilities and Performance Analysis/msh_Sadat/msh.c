#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command> [arguments...]\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "./mycopy") == 0) {
        if (fork() == 0) {
            execl(argv[1], argv[1], argv[2], argv[3], NULL);
        }
        wait((int*)0);
        printf("Finished mycopy\n");
    } else if (strcmp(argv[1], "./myremove") == 0) {
        if (fork() == 0) {
            execl(argv[1], argv[1], argv[2], NULL);
        }
        wait((int*)0);
        printf("Finished myremove\n");
    } else if (strcmp(argv[1], "./mymove") == 0) {
        if (fork() == 0) {
            execl(argv[1], argv[1], argv[2], argv[3], NULL);
        }
        wait((int*)0);
        printf("Finished mymove\n");
    } else {
        fprintf(stderr, "Unknown command\n");
        return 1;
    }

    return 0;
}