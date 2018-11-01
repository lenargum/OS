#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    setvbuf(stdout, 0, _IOLBF, 6);
    printf("%c", 'h');
    sleep(1);
    printf("%c", 'e');
    sleep(1);
    printf("%c", 'l');
    sleep(1);
    printf("%c", 'l');
    sleep(1);
    printf("%c\n", 'o');
    sleep(1);
}