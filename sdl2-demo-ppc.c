#include "SDL.h"
int main(int argc, char **argv) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) { SDL_Log("Init: %s", SDL_GetError()); return 2; }
    SDL_Window *w = SDL_CreateWindow("SDL2 on PowerPC G5  --  Elyan Labs",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    if (!w) { SDL_Log("CreateWindow: %s", SDL_GetError()); return 3; }
    SDL_Surface *s = SDL_GetWindowSurface(w);
    if (!s) { SDL_Log("GetWindowSurface: %s", SDL_GetError()); return 4; }
    SDL_Log("SDL2 software window up on PowerPC (%dx%d)", s->w, s->h);
    int f;
    for (f = 0; f < 900; f++) {
        SDL_FillRect(s, NULL, SDL_MapRGB(s->format, 18, 22, 38));
        int i;
        for (i = 0; i < 6; i++) {
            SDL_Rect bar; bar.x = 35 + i*100; bar.y = 120; bar.w = 70; bar.h = 80 + ((f + i*15) % 220);
            SDL_FillRect(s, &bar, SDL_MapRGB(s->format, 50+i*34, 210-i*28, 110+i*22));
        }
        SDL_Rect sq; sq.x = (f*4) % 600; sq.y = 40; sq.w = 40; sq.h = 40;
        SDL_FillRect(s, &sq, SDL_MapRGB(s->format, 255, 200, 0));
        SDL_UpdateWindowSurface(w);
        SDL_Delay(33);
        SDL_Event e; while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) f = 99999; }
    }
    SDL_DestroyWindow(w); SDL_Quit();
    return 0;
}
