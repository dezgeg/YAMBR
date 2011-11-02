#include "gui.h"
#include "mb.h"
#include "selector.h"

void init(void)
{
}
void handle_keypress(const SDL_keysym* keysym)
{
	switch (keysym->sym)
	{
		case SDLK_ESCAPE:
			exit(0);
			break;
		default:
			break;
	}
}
void handle_mouse(const SDL_Event* e)
{
	selector_handle_mouse(e);
}

