#include "header.h"

void draw_coordinate_system(double a, double b, int scale)
{
	line(0, b, a * 2, b); // x axe
	outtextxy(a * 2 - 30, b + 15, (char*)"X");

	line(a, 0, a, b * 2); // y axe
	outtextxy(a - 30, 5, (char*)"Y");

	outtextxy(a - 20, b + 5, (char*)"0"); // origin

	for (double i = a; i < a * 2; i += scale) // serifs for x axe
	{
		circle(i, b, 3);
	}
	for (double i = a; i > 0; i -= scale)
	{
		circle(i, b, 3);
	}

	for (double i = b; i < b * 2; i += scale) // serifs for y axe
	{
		circle(a, i, 3);
	}
	for (double i = b; i > 0; i -= scale)
	{
		circle(a, i, 3);
	}

	line(a * 2 - 10, b - 10, a * 2, b); // arrow for x axe
	line(a * 2 - 10, b + 10, a * 2, b);

	line(a - 10, 10, a, 0); // arrow for y axe
	line(a + 10, 10, a, 0);
}

void func_drawing(func_t f, double step, int scale, double xmin, double xmax, double a, double b)
{
	double x, y;
	double xe, ye;

	for (x = xmin; x < xmax; x += step) // draw fuction line
	{
		y = f(x);
		xe = a + scale * x;
		ye = b - scale * y;
		putpixel(xe, ye, 13);
	}
}

void adaptive_func_drawing(func_t f, double step, int scale, double xmin, double xmax, double xorigin, double yorigin)
{
	double a = xorigin, b = yorigin;
	if (b == (double)GetSystemMetrics(SM_CYSCREEN) / 2) b -= 100; // change b for better view

	draw_coordinate_system(a, b, scale);
	func_drawing(f, step, scale, xmin, xmax, a, b);

	std::string scale_text = "SCALE: " + std::to_string(scale);
	outtextxy(a * 2 - 100, 40, (char*)scale_text.c_str());

	rectangle(a * 2 - 100, 60, a * 2 - 80, 80);
	outtextxy(a * 2 - 93, 63, (char*)"+");

	rectangle(a * 2 - 70, 60, a * 2 - 50, 80);
	outtextxy(a * 2 - 61, 63, (char*)"-");

	POINT cursorPos;

	while (1)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			int mouseX, mouseY;
			getmouseclick(WM_LBUTTONDOWN, mouseX, mouseY);
			if (mouseX >= a * 2 - 100 && mouseX <= a * 2 - 80 && mouseY >= 60 && mouseY <= 80)
			{
				scale += 5;
				cleardevice();
				draw_coordinate_system(a, b, scale);
				func_drawing(f, step, scale, xmin, xmax, a, b);
				scale_text = "SCALE: " + std::to_string(scale);
				outtextxy(a * 2 - 100, 40, (char*)scale_text.c_str());
				rectangle(a * 2 - 100, 60, a * 2 - 80, 80);
				outtextxy(a * 2 - 93, 63, (char*)"+");
				rectangle(a * 2 - 70, 60, a * 2 - 50, 80);
				outtextxy(a * 2 - 61, 63, (char*)"-");
				clearmouseclick(WM_LBUTTONDOWN);
			}
			else if (mouseX >= a * 2 - 70 && mouseX <= a * 2 - 50 && mouseY >= 60 && mouseY <= 80)
			{
				scale -= 5;
				cleardevice();
				draw_coordinate_system(a, b, scale);
				func_drawing(f, step, scale, xmin, xmax, a, b);
				scale_text = "SCALE: " + std::to_string(scale);
				outtextxy(a * 2 - 100, 40, (char*)scale_text.c_str());
				rectangle(a * 2 - 100, 60, a * 2 - 80, 80);
				outtextxy(a * 2 - 93, 63, (char*)"+");
				rectangle(a * 2 - 70, 60, a * 2 - 50, 80);
				outtextxy(a * 2 - 61, 63, (char*)"-");
				clearmouseclick(WM_LBUTTONDOWN);
			}
		}
		else if (kbhit())
		{
			if (getch() == 27) break;
		}
	}
}
