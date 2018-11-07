#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char has_a_argument = 0;
    if (argc > 1) {
        if (strcmp("-a", argv[1]) == 0) {
            has_a_argument = 1;
        }
    }


    char *input = (char *) malloc(64);
    fgets(input, 63, stdin);
    printf("%s\n", input);


    for (int i = 1 + has_a_argument; i < argc; i++) {
        FILE *fp;
        if (has_a_argument) {
            fp = fopen(argv[i], "a");
        } else {
            fp = fopen(argv[i], "w");
        }

        if (fp == NULL) {
            fprintf(stderr, "Cannot open file \"%s\"\n", argv[i]);
            continue;
        }
        fputs(input, fp);
        fclose(fp);
    }
    return 0;
}