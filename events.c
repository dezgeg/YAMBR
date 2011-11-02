#include "gui.h"
#include <complex.h>
static const double X_MIN = -2.5, X_MAX = 1.0;
static const double Y_MIN = -1.0, Y_MAX = 1.0;
static const int ITERS = 50;

static inline double scale(double x, double xmin, double xmax, double ymin, double ymax)
{
	double fract = (x - xmin) / (xmax - xmin);
	return ymin + fract * (ymax - ymin);
}
static inline double cabs2(complex double z)
{
	double real = creal(z), imag = cimag(z);
	return real * real + imag * imag;
}


void init(void)
{
		update_image();
}
void update_image(void)
{
	SDL_FreeSurface(gui.image);
	int flags = gui.screen->flags;
	flags &= ~(SDL_HWACCEL | SDL_HWSURFACE);
	flags |= SDL_SWSURFACE;
	gui.image = SDL_ConvertSurface(gui.screen, gui.screen->format, flags);
	SDL_Surface* surface = gui.image;

	double width = (double)surface->w, height = (double)surface->h;
	for(int i = 0; i < surface->w; i++)
		for(int j = 0; j < surface->h; j++)
		{
			complex double c = scale((double)i + 0.5, 0.0, width, X_MIN, X_MAX) +
				_Complex_I * scale((double)j + 0.5, 0.0, height, Y_MIN, Y_MAX);
			complex double z = 0.0;
			int k;
			for(k = 0; k < ITERS; k++)
			{
				if(cabs2(z) > 4.0)
					break;
				z = z*z + c;
			}
			if(k == ITERS)
				put_pixel(surface, i, j, SDL_MapRGB(surface->format, 0, 0, 0));
			else
				put_pixel(surface, i, j, SDL_MapRGB(surface->format, 255, 255, 255));
		}
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
