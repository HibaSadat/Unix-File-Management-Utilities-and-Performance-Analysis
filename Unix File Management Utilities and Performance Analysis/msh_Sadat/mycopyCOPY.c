#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF_SIZE 4096
#define OUTPUT_MODE 0700 

int main(int argc, char *argv[]) {
    int in_fd, out_fd;
    ssize_t rd_count, wt_count;
    char buffer[BUF_SIZE];

    if (argc != 3) {
        exit(1); 
    }

    in_fd = open(argv[1], O_RDONLY);
    if (in_fd < 0) exit(2); 

    out_fd = creat(argv[2], OUTPUT_MODE);
    if (out_fd < 0) exit(3); 

    while ((rd_count = read(in_fd, buffer, BUF_SIZE)) > 0) {
        wt_count = write(out_fd, buffer, rd_count);
        if (wt_count <= 0) exit(4); 
    }

    close(in_fd);
    close(out_fd);

    if (rd_count == 0)
        exit(0); 
    else
        exit(5); 
}