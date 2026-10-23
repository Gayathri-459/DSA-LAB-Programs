
#include <stdio.h>
#define SIZE 10
int hashTable[SIZE];
void insert(int key)
{
    int index = key % SIZE;
    int start = index;
    while (hashTable[index] != -1)
    {
        index = (index + 1) % SIZE;
        if (index == start)
        {
            printf("Hash table is full!\n");
            return;
        }
    }
    hashTable[index] = key;
    printf("%d inserted at index %d\n", key, index);
}
void display()
{
    int i;

    printf("\nHash Table:\n");

    for (i = 0; i < SIZE; i++)
    {
        if (hashTable[i] == -1)
            printf("Index %d: Empty\n", i);
        else
            printf("Index %d: %d\n", i, hashTable[i]);
    }
}
int main()
{
    int i, n, key;
    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    printf("Enter number of keys (max %d): ", SIZE);
    scanf("%d", &n);
    if (n < 0 || n > SIZE)
    {
        printf("Invalid number of keys!\n");
        return 1;
    }
    for (i = 0; i < n; i++)
    {
        printf("Enter key: ");
        scanf("%d", &key);
        insert(key);
    }
    display();
    return 0;
}
