#include "../includes/app.h"
#include "../includes/engine.h"
#include "../includes/grid.h"
#include "../includes/log.h"
#include "../includes/ui.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>

int run_app() {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    char *msg;
    sprintf(msg, "SDL initialization failed: %s\n", SDL_GetError());
    log_error(msg);

    return 1;
  }

  // Create a window
  SDL_Window *window =
      SDL_CreateWindow("Game of life",         // Window title
                       SDL_WINDOWPOS_CENTERED, // X position (centered)
                       SDL_WINDOWPOS_CENTERED, // Y position (centered)
                       WINDOW_WIDTH,           // Width
                       WINDOW_HEIGHT,          // Height
                       SDL_WINDOW_SHOWN        // Flags (show window)
      );

  // Check if window creation failed
  if (window == NULL) {
    char *msg;
    sprintf(msg, "Window creation failed: %s\n", SDL_GetError());
    log_error(msg);
    SDL_Quit();

    return 1;
  }

  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == NULL) {
    char *msg;
    sprintf(msg, "renderer creation failed: %s\n", SDL_GetError());
    log_error(msg);

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 1;
  }

  int size = 200;
  grid_t g = new_grid(size);
  // INFO: to remove;
 /* g.matrix = compute_grid(&g);*/
 /*// render_grid(renderer, &g);*/
 /* build_app_grid(renderer, &g);*/

  // Main loop flag
  int running = 1;
  SDL_Event event;

  // Main loop
  while (running) {
    // Poll for events
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                running = 0;
                break;
            case SDL_MOUSEBUTTONDOWN:
                handle_click(&event);
                break;
        }
    }

    // INFO: tmp
    render_grid(renderer, &g);
    g.matrix = compute_grid(&g);

    // Clear the window to black (optional, requires a renderer for drawing)
    // For now, the window will just be shown without any drawing
  }

  // Clean up
  clean_matrix(&g);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}

void handle_click(SDL_Event *event){
    if (event->button.button != SDL_BUTTON_LEFT) {
        return;
    }


}
