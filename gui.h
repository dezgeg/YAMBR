#ifndef GUI_H
#define GUI_H

#include <SDL/SDL.h>
#include <stdbool.h>

// events.c
extern void handle_keypress(const SDL_keysym* keysym);
extern void handle_mouse(const SDL_MouseMotionEvent* mme);
extern void tick(void);
// draw.c
extern void draw_scene(void);
// main.c
extern SDL_Surface* surface;
#endif
