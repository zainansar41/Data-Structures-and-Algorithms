#include<iostream>
using namespace std;
struct node
{
    int data;
    node* link;
};
node* top=NULL;

void push(int x){
    node* newnode= new node();
    newnode->data=x;
    newnode->link=top;
    top=newnode;
}

void pop(){
    node* nodedel=top;
    if (top==NULL)
    {
        return;
    }
    
    top=nodedel->link;
    delete(nodedel);
}
void print(node* p){
    if (p==NULL)
    {
        return;
    }

    print(p->link);
    cout<<p->data<<"   ";
}

int main(){
    push(2);
    push(4);
    push(0);
    push(1);
    print(top);
    pop();
    print(top);

    return 0;
}
