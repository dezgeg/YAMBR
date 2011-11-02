#ifndef GUI_H
#define GUI_H

#include <SDL/SDL.h>
#include <stdbool.h>

#include "selector.h"

typedef struct GuiState
{
	SDL_Surface* screen;
	SDL_Surface* image;
	SelectorState selector;
} GuiState;

// events.c
extern void handle_keypress(const SDL_keysym* keysym);
extern void handle_mouse(const SDL_Event* e);
extern void init(void);
// draw.c
extern void setup_scene(void);
extern void draw_scene(void);
// main.c
extern GuiState gui;
#endif
