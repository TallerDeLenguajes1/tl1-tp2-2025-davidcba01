#include <stdio.h>
#include <stdlib.h>

#define N 5
#define M 7

int main() {
    int i, j;
    int mt[N][M];

    // Puntero a la posición 0 del arreglo
    int *ptr = &mt[0][0]; 

    // Imprimiendo los elementos del arreglo con el puntero
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            *(*(mt + i) + j) = 1 + rand() % 100;
            printf("%d ", *(ptr + i * M + j));
        }
        printf("\n");
    }

    return 0;
}