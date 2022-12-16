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
    node *newnode = new node();
    newnode->data = x;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        node *temp = new node();
        temp = head;
        newnode->next = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        head = newnode;
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
int main()
{
    head = NULL;
    add(3);
    add(7);
    add(5);
    add(4);
    print();

    return 0;
}
