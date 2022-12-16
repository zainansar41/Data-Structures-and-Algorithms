#include<iostream>
using namespace std;
const int MAX=101;
int Array[MAX];
int top=-1;
bool isEmpty(){
    if (top==-1)
    {
        return true;
    }
    return false;
}

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

void conversion(int num, int base){
    if (num<0 || base<=1)
    {
        cout<<"number can't be convert"<<endl;
        return;
    }
    while (num>0)
    {
        int temp=num % base;
        push(temp);
        num=num / base;
    }
    
    while (!(isEmpty()))
    {
        cout << topPop() << "  ";
        pop();
    }
    cout<<endl;
    
    
}


int main(){
    int number, base;
    cout<<"enter a decimal number = ";
    cin >> number;
    cout<<"enter base in which you want to convert number = ";
    cin >> base;
    conversion(number, base);



    return 1;
}

