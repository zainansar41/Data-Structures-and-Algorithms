#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};
node* head;
void add(int x, int n){
    node* newnode=new node();
    newnode->data=x;
    if (n==1)
    {
        newnode->next=head;
        head=newnode;
    }else
    {
        node* temp=new node();
        temp=head;
        for (int i = 0; i < n-2; i++)
        {
            temp=temp->next;
        }
        if (temp->next==head)
        {
            temp->next=newnode;
            newnode->next=head;
        }else
        {
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
}
void print(){
    node* temp=new node();
    temp=head;
    do
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    } while (temp!=head);
    
}
int main(){
    head=NULL;
    add(2,1);//2
    add(5,1);//5,2
    add(4,3);//5,2,4
    add(0,3);//5,2,0,4
    add(9,1);//5,2,0,4
    print();

    return 0;
}