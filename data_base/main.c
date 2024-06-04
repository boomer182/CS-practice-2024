#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "graphics.h"
#include "header.h"

// ������� ��� �����������
void display_menu() {
    printf("0: ���������� (���� ��������, ������ � �����)\n");
    printf("1: �������� �� �������\n");
    printf("2: ����� �� �����\n");
    printf("3: ���������� (0 - �������, 1 - �����, 2 - ���)\n");
    printf("4: ���������� �� ����� (����� ������ ��� �����)\n");
    printf("5: ������ � ���� (����� ������ ��� �����)\n");
    printf("6: ���������� � �������� ������� (0 - �������, 1 - �����, 2 - ���)\n");
    printf("7: ����� ���������� ��������� (0 - ����� ���������� ���������, 1 - ����� �������� ���������)\n");
    printf("8: ����� �������� ��������� (0 - �� ��������, 1 - �� ������)\n");
    printf("9: �����\n");
}

// ������� ��� ��������� ������� ���������
cmp get_comparator(int option, int reverse) {
    switch (option) {
    case 0: return reverse ? apointu : pointu;
    case 1: return reverse ? apodoblu : podoblu;
    case 2: return reverse ? apostringu : postringu;
    default: return NULL;
    }
}

// ������� �������
int main() {
    setlocale(LC_CTYPE, "Russian");

    struct group* g = new_group();
    if (!g) {
        perror("������ �������� ������");
        return EXIT_FAILURE;
    }

    while (1) {
        display_menu();

        int choice, age, index, sort_option;
        double point;
        char name[20], fname[20];
        cmp comparator;

        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "������ �����\n");
            break;
        }

        switch (choice) {
        case 0:
            printf("������� �������, ����� � ���: ");
            if (scanf("%d %lf", &age, &point) != 2) {
                fprintf(stderr, "������ ����� �������� � ������\n");
                break;
            }
            scanf("%19s", name); // ������ �����
            if (st_add(g, age, point, name)) {
                perror("������ ���������� ��������");
            }
            break;
        case 1:
            printf("������� ������ ��� ��������: ");
            if (scanf("%d", &index) != 1) {
                fprintf(stderr, "������ ����� �������\n");
                break;
            }
            if (st_del(g, index)) {
                perror("������ �������� ��������");
            }
            break;
        case 2:
            say(g);
            break;
        case 3:
            printf("������� �������� ��� ���������� (0 - �������, 1 - �����, 2 - ���): ");
            if (scanf("%d", &sort_option) != 1) {
                fprintf(stderr, "������ ����� ��������� ����������\n");
                break;
            }
            comparator = get_comparator(sort_option, 0);
            if (comparator) {
                start_heap_sort(g, comparator);
            }
            else {
                fprintf(stderr, "�������� �������� ����������\n");
            }
            break;
        case 4:
            printf("������� ��� �����: ");
            if (scanf("%19s", fname) != 1) {
                fprintf(stderr, "������ ����� ����� �����\n");
                break;
            }
            if (add_from_file(g, fname)) {
                perror("������ ���������� �������� �� �����");
            }
            break;
        case 5:
            printf("������� ��� �����: ");
            if (scanf("%19s", fname) != 1) {
                fprintf(stderr, "������ ����� ����� �����\n");
                break;
            }
            fsay(g, fname);
            break;
        case 6:
            printf("������� �������� ��� �������� ���������� (0 - �������, 1 - �����, 2 - ���): ");
            if (scanf("%d", &sort_option) != 1) {
                fprintf(stderr, "������ ����� ��������� ����������\n");
                break;
            }
            comparator = get_comparator(sort_option, 1);
            if (comparator) {
                start_heap_sort(g, comparator);
            }
            else {
                fprintf(stderr, "�������� �������� ����������\n");
            }
            break;
        case 7:
            printf("������� ��� ��������� (0 - �������, 1 - �����): ");
            if (scanf("%d", &sort_option) != 1) {
                fprintf(stderr, "������ ����� ���� ���������\n");
                break;
            }
            bar_data(g, sort_option);
            break;
        case 8:
            printf("������� ��� �������� ��������� (0 - �������, 1 - �����): ");
            if (scanf("%d", &sort_option) != 1) {
                fprintf(stderr, "������ ����� ���� ���������\n");
                break;
            }
            circle_data(g, sort_option);
            break;
        case 9:
            destroy(g);
            return EXIT_SUCCESS;
        default:
            fprintf(stderr, "�������� �����\n");
            break;
        }
    }

    destroy(g);
    return EXIT_FAILURE;
}
