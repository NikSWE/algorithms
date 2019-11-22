#include <stdio.h>

void print_array(int arr[], int n);
void merge_sort(int arr[], int l, int r);
void merge(int arr[], int l, int mid, int r);

int main()
{
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int n = sizeof(arr) / sizeof(int);

    printf("Unsorted Array: ");
    print_array(arr, n);

    merge_sort(arr, 0, n - 1);

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

void merge(int arr[], int l, int mid, int r)
{
    int k = l, lsize = mid - l + 1, rsize = r - mid;
    int larr[lsize], rarr[rsize];

    for (int i = l, j = 0; i <= mid; i++)
        larr[j++] = arr[i];

    for (int i = mid + 1, j = 0; i <= r; i++)
        rarr[j++] = arr[i];

    int i = 0, j = 0;

    while (i < lsize && j < rsize)
    {
        if (larr[i] > rarr[j])
            arr[k++] = rarr[j++];
        else
            arr[k++] = larr[i++];
    }

    while (i < lsize)
        arr[k++] = larr[i++];

    while (j < rsize)
        arr[k++] = rarr[j++];
}

void merge_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (r + l) / 2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}
