#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "graphics.h"
#include "header.h"

// Функция для отображения
void display_menu() {
    printf("0: Добавление (ввод возраста, баллов и имени)\n");
    printf("1: Удаление по индексу\n");
    printf("2: Вывод на экран\n");
    printf("3: Сортировка (0 - возраст, 1 - баллы, 2 - имя)\n");
    printf("4: Добавление из файла (нужно ввести имя файла)\n");
    printf("5: Запись в файл (нужно ввести имя файла)\n");
    printf("6: Сортировка в обратном порядке (0 - возраст, 1 - баллы, 2 - имя)\n");
    printf("7: Вывод столбчатой диаграммы (0 - вывод возрастной диаграммы, 1 - вывод балльной диаграммы)\n");
    printf("8: Вывод круговой диаграммы (0 - по возрасту, 1 - по баллам)\n");
    printf("9: Выход\n");
}

// Функция для получения функции сравнения
cmp get_comparator(int option, int reverse) {
    switch (option) {
    case 0: return reverse ? apointu : pointu;
    case 1: return reverse ? apodoblu : podoblu;
    case 2: return reverse ? apostringu : postringu;
    default: return NULL;
    }
}

// Главная функция
int main() {
    setlocale(LC_CTYPE, "Russian");

    struct group* g = new_group();
    if (!g) {
        perror("Ошибка создания группы");
        return EXIT_FAILURE;
    }

    while (1) {
        display_menu();

        int choice, age, index, sort_option;
        double point;
        char name[20], fname[20];
        cmp comparator;

        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Ошибка ввода\n");
            break;
        }

        switch (choice) {
        case 0:
            printf("Введите возраст, баллы и имя: ");
            if (scanf("%d %lf", &age, &point) != 2) {
                fprintf(stderr, "Ошибка ввода возраста и баллов\n");
                break;
            }
            scanf("%19s", name); // Чтение имени
            if (st_add(g, age, point, name)) {
                perror("Ошибка добавления студента");
            }
            break;
        case 1:
            printf("Введите индекс для удаления: ");
            if (scanf("%d", &index) != 1) {
                fprintf(stderr, "Ошибка ввода индекса\n");
                break;
            }
            if (st_del(g, index)) {
                perror("Ошибка удаления студента");
            }
            break;
        case 2:
            say(g);
            break;
        case 3:
            printf("Введите параметр для сортировки (0 - возраст, 1 - баллы, 2 - имя): ");
            if (scanf("%d", &sort_option) != 1) {
                fprintf(stderr, "Ошибка ввода параметра сортировки\n");
                break;
            }
            comparator = get_comparator(sort_option, 0);
            if (comparator) {
                start_heap_sort(g, comparator);
            } else {
                fprintf(stderr, "Неверный параметр сортировки\n");
            }
            break;
        case 4:
            printf("Введите имя файла: ");
            if (scanf("%19s", fname) != 1) {
                fprintf(stderr, "Ошибка ввода имени файла\n");
                break;
            }
            if (add_from_file(g, fname)) {
                perror("Ошибка добавления студента из файла");
            }
            break;
        case 5:
            printf("Введите имя файла: ");
            if (scanf("%19s", fname) != 1) {
                fprintf(stderr, "Ошибка ввода имени файла\n");
                break;
            }
            fsay(g, fname);
            break;
        case 6:
            printf("Введите параметр для обратной сортировки (0 - возраст, 1 - баллы, 2 - имя): ");
            if (scanf("%d", &sort_option) != 1) {
                fprintf(stderr, "Ошибка ввода параметра сортировки\n");
                break;
            }
            comparator = get_comparator(sort_option, 1);
            if (comparator) {
                start_heap_sort(g, comparator);
            } else {
                fprintf(stderr, "Неверный параметр сортировки\n");
            }
            break;
        case 7:
            printf("Введите тип диаграммы (0 - возраст, 1 - баллы): ");
            if (scanf("%d", &sort_option) != 1) {
                fprintf(stderr, "Ошибка ввода типа диаграммы\n");
                break;
            }
            bar_data(g, sort_option);
            break;
        case 8:
            printf("Введите тип круговой диаграммы (0 - возраст, 1 - баллы): ");
            if (scanf("%d", &sort_option) != 1) {
                fprintf(stderr, "Ошибка ввода типа диаграммы\n");
                break;
            }
            circle_data(g, sort_option);
            break;
        case 9:
            destroy(g);
            return EXIT_SUCCESS;
        default:
            fprintf(stderr, "Неверный выбор\n");
            break;
        }
    }

    destroy(g);
    return EXIT_FAILURE;
}

