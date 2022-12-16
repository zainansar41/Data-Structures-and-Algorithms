#include <iostream>
using namespace std;

struct node
{
    int data;
    node *link;
};
node *head;
node *headPrimeNo;
void add(int x)
{
    node *temp = new node(); // remember temp is the pointer variable and we are derefrencing its value to modify the value
    temp->data = x;
    // as we want to store the data at start of the list we have to store address of starting node "head" inside temp(which is the new starting node)
    temp->link = head;
    // As we already say that head store the starting node address so we rewrite the head by storing the new starting node(temp)
    head = temp; // instead of writting in if statement we can write this
}
bool IsPrimeNumber(int x)
{
    if (x < 2)//this is indicating " 1 " is not a prime number
    {
        return false;
    }
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}


//addPrimeAtBeg is same as add
void addPrimeAtBeg(int x)
{
    node *temp = new node();
    temp->data = x;
    temp->link = headPrimeNo;
    headPrimeNo = temp;
}
void seperatingPrimeNo()
{
    node *p = head;
    node *q;
    while (p)//instead of writing "p!=NULL" we can just write the "P" in condtion of while loop
    {
        int data;

        if (IsPrimeNumber(head->data))
        {

            data = head->data;
            head = p->link;
            delete (p);
            addPrimeAtBeg(data);
            p = head;// reassigning the address of head in P as address of p is deleted when we use delete funtion
        }
        else if (IsPrimeNumber(p->data))
        {
            data=p->data;
            q->link = p->link;
            delete (p);
            p = q->link;//moving to the (n+1)'s address because "N" is deleted
            addPrimeAtBeg(data);//adding the data part of deleted node
        }
        else//if the value of node is not a prime number we just move to the next node 
        {
            q = p;
            p = p->link;
        }
    }
}
void printList(node *p)
{

    node *temp = p;
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
    head = NULL; // indicates linked list is empty
    headPrimeNo = NULL;
    int n, i, x;
    cout << "how many numbers you want to enter ";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cout << "enter the number you want to enter = ";
        cin >> x;
        add(x);
    }
    printList(head);
    cout << endl;
    seperatingPrimeNo();
    printList(headPrimeNo);
    cout << endl;
    printList(head);

    return 0;
}
