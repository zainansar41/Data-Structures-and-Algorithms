//here we make some changes in node_at_beg.cpp for more concepts
//instead of making "head" a global variable we make it local variable in main function
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *link;
};
//we just pass only one data type in previous case but here we also pass head data in it
node* add(int x, node* head){ 
    //head in add is local variable
    node* temp= new node();
    temp->data=x;
    temp->link=head;
    head=temp;
    //as head is local variable here so we have to return the changes we dd in it that's why we use node* add instead of void in this funtion
    return head;
}

void print(node *p)
{
    if (p == NULL)
    {
        return;
    }
    //to understand these concept see a link page here
    cout << p->data << " ";
    print(p->link);
}
void recursionPrint(node* p){
    if (p == NULL)
    {
        return;
    }

    recursionPrint(p->link);
    cout << p->data << " ";
}

int main()
{
    node *head=NULL;
    //by calling add funtion we also have to rewrite the changes we did in head in adds
    head=add(2,head);
    head=add(6,head);
    head=add(7,head);
    head=add(3,head); 
    head=add(0,head); 
    print(head);
    cout<<endl;
    recursionPrint(head);


    return 0;
}
