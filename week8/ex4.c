#include <stdlib.h>
#include <memory.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/resource.h>

int main() {
    size_t tenByte = 1024*1024*10;
    struct rusage rusage1;
    for(int i = 0;i <10;i++) {
        int* mem = (int*)malloc(tenByte);
        memset(mem,0, tenByte);
        getrusage(RUSAGE_SELF,&rusage1);
        printf("Memory usage: %ld\n",rusage1.ru_maxrss);
        sleep(1);
    }
}