#include <stdio.h>
#include <stdlib.h>

int main() {
    char **s = (char**) malloc(sizeof(char));
    char foo[] = "Hello World";
    *s = foo;
    printf("s is %s\n", *s);
    **s = foo[0];
    printf("s[0] is %c\n",**s);
}