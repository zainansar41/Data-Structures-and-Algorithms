#include <iostream>
using namespace std;
struct node
{
    int data;
    node *prev;
    node *next;
};
node *head;
void ith(int x, int n)//adding at any position
{
    node *current = new node();
    current->data = x;  //initializing the data
    current->prev = NULL;
    current->next = NULL;
    //first their are 2 cases whether the data is being entered at head node or at any other node
    if (n == 1)//checking whether the data is entered at head or not 
    {
        current->next = head;//if data is entered at head node moving the previous head to (n+1)'s place
        head = current;//storing the address of new head node in head
    }
    else
    {
        node *temp = head;//traversing to the given position
        for (int i = 0; i < n - 2; i++)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)//now form case 2 whether the data is entered at last node or not
        {//if the data is entered at last just storing the address of new node in the (n-1)'s next part
            temp->next = current;
            current->prev = temp;//and also storing the (n-1)'s address to new node's previous part as it is the requirment of doubly linked list
        }
        else
        {//if data is entered at any middle position of LL 
            current->prev = temp;//storing the address of (n-1)'s address to prev of current 
            current->next = temp->next;//storing (n+1)'s address to next of current 
            (temp->next)->prev = current;//(temp->next) indicates (n+1) node so storing address of current node in (n+1)'s prev
            temp->next = current;//storing address of current node in (n-1)'s next
        }
    }
}
void del(int n){
    node* temp=new node();
    temp=head;
    node* temp1=new node();
    if (n==1)
    {
        //first their are 2 cases whether the data is being entered at head node or at any other node
        head=temp->next;//storing (n+1)'s address to the head so it behave like new N node(head node)
        head->prev=NULL;//as in doubly LL prev of First node is NULL
        delete(temp); //deleting the node
        return;
    }
    for (int i = 0; i < n-2; i++)//traversing
    {
        temp=temp->next;
    }
    temp1=temp->next;//for deletion storing the address of node to be deleted in another temporary vaariable
    if (temp1->next==NULL)//checking whether the node is last or not if it is last its next part must be null
    {
        temp->next=NULL;//if the N node is NULL then storing (n-1)'s next part to NULL so it behaves like last node
        delete(temp1);
        return;
    }

    temp1->next->prev=temp;//storing (n-1)'s address in (n+1)'s so link is break with N node
    temp->next=temp1->next;//storing (n+1)'s address in (n-1)'s so link is break with N node
    delete(temp1);
    
}
void print()//same as previous 
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

int main()
{
    head = NULL;
    ith(3, 1); // 3
    ith(1, 1); // 1,3
    ith(6, 2); // 1,6,3
    ith(9, 3); // 1,6,9,3
    ith(5, 5); // 1,6,9,3,5
    print();
    del(2);    //1,9,3,5
    print();
    return 0;
}
