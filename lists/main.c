#include <stdio.h>
#include <stdlib.h>
#include "header.h"

#define MAX_LISTS 10

int main()
{
    list **lists = (list **)malloc(MAX_LISTS * sizeof(list *));
    int num_lists = 0;
    int current_list_index = -1;

    while(1)
    {
        if (num_lists >= MAX_LISTS)
        {
            printf("Maximum number of lists reached (%d).\n", MAX_LISTS);
            break;
        }

        printf("1. Create new list\n");
        printf("2. Select list\n");
        printf("3. Create copy\n");
        printf("4. Delete the list\n");
        printf("5. Add after\n");
        printf("6. Add before\n");
        printf("7. Delete current\n");
        printf("8. Go next\n");
        printf("9. Go prev\n");
        printf("10. Print current\n");
        printf("11. Print the list\n");
        printf("12. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        int list_index, element;

        switch(choice)
        {
            case 1:
                lists[num_lists] = create();
                if (current_list_index == -1)
                {
                    current_list_index = num_lists;
                }
                printf("New list created at index %d.\n", num_lists);
                num_lists++;
                break;
            case 2:
                printf("Enter the index of the list to select: ");
                scanf("%d", &list_index);
                if (list_index >= 0 && list_index < num_lists)
                {
                    current_list_index = list_index;
                }
                else
                {
                    printf("Invalid list index.\n");
                }
                break;
            case 3:
                if (current_list_index != -1)
                {
                    lists[num_lists] = create_copy(lists[current_list_index]);
                    current_list_index = num_lists;
                    printf("Copy of the current list created at index %d.\n", num_lists);
                    num_lists++;

                }
                else
                {
                    printf("No list selected.\n");
                }
                break;
            case 4:
                if (current_list_index != -1)
                {
                    list_free(lists[current_list_index]);
                    for (int i = current_list_index; i < num_lists - 1; i++)
                    {
                        lists[i] = lists[i + 1];
                    }
                    num_lists--;
                    current_list_index = -1;
                    printf("List deleted.\n");

                }
                else
                {
                    printf("No list selected.\n");
                }
                break;
            case 5:
                if (current_list_index != -1)
                {
                    printf("Enter value to add after: ");
                    scanf("%d", &element);
                    lists[current_list_index] = add_after(lists[current_list_index], element);
                }
                else
                {
                    printf("No list selected.\n");
                }
                break;
            case 6:
                if (current_list_index != -1)
                {
                    printf("Enter value to add before: ");
                    scanf("%d", &element);
                    lists[current_list_index] = add_before(lists[current_list_index], element);
                }
                else
                {
                    printf("No list selected.\n");
                }
                break;
            case 7:
                if (current_list_index != -1)
                {
                    lists[current_list_index] = elem_delete(lists[current_list_index]);
                }
                else
                {
                    printf("No list selected.\n");
                }
                break;
            case 8:
                if (current_list_index != -1)
                {
                    lists[current_list_index] = move_next(lists[current_list_index]);
                }
                else
                {
                    printf("No list selected.\n");
                }
                break;
            case 9:
                if (current_list_index != -1)
                {
                    lists[current_list_index] = move_prev(lists[current_list_index]);
                }
                else
                {
                    printf("No list selected.\n");
                }
                break;
            case 10:
                if (current_list_index != -1)
                {
                    printf("Current value: %d\n", print_elem(lists[current_list_index]));
                }
                else
                {
                    printf("No list selected.\n");
                }
                break;
            case 11:
                if (current_list_index != -1)
                {
                    printf("List elements:\n");
                    print_list(lists[current_list_index]);
                }
                else
                {
                    printf("No list selected.\n");
                }
                break;
            case 12:
                for(int i = 0; i < num_lists; i++)
                {
                    list_free(lists[i]);
                }
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
