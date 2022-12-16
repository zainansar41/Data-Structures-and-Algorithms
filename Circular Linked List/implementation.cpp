#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *head;
void add(int n)
{
    int i, num;
    node *preptr, *newnode;
    head = new node();

        cout<<"enter data for 1st node";
        cin>>num;
        head->data = num;
        head->next = NULL;
        preptr = head;
        for(i=2; i<=n; i++)
        {
            newnode = new node();
            cout<<"enter data for "<<i<<" node";
            cin>>num;
            newnode->data = num;
            newnode->next = NULL;	// next address of new node set as NULL
            preptr->next = newnode;	// previous node is linking with new node
            preptr = newnode;   		// previous node is advanced
        }
        preptr->next = head; 
}
void print()
{
    node *temp = new node();
    temp = head;
    do
    {
        cout<<temp->data<<"->";

        temp = temp->next;
    } while (temp != head);
}

int main()
{
    head = NULL;
    int n;
    cout<<"how many numbers you want to enter";
    cin>>n;
    add(n);
    print();

    return 0;
}