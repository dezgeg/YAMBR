#include "gui.h"

void init()
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
void handle_mouse(const SDL_MouseMotionEvent* mme)
{

}
void tick(void)
{

}
