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
void del(int n)
{
    node *temp = new node();
    node *temp1 = new node();
    temp = head;
    temp1 = head;
    if (n == 1)
    {
        while (temp1->next != head)
        {
            temp1 = temp1->next;
        }
        head = temp->next;
        head->prev = temp1;
        temp1->next = head;
        delete (temp);
    }
    else
    {
        for (int i = 0; i < n - 2; i++)
        {
            temp1 = temp1->next;
        }
        temp = temp1->next;
        if (temp->next == head)
        {
            temp1->next = head;
            head->prev = temp1;
            delete (temp);
        }
        else
        {
            temp1->next = temp->next;
            delete (temp);
        }
    }
}
int main()
{
    head = NULL;
    ith(3, 1); // 3
    ith(4, 1); // 4,3
    ith(6, 2); // 4,6,3
    ith(1, 1); // 1,4,6,3
    ith(100, 1); // 100,1,4,6,3
    ith(0, 4); // 100,1,4,0,6,3
    ith(9, 2); // 100,9,1,4,0,6,3
    ith(9, 2); // 100,9,9,1,4,0,6,3
    print();
    cout << endl;
    del(1);//9,9,1,4,0,6,3
    del(7);//9,9,1,4,0,6
    print();
    return 0;
}