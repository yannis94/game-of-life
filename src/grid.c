#include "../includes/grid.h"
#include "../includes/log.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **build_matrix(int size) {
  int **matrix = (int **)malloc(size * sizeof(int *));

  if (matrix == NULL) {
    return NULL;
  }

  for (int i = 0; i < size; i++) {
    matrix[i] = (int *)malloc(size * sizeof(int *));

    if (matrix[i] == NULL) {
      for (int j = 0; j < i; j++) {
        free(matrix[j]);
      }

      free(matrix);

      return NULL;
    }
  }

  return matrix;
}

void clean_matrix(grid_t *grid) {
  log_info("clean_matrix");
  print_grid(*grid);

  for (int i = 0; i < grid->size; i++) {
    free(grid->matrix[i]);
  }

  free(grid->matrix);
}

grid_t new_grid(int size) {
  srand(time(NULL));
  int **matrix = build_matrix(size);

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {

      matrix[i][j] = rand() % 2;
    }
  }

  grid_t grid = {
      .size = size,
      .matrix = matrix,
  };

  return grid;
}

void print_grid(grid_t grid) {
  printf("------------------------------------\n");

  for (int i = 0; i < grid.size; i++) {
    for (int j = 0; j < grid.size; j++) {
      printf("%d\t", grid.matrix[i][j]);
    }

    printf("\n");
  }

  printf("------------------------------------\n");
}
