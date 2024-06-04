#include "header.h"

int main()
{
    setlocale(LC_ALL, "Rus");

    rb_tree *tree = rb_alloc();
    if (!tree)
    {
        printf("������ ��� ��������� ������ ��� ������.\n");
        return 1;
    }

    int choice;
    key_t key;
    while (1)
    {
        printf("\n�������� ��������:\n");
        printf("1. �������� �������\n");
        printf("2. ������� �������\n");
        printf("3. ������� ������\n");
        printf("4. ������ ������\n");
        printf("5. ������� ������\n");
        printf("6. ����� ������\n");
        printf("7. ���������� ���������\n");
        printf("8. ���������� �������\n");
        printf("9 �����\n");
        printf("��� �����: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("������� ���� ��� �������: ");
                scanf("%d", &key);
                if (rb_insert(tree, key) == 0)
                {
                    printf("������� ������� ��������.\n");
                }
                else printf("������ ��� ������� ��������.\n");
                break;

            case 2:
                printf("������� ���� ��� ��������: ");
                scanf("%d", &key);
                if (rb_delete(tree, key) == 0)
                {
                     printf("������� ������� ������.\n");
                }
                else printf("������� � ����� ������ �� ������.\n");
                break;

            case 3:
                printf("������:\n");
                print(tree->root);
                break;

            case 4:
                printf("������ ������: %d\n", black_height(tree));
                break;

            case 5:
                printf("������� ������: %d\n", max_red_height(tree));
                break;

            case 6:
                printf("����� ������ ������: %d\n", tree_height(tree->root));
                break;

            case 7:
                printf("���������� ��������� ������: %d\n", rb_count(tree));
                break;

            case 8:
                printf("���������� ������ ������: %d\n", rb_leaves(tree));
                break;

            case 9:
                printf("�����.\n");
                rb_free(tree);
                return 0;

            default:
                printf("������������ ����.\n");
        }
    }

    getch();
    return 0;
}
