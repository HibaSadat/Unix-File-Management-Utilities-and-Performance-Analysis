#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <output_file>\n", argv[0]);
        return 1;
    }

    const char *outputFileName = argv[1];
    const size_t fileSize = 1024000; 
    char *data = (char *)malloc(fileSize);
    
    if (data == NULL) {
        perror("Failed to allocate memory for data");
        return 1;
    }
    
    for (size_t i = 0; i < fileSize; i++) {
        data[i] = 'A' + rand() % 26;
    }
    
    int outputFile = open(outputFileName, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (outputFile == -1) {
        perror("Failed to open output file");
        free(data);
        return 1;
    }

    ssize_t bytesWritten = write(outputFile, data, fileSize);
    if (bytesWritten == -1) {
        perror("Failed to write to output file");
        free(data);
        close(outputFile);
        return 1;
    }

    if (bytesWritten != fileSize) {
        fprintf(stderr, "Failed to write the full data to the output file\n");
        free(data);
        close(outputFile);
        return 1;
    }

    printf("File '%s' created with a size of %zu bytes.\n", outputFileName, fileSize);
    
    free(data);
    close(outputFile);
    
    return 0;
}     