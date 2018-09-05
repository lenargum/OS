#include <stdio.h>

void print_array(int a[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void bubble_sort(int a[], int len) {
    for (int i = len - 1; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main() {
    int a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int len = sizeof(a) / sizeof(int);
    bubble_sort(a, len);
    print_array(a, len);
}
