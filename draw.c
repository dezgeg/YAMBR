#include <complex.h>
#include <stdbool.h>
#include "gui.h"
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

void draw_scene(void)
{
	double width = (double)surface->w, height = (double)surface->h;
	SDL_LockSurface(surface);
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
	SDL_UnlockSurface(surface);
}
