#include <stdlib.h>
#include <unistd.h>
#include <memory.h>
#include <stdio.h>
#include <signal.h>
#include <wait.h>

void sigstop_handler() {
    exit(0);
}

int main() {
    int pipi[2];
    int pipi2[2];
    signal(SIGSTOP,sigstop_handler);

    pipe(pipi);

    int pid = fork();


    if(pid != 0) {
        //parent
        printf("Parent: My pid is %d\n",getpid());

        read(pipi2[0],&pid, sizeof(pid));
        close(pipi2[0]);

        printf("Parent: Waiting for stop of child 2\n");
        waitpid(pid,0,0);
        printf("Parent: Looks like child 2 stopped\n");
        sleep(2);
        printf("Parent: oh, child 2 is dead\n");

    } else {

        if(fork() == 0) {
            //child 2

            printf("Child 2: I am alive!\n");
            int child2_pid = getpid();
            write(pipi[1],&child2_pid, sizeof(child2_pid));
            close(pipi[1]);
            printf("Child 2: My pid is %d\n",child2_pid);

        } else {
            //child 1
            printf("Child 1: I am alive!\n");
            int child1_pid = getpid();
            printf("Child 1: My pid is %d\n",child1_pid);


            read(pipi[0],&pid, sizeof(pid));
            close(pipi[0]);
            write(pipi2[1],&pid,sizeof(pid));
            close(pipi2[1]);

            sleep(2);
            printf("Child 1: Child 2, stop!\n");
            kill(pid, SIGSTOP);
        }
    }
}