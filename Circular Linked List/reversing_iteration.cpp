#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *head;
void add(int x)
{
    node *newnode = new node;
    newnode->data = x;
    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
}
void print()
{
    node *temp = new node();
    temp = head;
    do
    {
        cout << temp->data << "->";

        temp = temp->next;
    } while (temp != head);
}
void reverse()
{
    node *prev, *next, *current,*temp;
    temp=head;
    current=head;
    prev=NULL;
    do
    {
        next=current->next;
        current->next=prev;

        prev=current;
        current=next;
    } while (current!=head);
    head=prev;
    temp->next=head;
    
}
int main()
{
    add(4);
    add(7);
    add(1);
    add(9);
    print();
    cout<<endl;
    reverse();
    print();
    return 0;
}