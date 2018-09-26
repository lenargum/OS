#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void sigkill_handler() {
    printf("\n*process bleeding and dies\n");
    exit(0);
}

void sigstop_handler() {
    printf("\na\n*process stops*\n");
    exit(0);
}

void sigusr1_handler() {
    printf("\na\n*what*\n");
    exit(0);
}

int main() {
    signal(SIGKILL,sigkill_handler);
    signal(SIGSTOP,sigstop_handler);
    signal(SIGUSR1,sigusr1_handler);
    while(1) {
    }
}