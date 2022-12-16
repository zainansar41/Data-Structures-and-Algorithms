#include <iostream>
using namespace std;
const int MAX=101;
int Array[MAX];
int top=-1;

void push(int x){
    if (top== MAX-1)
    {
        cout<<"error - stack overflow";
        return;
    }
    top++;
    Array[top]=x;
}

void pop(){
    if (top==-1)
    {
        cout<<"error - No element is present in array"<<endl;
        return;
    }
    top--;
}

int topPop(){
    return Array[top];
}

void print(){
    int i;
    cout<<"stack = ";
    for ( i = 0; i <=top; i++)
    {
        cout<<Array[i]<<"   ";
    }
    cout<<endl;
    
}

int main(){
    push(2);print();
    push(5);print();
    push(7);print();
    push(1);print();
    pop();
    pop();
    push(12);print();

    return 0;
}