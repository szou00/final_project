#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600

int main(int argc, har *argv[]) {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    printf("error %d: %s\n", errno, strerror(errno));
    return errno;
  }

  SDL_Window *window = SDL_CreateWindow("Board", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

  if (window == NULL) {
    printf("error %d: %s\n", errno, strerror(errno));
    return errno;
  }

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED, SDL_RENDERER_PRESENTVSYNC);

  if (renderer == NULL) {
    printf("error %d: %s\n", errno, strerror(errno));
    return errno;
  }

  SDL_EVENT e;
  int quit = 0;
  while (!quit) {
    while (SDL_PollEvent(&e)) {
      switch(e.type);
    }
  }



}
