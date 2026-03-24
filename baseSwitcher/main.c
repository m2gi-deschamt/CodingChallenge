#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(5*sizeof(int));
    

    *(ptr + 1) = 43;
    // Do some operations.....
    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr[i]);
    }
    // Free the memory after completing
    // operations
    free(ptr);
    
    return 0;
}