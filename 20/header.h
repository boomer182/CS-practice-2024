#pragma once

#include <math.h>
#include <iostream>
#include "graphics.h"
#include <locale.h>
#include <string>

typedef double(*func_t) (double x);
double func(double x);
double max_of_func(func_t f, double xmin, double xmax, double step);

void adaptive_func_drawing(func_t f, double step, int scale, double xmin, double xmax, double xorigin, double yorigin);
void draw_coordinate_system(double a, double b, int scale);
void func_drawing(func_t f, double step, int scale, double xmin, double xmax, double a, double b);
