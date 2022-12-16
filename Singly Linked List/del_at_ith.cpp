#include <iostream>
using namespace std;
struct node
{
    int data;
    node *link;
};
node* head;
void add(int x)//same as implementation.cpp
{
    node* temp = new node();
    temp->data = x;
    temp->link = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        node* temp1 = new node();
        temp1 = head;
        while (temp1->link != NULL)
        {
            temp1 = temp1->link;
        }
        temp1->link=temp;
    }
}
void print()//same as previous codes
{
    node* temp=new node();
    temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->link;
    }
    cout<<"NULL"<<endl;
    
}
void del(int n)
{
    node* temp=head;
    if (n==1)//case when we want to delete the first node data from linked list  
    {
        //first head is storing the address of temp where as temp-> storing the address of second node  
        head=temp->link;//rewritting the head and storing the address of second node
        delete(temp);//above line remove the data from the list but it is present in memory delete() deletes it from memory
        return;
    }
    for (int i = 0; i < n-2; i++)//(n-2) is used to traverse to the (n-1)node
    {
        temp=temp->link;//traversing to the (n-1)node
    }
    node* temp1=temp->link;//creating a temporary variable to store the address of (n)'s address
    temp->link=temp1->link;//storing (n+1)'s address to (n-1)'s link
    delete(temp1);//deleting from memory
    
}

int main()
{
    head = NULL;
    int n;
    add(2);
    add(8);
    add(1);
    add(5);
    print();
    cout << "enter the position from where you want to remove data = ";
    cin >> n;
    del(n);
    print();
    return 0;
}