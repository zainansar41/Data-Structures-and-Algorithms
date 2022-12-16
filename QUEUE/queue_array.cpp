#include<iostream>
using namespace std;

const int MAX=100;
int Array[MAX];
int front=-1;
int rear=-1;
bool isEmpty(){
    if(front==-1 && rear==-1){
        return true;
    }else
    {
        return false;
    }
    
}
int frontIndex(){
    return Array[front];
}

void enqueue(int x){
    if (isEmpty())
    {
        front=0;
        rear=0;
    }else
    {
        rear=rear+1;
    }
    Array[rear]=x;
}
void dequeue(){
    for (int i = 0; i < rear+1; i++)
    {
        Array[i]=Array[i+1];
    }
    rear=rear-1;
}
void print(){
    for (int i = 0; i <= rear; i++)
    {
        cout<<Array[i]<<"  ";
    }
    cout<<endl;
}


int main(){
    enqueue(4);
    enqueue(7);
    enqueue(8);
    enqueue(1);
    print();
    dequeue();
    cout<<frontIndex()<<endl;
    print();


    return 0;
}