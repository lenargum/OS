#include <stdio.h>
#include <string.h>
int main() {
    printf("Enter the string, which you want to reverse:\n");
    char word[256];
    scanf("%[^\n]%*c" , word);
    int word_len = strlen(word);
    for(int i = word_len-1;i>=0;i--) {
       printf("%c",word[i]);
    }
    return 0;
}