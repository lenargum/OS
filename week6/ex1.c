#include <stdlib.h>
#include <unistd.h>
#include <memory.h>
#include <stdio.h>

int main() {
    int pipi[2];

    char string[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    char second_string[] = "";
    pipe(pipi);
    write(pipi[1],string,strlen(string));
    close(pipi[1]);
    read(pipi[0],second_string, strlen(string));
    close(pipi[0]);
    printf("%s",second_string);
}