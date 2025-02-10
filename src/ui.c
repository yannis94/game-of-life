#include "../includes/ui.h"
#include "../includes/log.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <unistd.h>

void build_app_grid(SDL_Renderer *renderer, grid_t *grid) {
  // Clear the screen (black)
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
  int square_size = WINDOW_HEIGHT / grid->size;

  // Set draw color to white for the square
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

  // Define the square's position and size
  SDL_Rect squareRect = {square_size, 0, square_size,
                         square_size}; // x, y, width, height

  // Draw the square
  SDL_RenderFillRect(renderer, &squareRect);

  // Update the screen
  SDL_RenderPresent(renderer);
}

void render_grid(SDL_Renderer *renderer, grid_t *grid) {
  // Clear the screen (black)
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  int square_size = WINDOW_HEIGHT / grid->size;

  printf("square size: %d\n", square_size);
  log_info("building grid");

  int padding = 2;

  for (int row = 0; row < grid->size; row++) {
    int y = row * (square_size + padding);

    for (int col = 0; col < grid->size; col++) {
      int x = col * (square_size + padding);

      if (grid->matrix[row][col] == 1) {
          // Set draw color to white for the square
          SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
      } else {
          // Set draw color to white for the square
          SDL_SetRenderDrawColor(renderer, 250, 250, 250, 255);
      }
      // Define the square's position and size
      SDL_Rect squareRect = {x, y, square_size,
                             square_size}; // x, y, width, height

      // Draw the square
      SDL_RenderFillRect(renderer, &squareRect);
    }
  }

  // Update the screen
  SDL_RenderPresent(renderer);

  sleep(1);
}
