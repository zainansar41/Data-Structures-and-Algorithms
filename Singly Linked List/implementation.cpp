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

int main()
{
    head = NULL;
    cout << "how many numbers you want to enter ";
    int n, i, x;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        /* code */
        cout << "enter the number you want to add ";
        cin >> x;

        add(x);
        printList();
    }

    return 0;
}
