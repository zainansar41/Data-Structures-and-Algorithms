#include <iostream>
using namespace std;

void countSort(int arr[], int n, int pass)
{
    int Outputarr[n];
    int count[10];

    for (int i = 0; i < 10; i++) // initializing 0
    {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        count[(arr[i]/pass)%10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        Outputarr[count[(arr[i] / pass) % 10] - 1] = arr[i];
        count[(arr[i] / pass) % 10]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = Outputarr[i];
    }
}
void radixSort(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++) // for max
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    for (int pass = 1; (max/pass) >0 ; pass*=10)
    {
        countSort(arr,n,pass);
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
    int arr[] = {432,8,530,90,88,231,11,45,677,199};
    int size = sizeof(arr) / sizeof(arr[0]);
    radixSort(arr, size);
    print(arr, size);

    return 0;
}