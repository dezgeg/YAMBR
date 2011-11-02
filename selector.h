#ifndef SELECTOR_H
#define SELECTOR_H

#include "SDL/SDL.h"
#include <stdbool.h>

typedef struct SelectorState
{
	int x1, y1;
	int x2, y2;
	bool selection_in_progress;
} SelectorState;

extern void selector_handle_mouse(const SDL_Event* ev);
extern void selector_draw(SDL_Surface* surface);

#endif
