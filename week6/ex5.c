#include <stdlib.h>
#include <unistd.h>
#include <memory.h>
#include <stdio.h>
#include <signal.h>

void sigterm_handler() {
    printf("\nChild: Guess I'll die\n");
    exit(0);
}

int main() {
    int pipi[2];


    pipe(pipi);
    int pid = fork();
    signal(SIGTERM,sigterm_handler);

    if(pid != 0) {
        read(pipi[0],&pid, sizeof(pid));
        close(pipi[0]);
        sleep(10);
        printf("Parent: *stabs child %d*\n",pid);
        kill(pid,SIGTERM);
    } else {

        write(pipi[1],&pid, sizeof(pid));
        close(pipi[1]);
        while(1) {
            printf("Child: I'm alive!\n");
            sleep(1);
        }
    }
}