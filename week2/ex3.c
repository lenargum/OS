#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if(argc<=1) {
        printf("No arguments found");
        exit(1);
    }
    int n = atoi(argv[1]);
    int spaces = n-1;
    for(int i = 1;i<=n;i++) {
        for(int sp = spaces;sp>0;sp--) {
            printf(" ");
        }
        spaces--;
        for(int st = 0;st<2*i-1;st++) {
            printf("*");
        }
        printf("\n");
    }
}