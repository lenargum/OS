#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter N: ");
    scanf("%d", &n);
    int *arr = calloc(sizeof(int), (size_t) n);
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
    free(arr);
}