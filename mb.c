#include <complex.h>
#include <math.h>

#include "util.h"
#include "mb.h"
#include "gui.h"

static const double X_MIN = -2.5, X_MAX = 1.0;
static const double Y_MIN = -1.0, Y_MAX = 1.0;
static const int ITERS = 30;

static double get_color(int n, complex double z)
{
	return n - log2(log2(cabs(z)));
}
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

Uint32 colors[256];
void draw_mb(SDL_Surface* base)
{
	SDL_FreeSurface(gui.image);
	int flags = base->flags;
	flags &= ~(SDL_HWACCEL | SDL_HWSURFACE);
	flags |= SDL_SWSURFACE;
	gui.image = SDL_ConvertSurface(base, base->format, flags);
	SDL_Surface* surface = gui.image;

	for(int i = 0; i < 256; i++)
	{
		double p = (double)i / 255.0;
		colors[i] = SDL_MapRGB(surface->format, (1 - p) * 255.0, (1 - p) * 255.0, 255);
	}

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
				put_pixel(surface, i, j, colors[(int)(256 * (get_color(k, z) / (double)ITERS))]);
			//put_pixel(surface, i, j, colors[i % 256]);
		}
}
