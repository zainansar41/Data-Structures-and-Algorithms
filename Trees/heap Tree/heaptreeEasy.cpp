#include<iostream>
#include<stack>
using namespace std;
stack<int> inAscending;
void swap1(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int parent(int data)
{
    return (data - 1) / 2;
}
int arr[5];
int n=0;
void insert(int key)
{
    
    arr[n] = key;
    int i = n;
    while (i > 0 && arr[i] > arr[parent(i)])
    {
        swap1(&arr[i], &arr[parent(i)]);
        i = parent(i);
    }
    n++;
}
int delete_heap()
{
    int x = arr[0];
    arr[0] = arr[n - 1];
    n--;
    int i = 0;
    int j = 2 * i + 1;
    while (j < n - 1)
    {
        if (arr[j + 1] > arr[j])
        {
            j = j + 1;
        }
        if (arr[i] < arr[j])
        {
            swap1(&arr[i], &arr[j]);
            i = j;
            j = 2 * j + 1;
        }
        else
        {
            break;
        }
    }
    if (arr[i] < arr[j])
        {
            swap1(&arr[i], &arr[j]);
            i = j;
            j = 2 * j + 1;
        }
    return x;
}
void inAscendingOrder(){
    while (n != 0)
    {
        inAscending.push(delete_heap());
    }

    while (!(inAscending.empty()))
    {
        cout << inAscending.top()<<"  ";
        inAscending.pop();
    }
    cout<<endl;
}

int main(){
    insert(35);
    insert(36);
    insert(37);
    insert(26);
    insert(39);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<< endl;
    inAscendingOrder();
    return 0;
}
