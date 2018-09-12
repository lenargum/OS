#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pid = fork(), n = 1337;
    if (pid > 0) {
        printf("Hello from parent [%d - %d]\n", pid, n);
    } else if (pid == 0) {
        printf("Hello from child [%d - %d]\n", pid, n);
    }
}
