#ifndef GUI_H
#define GUI_H

#include <SDL/SDL.h>
#include <stdbool.h>

typedef struct GuiState
{
	int unused;
} GuiState;

// events.c
extern void handle_keypress(const SDL_keysym* keysym);
extern void handle_mouse(const SDL_MouseMotionEvent* mme);
extern void tick(void);
extern void init(void);
// draw.c
extern void draw_scene(void);
extern void video_init(void);
// main.c
extern SDL_Surface* surface;
extern GuiState gui;
// util.c
extern Uint32 get_pixel(const SDL_Surface* surface, int x, int y);
extern void put_pixel(SDL_Surface* surface, int x, int y, Uint32 pixel);
#endif
