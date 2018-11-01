#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>


int main() {
    int file = open("ex1.txt", O_RDWR);
    if (file < 0) {
        perror("ex1.txt open failure");
        exit(1);
    }

    struct stat file_stat = {};
    if (fstat(file, &file_stat)) {
        perror("fstat error\n");
    }

    off_t size = file_stat.st_size;
    char *string = "This is a nice day";
    char *address = mmap(NULL, strlen(string), PROT_READ | PROT_WRITE, MAP_SHARED, file, 0);
    if (address == MAP_FAILED) {
        printf("mmap error\n");
    }

    size_t len = strlen(address);

    if ((int) len > (int) strlen(string)) {
        memcpy(address, string, (int) strlen(string) * sizeof(char) + 1);
        memset(address + strlen(string) + 1, 0, len - strlen(string));
    } else {
        memcpy(address, string, strlen(string) + 1);
    }
    return 0;
}
