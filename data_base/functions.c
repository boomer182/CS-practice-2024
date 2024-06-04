#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "string.h"
#include "graphics.h"
#include <math.h>
#include "header.h"

struct student
{
    char st_name[20];
    int st_full_age;
    double points;
};
int pointu(struct student a, struct student b)
{
    if (a.st_full_age < b.st_full_age)
        return 1;
    return 0;
}
int apointu(struct student a, struct student b)
{
    if (a.st_full_age > b.st_full_age)
        return 1;
    return 0;
}
int podoblu(struct student a, struct student b)
{
    if (a.points < b.points)
        return 1;
    return 0;
}
int apodoblu(struct student a, struct student b)
{
    if (a.points > b.points)
        return 1;
    return 0;
}
int postringu(struct student a, struct student b)
{
    int x = strcmp(a.st_name, b.st_name);
    if (x < 0)
        return 1;
    return 0;
}
int apostringu(struct student a, struct student b)
{
    int x = strcmp(a.st_name, b.st_name);
    if (x > 0)
        return 1;
    return 0;
}
void hm_swap(struct student* a, struct student* b)
{
    struct student* c = (student*)malloc(sizeof(struct student));
    *c = *a;
    *a = *b;
    *b = *c;
    free(c);
}
struct group
{
    size_t g_size;
    size_t g_max;
    struct student* students;
};
struct group* new_group()
{
    struct group* g = (group*)malloc(sizeof(struct group));
    if (!g)
        return NULL;
    g->students = (student*)malloc(8 * sizeof(struct student));
    g->g_size = 0;
    g->g_max = 8;
    return g;
}
int twice(struct group* g)
{
    struct student* e = (student*)realloc(g->students, 2 * g->g_max * sizeof(struct student));
    if (!e)
    {
        return 1;
    }
    g->students = e;
    g->g_max *= 2;
    return 0;
}
int antitwice(struct group* g)
{
    struct student* e = (student*)realloc(g->students, g->g_max * sizeof(struct student) / 2);
    if (!e)
    {
        return 1;
    }
    g->students = e;
    g->g_max /= 2;
    return 0;
}
struct student* new_student(char* s, int a, double b)
{
    struct student* st = (student*)malloc(sizeof(struct student));
    if (!st)
    {
        return NULL;
    }
    if (!s)
        return NULL;
    st->points = b;
    st->st_full_age = a;
    size_t x = 0;
    for (char* ch = s; *ch != '\0'; ch++)
    {
        st->st_name[x] = *ch;
        x++;
    }
    st->st_name[x] = '\0';
    return st;
};
int st_add(struct group* g, int a, double b, char* s)
{
    if (g->g_max == g->g_size)
    {
        if (twice(g))
            return 1;
    }
    struct student* st = new_student(s, a, b);
    if (!st)
        return 1;
    g->students[g->g_size] = *st;
    free(st);
    g->g_size++;
    return 0;
}
int st_del(struct group* g, size_t k)
{
    if (k >= g->g_size)
        return 1;
    for (size_t i = k; i + 1 < g->g_size; i++)
    {
        g->students[i] = g->students[i + 1];
    }
    g->g_size--;
    if (g->g_max >= 16)
    {
        if (2 * g->g_size < g->g_max)
        {
            if (antitwice(g))
                return 1;
        }
    }
    return 0;
}
static void up(struct student* st, size_t k, cmp c)
{
    while (k > 0)
    {
        size_t l = k - 1;
        l /= 2;
        if (!c(st[l], st[k]))
            return;
        hm_swap(&st[l], &st[k]);
        k = l;
    }
}
static void down(struct student* st, size_t n, cmp c)
{
    size_t k = 0;
    while (2 * k + 1 < n)
    {
        size_t l1 = 2 * k + 1;
        size_t l2 = l1 + 1;
        if (l2 >= n)
            l2 = l1;
        if ((!c(st[k], st[l1])) && (!c(st[k], st[l2])))
            return;
        if (c(st[l1], st[l2]))
        {
            hm_swap(&st[k], &st[l2]);
            k = l2;
        }
        else
        {
            hm_swap(&st[k], &st[l1]);
            k = l1;
        }
    }
}
static void hsort(struct student* st, size_t n, cmp c)
{
    for (size_t i = 0; i < n; i++)
    {
        up(st, i, c);
    }
    for (size_t i = 1; i < n; i++)
    {
        hm_swap(&st[0], &st[n - i]);
        down(st, n - i, c);
    }
}
void start_heap_sort(struct group* g, cmp c)
{
    hsort(g->students, g->g_size, c);
}
void say(struct group* g)
{
    int n = g->g_size;
    printf("%d\n", n);
    for (size_t i = 0; i < g->g_size; i++)
    {
        printf("%d %lf %s\n", g->students[i].st_full_age, g->students[i].points, g->students[i].st_name);
    }
}
void fsay(struct group* g, char* s)
{
    FILE* f = fopen(s, "w");
    int n = g->g_size;
    fprintf(f, "%d\n", n);
    for (size_t i = 0; i < g->g_size; i++)
    {
        fprintf(f, "%d %lf %s\n", g->students[i].st_full_age, g->students[i].points, g->students[i].st_name);
    }
    fclose(f);
}
int add_from_file(struct group* g, char* s)
{
    if (!s)
        return 1;
    FILE* f = fopen(s, "r");
    if (!f)
        return 1;
    int n;
    fscanf(f, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        int age;
        double point;
        char name[20];
        fscanf(f, "%d %lf %s", &age, &point, name);
        if (st_add(g, age, point, name))
        {
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;
}
void destroy(struct group* g)
{
    free(g->students);
    free(g);
}
int bar_data(struct group* g, int x)
{
    if (!g)
    {
        return 1;
    }
    if (!g->students)
    {
        return 1;
    }
    int gd = DETECT;
    int  gm = DETECT;
    initgraph(&gd, &gm, "");
    int k = 499 / g->g_size;
    if (x == 0)
    {
        int f = -1;
        for (size_t i = 0; i < g->g_size; i++)
        {
            if (g->students[i].st_full_age > f)
            {
                f = g->students[i].st_full_age;
            }
        }
        for (size_t i = 0; i < g->g_size; i++)
        {
            if (i % 2 == 0)
            {
                setcolor(GREEN);
                setbkcolor(RED);
            }
            else
            {
                setcolor(BLUE);
                setbkcolor(MAGENTA);
            }
            int x = g->students[i].st_full_age;
            x *= 499;
            x /= f;
            rectangle(k * i, 500 - x, k * (i + 1) - 1, 500);
            outtextxy(k * i, 100, g->students[i].st_name);
            char ch[4];
            ch[0] = '0' + i / 100;
            ch[1] = '0' + (i % 100) / 10;
            ch[2] = '0' + i % 10;
            ch[3] = '\0';
            outtextxy(k * i, 110, ch);
        }

    }
    else
    {
        double f = -1;
        for (size_t i = 0; i < g->g_size; i++)
        {
            if (g->students[i].points > f)
            {
                f = g->students[i].points;
            }
        }
        for (size_t i = 0; i < g->g_size; i++)
        {
            double x = g->students[i].points;
            if (i % 2 == 0)
            {
                setcolor(GREEN);
                setbkcolor(RED);
            }
            else
            {
                setcolor(BLUE);
                setbkcolor(MAGENTA);
            }
            x *= 499;
            x /= f;
            int y = (int)x;
            rectangle(k * i, 500 - y, k * (i + 1) - 1, 500);
            outtextxy(k * i, 100, g->students[i].st_name);
            char ch[4];
            ch[0] = '0' + i / 100;
            ch[1] = '0' + (i % 100) / 10;
            ch[2] = '0' + i % 10;
            ch[3] = '\0';
            outtextxy(k * i, 110, ch);
        }
    }
    return 0;
}
int circle_data(struct group* g, int x)
{
    if (!g)
    {
        return 1;
    }
    if (!g->students)
    {
        return 1;
    }
    int gd = DETECT;
    int gm = DETECT;
    initgraph(&gd, &gm, "");
    double sum = 0;
    double sum1 = 0;
    if (x == 0)
    {
        int j = 0;
        for (size_t i = 0; i < g->g_size; i++)
        {
            sum += g->students[i].st_full_age;
        }
        for (size_t i = 0; i < g->g_size; i++)
        {
            if (j % 2 == 0)
            {
                setcolor(RED);
            }
            else
            {
                setcolor(MAGENTA);
            }
            double x = g->students[i].st_full_age;
            if (x != 0.0)
            {
                j++;
                x *= 360;
                x /= sum;
                if (i + 1 != g->g_size)
                {
                    sector(250, 210, sum1, sum1 + x, 150, 150);
                }
                else
                {
                    setcolor(GREEN);
                    sector(250, 210, sum1, 0, 150, 150);
                }
                setcolor(YELLOW);
                double r = sum1 + x / 2;
                r = r * 2 * 3.1415926 / 360;
                double rx = cos(r) * 200;
                double ry = sin(r) * 200;
                char ch[4];
                ch[0] = '0' + i / 100;
                ch[1] = '0' + (i % 100) / 10;
                ch[2] = '0' + i % 10;
                ch[3] = '\0';
                int RX = (int)rx;
                int RY = (int)ry;
                outtextxy(250 + RX, 210 - RY, ch);
                sum1 += x;
            }
        }
    }
    else
    {
        for (size_t i = 0; i < g->g_size; i++)
        {
            sum += g->students[i].points;
        }
        int j = 0;
        for (size_t i = 0; i < g->g_size; i++)
        {
            if (j % 2 == 0)
            {
                setcolor(GREEN);
            }
            else
            {
                setcolor(BLUE);
            }
            double x = g->students[i].points;
            if (x != 0.0)
            {
                j++;
                x *= 360;
                x /= sum;
                if (i + 1 != g->g_size)
                {
                    sector(250, 210, sum1, sum1 + x, 150, 150);
                }
                else
                {
                    setcolor(RED);
                    sector(250, 210, sum1, 0, 150, 150);
                }
                setcolor(YELLOW);
                double r = sum1 + x / 2;
                r = r * 2 * 3.1415926 / 360;
                double rx = cos(r) * 200;
                double ry = sin(r) * 200;
                char ch[4];
                ch[0] = '0' + i / 100;
                ch[1] = '0' + (i % 100) / 10;
                ch[2] = '0' + i % 10;
                ch[3] = '\0';
                int RX = (int)rx;
                int RY = (int)ry;
                outtextxy(250 + RX, 210 - RY, ch);
                sum1 += x;
            }
        }
    }
}
