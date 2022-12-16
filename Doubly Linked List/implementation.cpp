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
void addHead(int x){
    node* newNode=new node();
    newNode->data=x;//(*newNode).data is same
    newNode->next=NULL;
    newNode->prev=NULL;
    if(head==NULL){
        head=newNode;
        return;
    }
    head->prev=newNode;
    newNode->next=head;
    head=newNode;
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
void printReverse(){
    node* temp=new node();
    temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }

    while (temp!=NULL)
    {
        cout<<temp->data<<"-> ";
        temp=temp->prev;
    }
    cout<<endl;
        
}
int main(){
    head=NULL;
    addHead(2);
    addHead(5);
    addTail(1);
    addTail(8);

    print();
    printReverse();
    return 0;
}