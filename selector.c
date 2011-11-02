#include <SDL/SDL_gfxPrimitives.h>
#include "selector.h"
#include "util.h"
#include "gui.h"

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

void selector_handle_mouse(const SDL_Event* e)
{
	switch(e->type)
	{
		case SDL_MOUSEMOTION:
			if(gui.selector.selection_in_progress)
			{
				gui.selector.x2 = e->motion.x;
				gui.selector.y2 = e->motion.y;
			}
			break;
		case SDL_MOUSEBUTTONUP:
			gui.selector.selection_in_progress = false;
			break;
		case SDL_MOUSEBUTTONDOWN:
			gui.selector.selection_in_progress = true;
			gui.selector.x1 = gui.selector.x2 = e->button.x;
			gui.selector.y1 = gui.selector.y2 = e->button.y;
			break;
		default:
			break;
	}
}
void selector_draw(SDL_Surface* screen)
{
	SelectorState* sel = &gui.selector;
	int x1 = MIN(sel->x1, sel->x2), x2 = MAX(sel->x1, sel->x2);
	int y1 = MIN(sel->y1, sel->y2), y2 = MAX(sel->y1, sel->y2);

	boxRGBA(screen, x1, y1, x2, y2, 0, 0, 255, 128);
	rectangleRGBA(screen, x1, y1, x2, y2, 0, 0, 255, 255);
}
