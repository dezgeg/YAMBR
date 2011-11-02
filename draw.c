#include <stdbool.h>
#include "gui.h"
#include "mb.h"

void setup_scene(void)
{
	draw_mb(gui.screen);
}
void draw_scene(void)
{
	SDL_BlitSurface(gui.image, NULL, gui.screen, NULL);
	SDL_Flip(gui.screen);
}
