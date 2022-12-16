#include<iostream>
using namespace std;

void bubbleSort(int arr[], int size){
    int temp;
    for (int i = 0; i < size-1; i++)
    {
        for (int k = 0; k < (size-i-1); k++)
        {
            if (arr[k]>arr[k+1])
            {
                temp=arr[k];
                arr[k] = arr[k+1];
                arr[k+1]=temp;  
            }   
        }   
    }
}
void print(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<"->";
    }
}

int main(){
    int arr[]={3,5,1,8,9,16,8};
    int size= sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,size);
    print(arr,size);

    return 0;
}