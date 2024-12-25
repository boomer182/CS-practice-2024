#include "header.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    rb_tree *tree = rb_alloc();
    if (!tree)
    {
        printf("Ошибка при выделении памяти для дерева.\n");
        return 1;
    }

    int choice;
    key_t key;
    while (1)
    {
        printf("\nВыберите действие:\n");
        printf("1. Вставить элемент\n");
        printf("2. Удалить элемент\n");
        printf("3. Вывести дерево\n");
        printf("4. Черная высота\n");
        printf("5. Красная высота\n");
        printf("6. Общая высота\n");
        printf("7. Количество элементов\n");
        printf("8. Количество листьев\n");
        printf("9. Выход\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Введите ключ для вставки: ");
                scanf("%d", &key);
                if (rb_insert(tree, key) == 0)
                {
                    printf("Элемент успешно вставлен.\n");
                }
                else printf("Ошибка при вставке элемента.\n");
                break;

            case 2:
                printf("Введите ключ для удаления: ");
                scanf("%d", &key);
                if (rb_delete(tree, key) == 0)
                {
                     printf("Элемент успешно удален.\n");
                }
                else printf("Элемент с таким ключом не найден.\n");
                break;

            case 3:
                printf("Дерево:\n");
                print(tree->root);
                break;

            case 4:
                printf("Черная высота: %d\n", black_height(tree));
                break;

            case 5:
                printf("Красная высота: %d\n", max_red_height(tree));
                break;

            case 6:
                printf("Общая высота дерева: %d\n", tree_height(tree->root));
                break;

            case 7:
                printf("Количество элементов дерева: %d\n", rb_count(tree));
                break;

            case 8:
                printf("Количество листьев дерева: %d\n", rb_leaves(tree));
                break;

            case 9:
                printf("Выход.\n");
                rb_free(tree);
                return 0;

            default:
                printf("Некорректный ввод.\n");
        }
    }

    getch();
    return 0;
}
