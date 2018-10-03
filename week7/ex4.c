#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include <malloc.h>

size_t getmin(size_t a, size_t b) {
    if (a < b) {
        return a;
    } else return b;
}

void *realloc(void *ptr, size_t size) {
    if(ptr == NULL) {
        return malloc(size);
    }
    void *newptr;


    size_t ptr_size = malloc_usable_size(ptr);

    ptr_size = getmin(ptr_size, size);

    newptr = malloc(size);
    newptr = memcpy(newptr, ptr, ptr_size);
    free(ptr);

    return newptr;
}


int main() {

    // Allows user to specify the original array size, stored in variable n1.
    printf("Enter original array size: ");
    int n1 = 0;
    scanf("%d", &n1);

    //Create a new array of n1 ints
    int *a1 = (int*)calloc(sizeof(int), (size_t) n1);
    for (int i = 0; i < n1; i++) {
        //Set each value in a1 to 100
        a1[i] = 100;

        //Print each element out (to make sure things look right)
        printf("%d ", a1[i]);
    }

    //User specifies the new array size, stored in variable n2.
    printf("\nEnter new array size: ");
    int n2 = 0;
    scanf("%d", &n2);

    //Dynamically change the array to size n2
    a1 = (int*)realloc(a1, (size_t) n2*sizeof(int));

    //If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.

    if (n1 < n2) {
        for (int i = n1; i < n2; i++) {
            a1[i] = 0;
        }
    }

    for (int i = 0; i < n2; i++) {
        //Print each element out (to make sure things look right)
        printf("%d ", a1[i]);
    }
    printf("\n");

    //Done with array now, done with program :D

    return 0;
}