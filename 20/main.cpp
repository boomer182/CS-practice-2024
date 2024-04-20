#include "header.h"

int main()
{
	setlocale(LC_CTYPE, "Russian");

	std::cout << "Введите промежуток, на котором рисуется график функции: \n";
	double xmin, xmax;
	std::cin >> xmin >> xmax;

	std::cout << "Введите шаг вычисления функции: \n";
	double step;
	std::cin >> step;

	std::cout << "Введите масштаб графика: \n";
	int scale;
	std::cin >> scale;

	int width = 2 * (xmax - xmin) * scale, height = 2 * max_of_func(func, xmin, xmax, step) * scale;

	int HEIGHT = GetSystemMetrics(SM_CYSCREEN);
	int WIDTH = GetSystemMetrics(SM_CXSCREEN);

	if (height > HEIGHT) height = HEIGHT;
	else if (height < HEIGHT / 2) height = HEIGHT / 2;

	if (width > WIDTH) width = WIDTH;
	else if (width < WIDTH / 2) width = WIDTH / 2;

	initwindow(width+10, height);
	adaptive_func_drawing(func, step, scale, xmin, xmax, (double)width / 2, (double)height / 2);

	getch();
	closegraph();

	return 0;
}