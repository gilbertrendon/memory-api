#include <stdio.h>
#include <stdlib.h>


int main(void) {
    int cantidad = 4;
    int* numeros = malloc(cantidad * sizeof(int));

    
    numeros = NULL;

    //free(numeros);
    return EXIT_SUCCESS;
}
