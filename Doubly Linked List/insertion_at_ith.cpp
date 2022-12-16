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
    node *current = new node();
    current->data = x;
    current->prev = NULL;
    current->next = NULL;
    node *temp1 = head;
    if (head == NULL && n==1)
    {
        head = current;
        return;
    }

    // first their are 2 cases whether the data is being entered at head node or at any other node
    if (n == 1) // checking whether the data is entered at head or not
    {
        current->next = head; // if data is entered at head node moving the previous head to (n+1)'s place
        head->prev = current;
        head = current; // storing the address of new head node in head
    }
    else
    {
        node *temp = head; // traversing to the given position
        for (int i = 0; i < n - 2; i++)
        {
            temp = temp->next;
        }
        if (temp->next == NULL) // now for case 2 whether the data is entered at last node or not
        {
            // if the data is entered at last just storing the address of new node in the (n-1)'s next part
            temp->next = current;
            current->prev = temp; // and also storing the (n-1)'s address to new node's previous part as it is the requirment of doubly linked list
        }
        else
        {                                 // if data is entered at any middle position of LL
            current->prev = temp;         // storing the address of (n-1)'s address to prev of current
            current->next = temp->next;   // storing (n+1)'s address to next of current
            (temp->next)->prev = current; //(temp->next) indicates (n+1) node so storing address of current node in (n+1)'s prev
            temp->next = current;         // storing address of current node in (n-1)'s next
        }
    }
}
void print()
{
    node *temp = new node();
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << endl;
}
void printReverse()
{
    node *temp = new node();
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    while (temp != NULL)
    {
        cout << temp->data << "-> ";
        temp = temp->prev;
    }
    cout << endl;
}
int main()
{
    head = NULL;
    ith(3, 1);  // 3
    ith(1, 1);  // 1,3
    ith(6, 2);  // 1,6,3
    ith(9, 3);  // 1,6,9,3
    ith(5, 5);  // 1,6,9,3,5
    ith(15, 1); // 1,6,9,3,5
    print();
    printReverse();
    return 0;
}
