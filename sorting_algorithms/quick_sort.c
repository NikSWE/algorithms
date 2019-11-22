#include <stdio.h>

void print_array(int arr[], int n);
void quick_sort(int arr[], int l, int r);
int partition(int arr[], int l, int r);

int main()
{
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int n = sizeof(arr) / sizeof(int);

    printf("Unsorted Array: ");
    print_array(arr, n);

    quick_sort(arr, 0, n - 1);

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

int partition(int arr[], int l, int r)
{
    int pivot = arr[l], pindex = l + 1;

    for (int i = l + 1; i <= r; i++)
    {
        if (arr[i] <= pivot)
        {
            int temp = arr[pindex];
            arr[pindex++] = arr[i];
            arr[i] = temp;
        }
    }

    int temp = arr[pindex - 1];
    arr[pindex - 1] = arr[l];
    arr[l] = temp;

    return pindex - 1;
}

void quick_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int pindex = partition(arr, l, r);
        quick_sort(arr, l, pindex - 1);
        quick_sort(arr, pindex + 1, r);
    }
}
