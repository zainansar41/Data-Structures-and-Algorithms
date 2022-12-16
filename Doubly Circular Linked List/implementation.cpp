#include <iostream>
using namespace std;
struct node
{
    int data;
    node *prev;
    node *next;
};
node *head;
void add(int x)
{
    node *newNode = new node();
    newNode->data = x;
    newNode->prev = NULL;
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    }
    else
    {
        node *temp = head;
        node *temporaty = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = head;
        head->prev = newNode;
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
    add(4);
    add(7);
    add(1);
    add(9);
    print();
    return 0;
}