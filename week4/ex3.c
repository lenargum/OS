#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    char command[15];
    while (strcmp(command, "exit\n") != 0) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        system(command);
    }
}