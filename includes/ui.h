#ifndef UI_H
#define UI_H

#include "grid.h"
#include <SDL2/SDL_render.h>

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 800

void build_app_grid(SDL_Renderer *renderer, grid_t *grid);
void render_grid(SDL_Renderer *renderer, grid_t *grid);

#endif
