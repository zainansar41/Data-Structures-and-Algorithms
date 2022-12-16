#include <iostream>
using namespace std;

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int value = arr[i];
        int hole = i - 1;
        while (hole >= 0 && arr[hole] < value)
        {
            arr[hole + 1] = arr[hole];
            hole = hole - 1;
        }
        arr[hole + 1] = value;
    }
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
    insertionSort(arr, size);
    print(arr, size);

    return 0;
}