#ifndef GRID_H
#define GRID_H

typedef struct Grid {
  int size;
  int **matrix;
} grid_t;


int** build_matrix(int size);
void clean_matrix(grid_t* grid);
grid_t new_grid(int size);
void print_grid(grid_t grid);

#endif
