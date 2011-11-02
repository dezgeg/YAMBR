#include <stdbool.h>
#include "gui.h"
void draw_scene(void)
{
		SDL_BlitSurface(gui.image, NULL, gui.screen, NULL);
}
