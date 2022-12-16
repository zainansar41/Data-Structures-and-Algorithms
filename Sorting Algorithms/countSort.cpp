#include <iostream>
using namespace std;

void countSort(int arr[], int n)
{
    int Outputarr[n];
    int max = arr[0];
    for (int i = 1; i < n; i++) // for max
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    int count[max];

    for (int i = 0; i <= max; i++) // initializing 0
    {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    for (int i = 1; i <= max; i++)
    {
        count[i] +=  count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        Outputarr[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = Outputarr[i];
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
    countSort(arr, size);
    print(arr, size);

    return 0;
}