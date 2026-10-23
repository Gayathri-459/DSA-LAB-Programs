#include <stdio.h>
void bubbleSort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
void selectionSort(int a[], int n)
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}
void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;
    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;
    if (largest != i)
    {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(a, n, largest);
    }
}
void heapSort(int a[], int n)
{
    int i, temp;

    for (i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (i = n - 1; i > 0; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
    }
}
void display(int a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}
int main()
{
    int a[100], b[100], s[100], h[100];
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100)
    {
        printf("Invalid number of elements!\n");
        return 1;
    }
    printf("Enter %d elements: ", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
        s[i] = a[i];
        h[i] = a[i];
    }
    bubbleSort(b, n);
    selectionSort(s, n);
    heapSort(h, n);
    printf("\nBubble Sort: ");
    display(b, n);
    printf("Selection Sort: ");
    display(s, n);
    printf("Heap Sort: ");
    display(h, n);
    return 0;
}
