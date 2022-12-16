#include <iostream>
using namespace std;

struct node
{
    /* data */
    int data;
    node *link;
};
// declaring head a global pointer variable of type struct
node *head;
void add(int val)
{
    node *temp = new node();

    // below two lines store data in memory but we don't connect it with linked list
    temp->data = val;
    temp->link = NULL;

    if (head == NULL)
    {
        head = temp; // indicates it is the start of Linked list
    }
    else
    {
        // else part deals when there is some data in the linked list

        node *temp1 = new node();
        temp1 = head;             

        // while loop is to traverse the linked list bcz we want to store data at the end of linked list
        while (temp1->link != NULL)
        {
            temp1 = temp1->link;
        } // end of loop indicates we have found the end of linked list

        temp1->link = temp; // storing the n's node address in (n-1)'s node link
    }
}
void printList()
{
    node *temp = head;
    while (temp != NULL)
    {
        /* code */
        cout << temp->data << "->";
        temp = temp->link;
    }
    cout << endl;
}
void ith(int x, int n)
{
    node *temp = new node(); // store data and link of next node
    node *temp1 = head;      // for traversing
    temp->data = x;
    temp->link = NULL;
    if (n == 1)
    {                      // case when list is empty
        temp->link = head; // just the case of node_at_beggining
        head = temp;       // initializing the head to address of new created node
        return;            // return is important here
    }
    for (int i = 0; i < n - 2; i++) // traversing to the desired position
    {
        /* code */
        temp1 = temp1->link; // as implementation.cpp
    }
    temp->link = temp1->link; // storing the address of next node to the link of newly created node
    temp1->link = temp;
}
int main()
{
    head = NULL;
    cout << "how many numbers you want to enter ";
    int n, i, x, p;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        /* code */
        cout << "enter the number you want to add ";
        cin >> x;

        add(x);
        printList();
    }

    cout << "Enter the number you want to enter ";
    cin >> x;
    cout << "Enter the position at which you want to enter ";
    cin >> p;

    ith(x, p);
    printList();

    return 0;
}
