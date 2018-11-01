#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>


int main() {
    int file1 = open("ex1.txt", O_RDONLY);
    if (file1 < 0) {
        perror("ex1.txt open failure");
        exit(1);
    }
    size_t size = (size_t) lseek(file1, 0, SEEK_END);

    int file2 = open("ex1.memcpy.txt", O_RDWR | O_CREAT | O_TRUNC);
    if (file2 < 0) {
        perror("ex1.memcpy.txt open failure");
        exit(1);
    }

    ftruncate(file2, size);

    char *src = mmap(NULL, size, PROT_READ, MAP_PRIVATE, file1, 0);
    if (src == MAP_FAILED) {
        printf("mmap file1 error\n");
    }

    char *dst = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, file2, 0);
    if (dst == MAP_FAILED) {
        printf("mmap file2 error\n");
    }

    memcpy (dst, src, size);
}
