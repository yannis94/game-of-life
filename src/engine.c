#include "../includes/engine.h"
#include "../includes/log.h"

struct Cell {
  int row;
  int col;
};

int get_cell_value(grid_t *g, struct Cell cell) {
  if (cell.row < 0 || cell.col < 0) {
    return 0;
  } else if (cell.row >= g->size || cell.col >= g->size) {
    return 0;
  }

  return g->matrix[cell.row][cell.col];
}

int get_alive_neighbors(grid_t *g, struct Cell cell) {
  // a cell always have 8 posssible neighbors.
  struct Cell neighbor_top = {cell.row + 1, cell.col};
  struct Cell neighbor_top_right = {cell.row + 1, cell.col + 1};
  struct Cell neighbor_right = {cell.row, cell.col + 1};
  struct Cell neighbor_bottom_right = {cell.row - 1, cell.col + 1};
  struct Cell neighbor_bottom = {cell.row - 1, cell.col};
  struct Cell neighbor_bottom_left = {cell.row - 1, cell.col - 1};
  struct Cell neighbor_left = {cell.row, cell.col - 1};
  struct Cell neighbor_left_top = {cell.row + 1, cell.col - 1};

  int alive_neighbors = 0;

  alive_neighbors += get_cell_value(g, neighbor_top);
  alive_neighbors += get_cell_value(g, neighbor_top_right);
  alive_neighbors += get_cell_value(g, neighbor_right);
  alive_neighbors += get_cell_value(g, neighbor_bottom_right);
  alive_neighbors += get_cell_value(g, neighbor_bottom);
  alive_neighbors += get_cell_value(g, neighbor_bottom_left);
  alive_neighbors += get_cell_value(g, neighbor_left);
  alive_neighbors += get_cell_value(g, neighbor_left_top);

  return alive_neighbors;
}

int compute_cell(grid_t *grid, struct Cell cell) {
  int alive_neighbors = get_alive_neighbors(grid, cell);
  int cell_value = grid->matrix[cell.row][cell.col];

  // case dead cell.
  if (cell_value == 0) {
    if (alive_neighbors == 3) {
      return 1;
    }

    return 0;
  }

  // case alive cell.
  if (alive_neighbors < 2) {
    return 0;
  } else if (alive_neighbors > 3) {
    return 0;
  }

  return 1;
}

int **compute_grid(grid_t *g) {
  log_info("compute_grid");
  int **m = build_matrix(g->size);

  for (int i = 0; i < g->size; i++) {
    for (int j = 0; j < g->size; j++) {
      struct Cell cell = {.row = i, .col = j};
      m[i][j] = compute_cell(g, cell);
    }
  }

  clean_matrix(g);

  return m;
}
