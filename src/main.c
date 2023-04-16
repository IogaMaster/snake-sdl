#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

int main() {
  // The window we'll be rendering to
  SDL_Window *window =
      SDL_CreateWindow("Snake SDL", 0, 0, 1080, 720, SDL_WINDOW_SHOWN);

  // The surface contained by the window
  SDL_Surface *surface = SDL_GetWindowSurface(window);

  SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));

  SDL_UpdateWindowSurface(window);

  SDL_Event e;
  bool quit = false;
  while (quit == false) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT)
        quit = true;
    }
  }

  // Cleanup
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
