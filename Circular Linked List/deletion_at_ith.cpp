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
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
        head = newnode;
    }
}
void del(int n)
{
    node *temp = new node();
    node *temp1 = new node();
    temp=head;
    temp1=head;
    if (n == 1)
    {
        while (temp1->next != head)
        {
            temp1 = temp1->next;
        }
        head = temp->next;
        temp1->next = head;
        delete (temp);
    }
    else
    {
        for (int i = 0; i < n - 2; i++)
        {
            temp = temp->next;
        }
        if (temp->next == head)
        {
            temp1 = temp->next;
            temp->next = head;
            delete (temp1);
        }
        else
        {
            temp1 = temp->next;
            temp->next = temp1->next;
            delete (temp1);
        }
    }
}
void print()
{
    node *temp = new node();
    temp = head;
    do
    {
        cout << temp->data << "-> ";
        temp = temp->next;
    } while (temp != head);
}
int main()
{
    add(4);
    add(0);
    add(1);
    add(3);
    print();
    cout << endl;
    del(1);
    print();
    return 0;
}