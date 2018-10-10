#include <stdlib.h>
#include <memory.h>
#include <unistd.h>

int main() {
    size_t tenByte = 1024*1024*10;
    for(int i = 0;i <10;i++) {
        int* mem = (int*)malloc(tenByte);
        memset(mem,0, tenByte);
        sleep(1);
    }
}