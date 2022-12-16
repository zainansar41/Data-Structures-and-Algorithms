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
void add(int x)
{
    node *temp = new node(); // remember temp is the pointer variable and we are derefrencing its value to modify the value

    temp->data = x;

    // as we want to store the data at start of the list we have to store address of starting node "head" inside temp(which is the new starting node)
    temp->link = head;
    
    // As we already say that head store the starting node address so we rewrite the head by storing the new starting node(temp)
    head = temp; // instead of writting in if statement we can write this
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
    head = NULL; // indicates linked list is empty
    cout << "how many numbers you want to enter ";
    int n, i, x;
    cin >> n;

    for (i = 0; i < n; i++)
    {
        /* code */
        cout << "enter the number you want to enter = ";
        cin >> x;
        add(x);
        printList();
    }

    return 0;
}
