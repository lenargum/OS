#include <stdio.h>
#include <stdlib.h>

void fig0(int n) {
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

void fig1(int n) {
    for(int i = 1;i<=n;i++) {
        for(int st = 0;st<i;st++) {
            printf("*");
        }
        printf("\n");
    }
}

void fig2(int n) {
    for(int i = 1;i<=n/2;i++) {
        for(int st = 0;st<i;st++) {
            printf("*");
        }
        printf("\n");
    }
    if(n%2==1) {
        for(int st = 0;st<n/2+1;st++) {
            printf("*");
        }
        printf("\n");
    }
    for(int i = n/2;i>=0;i--) {
        for(int st = 0;st<i;st++) {
            printf("*");
        }
        printf("\n");
    }
}

void fig3(int n) {
    for(int i = 1;i<=n;i++) {
        for(int st = 0;st<n;st++) {
            printf("*");
        }
        printf("\n");
    }
}

//first argument is height, second is number of figure
int main(int argc, char* argv[]) {
    if(argc<=1) {
        printf("No arguments found");
        exit(1);
    }
    int n = atoi(argv[1]);
    
    int fig = atoi(argv[2]);
    
    if(fig==0) {
        fig0(n);
    } else if (fig==1) {
        fig1(n);
    } else if (fig==2) {
        fig2(n);
    } else if (fig==3) {
        fig3(n);
    }
}