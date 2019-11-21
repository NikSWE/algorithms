#include <stdio.h>
#include <stdbool.h>

void print_array(int arr[], int n);
void bubble_sort(int arr[], int n);

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted Array: ");
    print_array(arr, n);

    bubble_sort(arr, n);

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

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int temp;
        bool is_sorted = true;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                is_sorted = false;
            }
        }

        printf("Pass %d: ", i + 1);
        print_array(arr, n);

        if (is_sorted)
            break;
    }
}
