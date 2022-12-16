#include <iostream>
using namespace std;

struct node
{
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
void pairwiseswap(){
    node* curr = head;
    node* prev = NULL;
 
    while (curr != NULL && curr->link != NULL)
    {
        node* next = curr->link;
        curr->link = next->link;
        next->link = curr;
        if (prev == NULL) {
            head = next;
        }
        else {
            prev->link = next;
        }
        prev = curr;
        curr = curr->link;
    }

}
//printList is just printing the entire singly linked list using iteration insted of recursion as in "reversingSLL_through_rrecursion_ZAIN.cpp"
void printList()
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->link;
    }
    cout << endl;
}
int main()
{
    head = NULL; // indicates linked list is empty
    int n, i, x;
    cout << "how many numbers you want to enter ";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cout << "enter the number you want to enter = ";
        cin >> x;
        add(x);
    }
    printList();
    cout<<"swaped"<<endl;
    pairwiseswap();
    printList();

    return 0;
}
