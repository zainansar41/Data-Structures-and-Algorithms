#include <iostream>
using namespace std;
struct node
{
    int data;
    node *prev;
    node *next;
};
node *head;
void ith(int x, int n)
{
    node *newnode = new node();
    node *temp = head;
    newnode->data = x;
    if (n == 1)
    {
        if (head == NULL)
        {
            head = newnode;
            newnode->next = head;
            newnode->prev = head;
            return;
        }

        newnode->next = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
        head = newnode;
    }
    else
    {
        for (int i = 0; i < n - 2; i++)
        {
            temp = temp->next;
        }
        if (temp->next == head)
        {
            newnode->next = temp->next;
            newnode->prev = temp;
            temp->next = newnode;
        }
        else
        {
            newnode->prev = temp;
            newnode->next = temp->next;
            temp->next = newnode;
        }
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
    ith(4, 1); // 4
    ith(6, 2); // 4,6
    ith(1, 1); // 1,4,6
    ith(0, 4); // 1,4,6,0
    ith(9, 2); // 1,9,4,6,0
    print();
    return 0;
}