#include <stdio.h>

void swap (int * a,int * b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 0;
    int b = 0;
    printf("Enter 2 numbers through a space: \n");
    scanf("%d %d", &a ,&b);
    swap(&a, &b);
    printf("Result: %d %d \n", a, b);
}