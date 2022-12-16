#include<iostream>
using namespace std;

struct node
{
    int data;
    node* prev;
    node* next;
};
node* head;

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
int main(){
    head=NULL;
    addHead(2);
    addHead(5);
    addHead(6);
    addHead(1);
    addHead(0);


    print();
    return 0;
}