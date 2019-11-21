#include <stdio.h>

void print_array(int arr[], int n);
void selection_sort(int arr[], int n);

int main()
{
    int arr[] = {9, 8, 4, 2, 6, 7, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted Array: ");
    print_array(arr, n);

    selection_sort(arr, n);

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

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i, temp;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
                min = j;
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;

        printf("Pass %d: ", i + 1);
        print_array(arr, n);
    }
}
