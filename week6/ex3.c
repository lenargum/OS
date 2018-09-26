#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void sigint_handler() {
    printf("\na\n");
    exit(0);
}

int main() {
    signal(SIGINT,sigint_handler);
    while(1) {
    }
}