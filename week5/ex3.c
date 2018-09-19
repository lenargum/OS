#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex;
pthread_cond_t condc, condp;
int buff = 0;
int i = 1;

void *producer(void *ptr)
{
    while(1){
        while(buff == 10)
            pthread_cond_wait(&condp,&mutex);
        i = i + 1;
        buff = i;
        printf("Producer produced %d\n", i);
        pthread_cond_signal(&condc);
    }
}

void *consumer(void *ptr)
{
    while(1){
        while(buff == 0)
            pthread_cond_wait(&condc,&mutex);
        i = i - 1;
        buff = i;
        printf("Consumer takes %d\n",buff);
        pthread_cond_signal(&condp);
    }
}

int main(int argc, char **argv){
    pthread_t pro, con;
    pthread_cond_init(&condc, 0);
    pthread_cond_init(&condp, 0);
    pthread_create(&con, 0, consumer, 0);
    pthread_create(&pro, 0, producer, 0);
    pthread_join(pro, 0);
    pthread_join(con, 0);
    pthread_cond_destroy(&condc);
    pthread_cond_destroy(&condp);
}