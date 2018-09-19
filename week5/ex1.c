#include <pthread.h>
#include <stdio.h>

int variable = 0;

void *threadFunc() {
    printf("threadFunc says: %d\n", variable++);
    return NULL;
}

int main(void) {
    printf("Enter the number of threads: ");
    int n;
    scanf("%d", &n);
    pthread_t pth;
    for (int i = 1; i <= n; i++) {
        printf("Thread number %d created!\n", i);
        pthread_create(&pth, NULL, threadFunc, NULL);
        pthread_join(pth, NULL);    //(second part of task) remove this line to get solution for first part of the task
    }
    pthread_exit(NULL);
}