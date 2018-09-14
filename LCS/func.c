#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

int maximum(int x, int y){
    if(x > y) return x;
    return y;
}

int** allocateMatrix(int lines, int columns){
    if(lines <= 0 || columns <= 0) return NULL;

    int i, j;
    int** matrix = (int **)calloc(lines, sizeof(int *));
    if(matrix == NULL) return NULL;
    for(i = 0; i < lines; ++i){
        *(matrix + i) = (int *)calloc(columns, sizeof(int));
        if((matrix + i) == NULL){
            for(j = i - 1; j >= 0; --j){
                free(*(matrix + j));
            }
            free(matrix);
            return NULL;
        }
    }

    return matrix;
}

void deleteMatrix(int*** matrix, int lines){
    int i;
    for(i = 0; i < lines; ++i){
        free(*(*matrix + i));
    }
    free(*matrix);
    return;
}

int** LCS(char* first, char* second){
    if(first == NULL || second == NULL){
        return NULL;
    }
    int lines = strlen(first) + 1, columns = strlen(second) + 1, i = 0, j = 0;
    int f = 0, s = 0;

    int** matrix = allocateMatrix(lines, columns);
    if(matrix == NULL){
        printf("Failed to allocate memory");
        return NULL;
    }

    f = 0;
    for(i = 1; i < lines; ++i){
        s = 0;
        for(j = 1; j < columns; ++j){
            if(*(first + f) == *(second + s)){
                *(*(matrix + i) + j) = *(*(matrix + (i - 1)) + (j - 1)) + 1;
            }
            else{
                *(*(matrix + i) + j) = maximum(*(*(matrix + (i - 1)) + j),*(*(matrix + i) + (j - 1)));
            }
            ++s;
        }
        ++f;
    }

    return matrix;
}

void printMatrix(int** matrix, int lines, int columns){
    int i, j;
    for(i = 0; i < lines; ++i){
        for(j = 0; j < columns; ++j){
            printf("%5d", *(*(matrix + i) + j));
        }
        printf("\n");
    }

    return;
}

