#include <iostream>
using namespace std;
struct node
{
    /* data */
    int data;
    node *link;
};
node *head;
void add(int x)//same as implementation.cpp
{
    node *temp = new node();
    temp->data = x;
    temp->link = NULL;
    if (head == NULL)
    {
        head = temp;
        return;
    }
    else
    {
        node *temp1 = new node();
        temp1 = head;
        while (temp1->link != NULL)
        {
            /* code */
            temp1 = temp1->link;
        }
        temp1->link = temp;
    }
}
void print()//same as previous codes
{
    node *temp = head;
    while (temp != NULL)
    {
        /* code */
        cout << temp->data << "->";
        temp = temp->link;
    }
    cout << "NULL"<<endl;
}
void reverse(){
    node *current, *prev, *next;//taking 2 extra temporary variables name as next and prev whereas current is equal to temp(previous codes)
    current=head;//like previous codes
    prev=NULL;//but here we store NULL to prev. why? bcz in first iteration means first node we want to store NULL so it behave like last node

    while (current != NULL)//like previous case iterating the loop
    {
        /* code */
        next=current->link;//storing the address of next node(n+1) for prevention of data loss in next(temparary)
        current->link=prev;//storing the address of (n-1)'s node in n->link in first case it will store NULL as we stored and not changed it
        

        //below to statements will be use to move to the next node
        
        prev=current;//storing the address of node which link part is changed so it become the (n-1 node)
        current=next;//storing the address of (n+1) node to current so it behave like "N" node in the next iteration
    }
    head=prev;
    
}
int main()
{
    head = NULL;
    add(4);
    add(3);
    add(5);
    add(9);
    add(1);
    print();
    reverse();
    print();

    return 0;
}
