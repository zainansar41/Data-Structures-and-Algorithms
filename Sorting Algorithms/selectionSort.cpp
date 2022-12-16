#include <iostream>
using namespace std;

void selectionSort(int arr[], int size)
{
    int temp;
    for (int i = 0; i < size-1; i++)
    {
        int minInd = i;
        for (int k = i + 1; k < (size); k++)
        {
            if (arr[minInd] > arr[k])
            {
                minInd=k;
            }
        }
        temp = arr[i];
        arr[i] = arr[minInd];
        arr[minInd] = temp;
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
    selectionSort(arr, size);
    print(arr, size);

    return 0;
}