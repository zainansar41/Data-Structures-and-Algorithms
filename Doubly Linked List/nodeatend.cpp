#include<iostream>
using namespace std;

struct node
{
    int data;
    node* prev;
    node* next;
};
node* head;
void addTail(int x){
    node* newNode=new node();
    newNode->data=x;//(*newNode).data
    newNode->next=NULL;
    newNode->prev=NULL;  
    if (head==NULL)
    {
        head=newNode;
        return;
    }
    node* temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
      
}
void print(){
    node* temp=new node();
    temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"-> ";
        temp=temp->next;
    }
    cout<<endl;
    
}
int main(){
    head=NULL;
    addTail(1);
    addTail(8);
    addTail(0);
    addTail(67);
    addTail(9);

    print();
    return 0;
}