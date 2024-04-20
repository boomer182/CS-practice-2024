#include "header.h"

double func(double x)
{
	return x*sin(4*x);
}

double max_of_func(func_t f, double xmin, double xmax, double step)
{
	double max = 0;
	for (double x = xmin; x <= xmax; x += step)
	{
		if (fabs(f(x)) > max) max = fabs(f(x));
	}

	return max;
}
