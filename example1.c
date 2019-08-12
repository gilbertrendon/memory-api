#include <stdio.h>
#include <stdlib.h>

#define TAM 10 

int main() {
  int *p, *q;
  p = malloc(TAM*sizeof(int));
  for (int i = 0; i < TAM; i++) {
    *(p + i) = 0; // p[i] = 0
  }
  free(p); 
  p = NULL;
  return 0;
}
