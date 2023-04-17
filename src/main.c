#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

int main() {
  SDL_Window *window =
      SDL_CreateWindow("Snake SDL", 0, 0, 1080, 720, SDL_WINDOW_SHOWN);
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
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
