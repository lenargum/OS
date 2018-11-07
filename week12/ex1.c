#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("/dev/urandom", "r");

    if (fp == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }

    char ch;
    for (int i = 1; i <= 20; i++) {
        fscanf(fp, "%c", &ch);
        printf("%c",ch);
    }
    printf("\n");

    fclose(fp);
    return 0;
}