#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    struct stat path_stat;
    stat(argv[1], &path_stat);

    if (S_ISDIR(path_stat.st_mode)) {
        if (rmdir(argv[1]) != 0) {
            perror("Failed to remove directory");
            return 1;
        }
    } else {
        if (unlink(argv[1]) != 0) {
            perror("Failed to remove file");
            return 1;
        }
    }

    printf("File/Directory removed successfully.\n");
    return 0;
}