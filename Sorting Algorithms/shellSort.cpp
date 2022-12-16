#include <iostream>
using namespace std;
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void shellSort(int arr[], int n)
{
    for (int gap = n/2; gap >= 1; gap=gap/2) 
    {
        for (int j = gap; j < n; j++)
        {
            for (int i = j-gap; i >= 0; i -= gap)
            {
                if (arr[i+gap]> arr[i])
                {
                    break;
                }else
                {
                    swap(arr[i+gap], arr[i]);
                }
            }
            
        }
        
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
    shellSort(arr, size);
    print(arr, size);

    return 0;
}