#include <iostream>
using namespace std;
struct node
{
    int data;
    node *link;
};
node *head;
node* tail=NULL;
bool isEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int front()
{
    return head->data;
}
void enqueue(int x)
{
    node *temp = new node();
    temp->data = x;
    temp->link = NULL;
    if (head == NULL)
    {
        head = temp;
        tail=temp;
    }
    else
    {
        tail->link=temp;//dping this to make time complexity to O(1)
        tail=temp;
        
        // node *temp1 = head;
        // while (temp1->link != NULL)
        // {
        //     temp1 = temp1->link;
        // }
        // temp1->link = temp;
    }
}
void dequeue()
{
    node *temp = new node();
    temp = head;
    head = temp->link;
    delete (temp);
}
void print(node *p)
{
    if (p == NULL)
    {
        return;
    }
    cout << p->data << " ";
    print(p->link);
}

int main()
{
    head = NULL;
    enqueue(2);
    enqueue(4);
    enqueue(7);
    enqueue(1);
    print(head);
    cout << endl;
    cout << front();
    cout << endl;
    dequeue();
    print(head);

    return 0;
}
