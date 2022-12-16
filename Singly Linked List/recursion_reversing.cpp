#include<iostream>
using namespace std;

struct node
{
    int data;
    node* link;
};
node* head;
void add(int x)
{
    node *temp = new node();
    temp->data = x;
    temp->link = head;
    head = temp;
}
void reverse(node* p){
    if (p->link==NULL)
    {
        head=p;
        return;
    }
    reverse(p->link);
    node* q=p->link;
    q->link=p;
    p->link=NULL;
}
void print(node *p)
{
    if (p == NULL)
    {
        return;
    }

    cout << p->data << "->";
    print(p->link);
}
int main(){
    head=NULL;
    add(2);
    add(6);
    add(7);
    add(1);
    add(3);
    print(head);
    cout<<endl;
    reverse(head);
    print(head);

    return 0;
}