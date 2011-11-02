#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

#include "gui.h"
#include "mb.h"

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480
#define SCREEN_BPP     24
#define FRAME_INTERVAL 30

GuiState gui;
static void die(const char* message)
{
	fprintf(stderr, "%s: %s\n", message, SDL_GetError());
	exit(EXIT_FAILURE);
}
int main(int argc, char** argv)
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
		die("SDL initialization failed");
	atexit(SDL_Quit);

	int videoFlags = SDL_RESIZABLE | SDL_HWSURFACE | SDL_HWACCEL | SDL_DOUBLEBUF;
	SDL_Surface* surface = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, videoFlags);
	if(!surface)
		die("Changing video mode failed");
	gui.screen = surface;
	init();

	SDL_Event event;
	/* ignore spurious mouse events at startup */
	do{
		SDL_PumpEvents();
	}while(SDL_PeepEvents(&event, 1, SDL_GETEVENT, SDL_EVENTMASK(SDL_MOUSEMOTION)) == 1);

	setup_scene();
	draw_scene();
	while (true)
	{
		bool redraw = false;
		SDL_WaitEvent(NULL);
		while (SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_ACTIVEEVENT:
					if(event.active.state & SDL_APPACTIVE && event.active.gain)
						redraw = true;
					break;			    
				case SDL_VIDEORESIZE:
					gui.screen = SDL_SetVideoMode(event.resize.w,
							event.resize.h,
							SCREEN_BPP, videoFlags);
					if(!gui.screen)
						die("Lost video surface during resize");
					setup_scene();
					redraw = true;
					break;
				case SDL_KEYDOWN:
					handle_keypress(&event.key.keysym);
					break;
				case SDL_MOUSEMOTION:
				case SDL_MOUSEBUTTONDOWN:
				case SDL_MOUSEBUTTONUP:
					handle_mouse(&event);
					redraw = true;
					break;
				case SDL_QUIT:
					goto out;
				default:
					break;
			}
		}
		if(redraw)
			draw_scene();
	}
out:

	return 0;
}
