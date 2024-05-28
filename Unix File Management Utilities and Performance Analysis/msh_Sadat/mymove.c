#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <oldfilename> <newfilename>\n", argv[0]);
        return 1;
    }

    const char *oldfilename = argv[1];
    const char *newfilename = argv[2];

    // Use the rename function to rename the file
    if (rename(oldfilename, newfilename) != 0) {
        perror("Failed to rename file");
        return 1;
    }

    printf("File renamed successfully.\n");
    return 0;
}