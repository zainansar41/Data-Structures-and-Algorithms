#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(int arr[], int len, int i)
{
    int large = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < len && arr[left] > arr[large])
    {
        large = left;
    }

    if (right < len && arr[right] > arr[large])
    {
        large = right;
    }

    if (large != i)
    {
        swap(arr[i], arr[large]);
        heapify(arr, len, i);
    }
}

void buildHeap(int arr[], int len)
{
    int lastWithChilds = (len / 2) - 1;

    for (int i = lastWithChilds; i >= 0; i--)
        heapify(arr, len, i);
}

void display(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heapSort(int arr[], int len)
{
    for (int i = len - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void deleteRoot(int arr[], int &len)
{
    int lastElement = arr[len - 1];
    // Replace root with last element
    arr[0] = lastElement;
    // Decrease size of heap by 1
    len = len - 1;
    // heapify the root node
    heapify(arr, len, 0);
}

int main()
{
    int arr[] = {35, 25, 14, 11, 24, 8, 12, 1};
    int len = sizeof(arr) / sizeof(arr[0]);

    deleteRoot(arr, len);
    buildHeap(arr, len);
    display(arr, len);

    // heapSort(arr, len);
    // display(arr, len);
}
