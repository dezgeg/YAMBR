#ifndef UTIL_H
#define UTIL_H

#include <SDL/SDL.h>

extern Uint32 get_pixel(const SDL_Surface* surface, int x, int y);
extern void put_pixel(SDL_Surface* surface, int x, int y, Uint32 pixel);
#endif
