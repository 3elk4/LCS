#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
#define n 30

int main() {
    char first[n], second[n];

    printf("Podaj pierwszy wyraz: ");
    scanf("%29s", first);
    *(first + strlen(first)) = '\0';
    int lines = strlen(first) + 1;

    printf("Podaj drugi wyraz: ");
    scanf("%29s", second);
    *(second + strlen(second)) = '\0';
    int columns = strlen(second) + 1;

    int** matrix = LCS(first, second);
    printMatrix(matrix, lines, columns);
    printf("\n");
    printf("Najdluzsza wspolna podsekwencja: %d\n", *(*(matrix + (lines - 1)) + (columns - 1)));
    deleteMatrix(&matrix, lines);

    return 0;
}
