#include <iostream>
using namespace std;
void merge(int arr[], int n, int left[], int nl, int right[], int nr)
{
    int i, j, k;
    i = 0;
    j = 0;
    k = 0;
    while (i < nl && j < nr)
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = right[j];
            k++;
            j++;
        }
    }
    while (i < nl)
        arr[k++] = left[i++];
    while (j < nr)
        arr[k++] = right[j++];
}
void mergeSort(int arr[], int n)
{
    int mid, i;
    if (n < 2)
    {
        return;
    }

    mid = n / 2;
    int left[mid];
    int right[n - mid];
    for (i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }
    for (i = mid; i < n; i++)
    {
        right[i - mid] = arr[i];
    }
    mergeSort(left, mid);
    mergeSort(right, n - mid);
    merge(arr, n, left, mid, right, n - mid);
}
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "->";
    }
}

int main()
{
    int arr[] = {3, 5, 1, 8, 9, 16, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, size);
    print(arr, size);

    return 0;
}