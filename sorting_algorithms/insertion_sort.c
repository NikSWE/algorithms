#include <stdio.h>

void print_array(int arr[], int n);
void insertion_sort(int arr[], int n);

int main()
{
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted Array: ");
    print_array(arr, n);

    insertion_sort(arr, n);

    printf("Sorted Array: ");
    print_array(arr, n);

    return 0;
}

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);

        if (i != n - 1)
            printf(" ");
    }
    printf("\n");
}

void insertion_sort(int arr[], int n)
{
    int in_hand, hole;

    for (int i = 1; i < n; i++)
    {
        hole = i;
        in_hand = arr[i];

        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > in_hand)
            {
                arr[j + 1] = arr[j];
                hole = j;
            }
        }

        arr[hole] = in_hand;
    }
}
