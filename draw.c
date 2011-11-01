#include "gui.h"

void draw_scene(void)
{
	SDL_LockSurface(surface);
	for(int i = 0; i < surface->w; i++)
	{
		for(int j = 0; j < surface->h; j++)
		{
			put_pixel(surface, i, j, SDL_MapRGB(surface->format, i % 256, j % 256, (i + j) % 256));
		}
	}
	SDL_UnlockSurface(surface);
}
