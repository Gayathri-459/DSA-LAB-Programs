
#include <stdio.h>
#define MAX 5
int queue[MAX];
int priority[MAX];
int n = 0;
void insert()
{
    int value, p;

    if (n == MAX)
    {
        printf("Priority Queue is Full\n");
    }
    else
    {
        printf("Enter value: ");
        scanf("%d", &value);

        printf("Enter priority: ");
        scanf("%d", &p);

        queue[n] = value;
        priority[n] = p;
        n++;

        printf("Element inserted successfully\n");
    }
}
void delete()
{
    int i, pos = 0;

    if (n == 0)
    {
        printf("Priority Queue is Empty\n");
    }
    else
    {
        for (i = 1; i < n; i++)
        {
            if (priority[i] < priority[pos])
                pos = i;
        }

        printf("Deleted element: %d\n", queue[pos]);

        for (i = pos; i < n - 1; i++)
        {
            queue[i] = queue[i + 1];
            priority[i] = priority[i + 1];
        }

        n--;
    }
}
void display()
{
    int i;

    if (n == 0)
    {
        printf("Priority Queue is Empty\n");
    }
    else
    {
        printf("Value\tPriority\n");

        for (i = 0; i < n; i++)
            printf("%d\t%d\n", queue[i], priority[i]);
    }
}
int main()
{
    int choice;
    while (1)
    {
        printf("\n--- PRIORITY QUEUE ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
