#include<iostream>
using namespace std;

struct node
{
    int data;
    node* prev;
    node* next;
};
node* head;
//addHead is simply adding the new node at the begining of doubly linked list
void addHead(int x){
    node* newNode=new node();
    newNode->data=x;//(*newNode).data is same
    newNode->next=NULL;
    newNode->prev=NULL;
    if(head==NULL){
        head=newNode;
        return;
    }
    head->prev=newNode;
    newNode->next=head;
    head=newNode;
}
void pairwiseswap(){
    node* curr = head;//curr is use to traverse the entire Linked list
    node* prev = NULL;//prev is use to only for the first swap where we have to update the address of head pointer 
 
    while (curr != NULL && curr->next != NULL)
    {
        node* next = curr->next;
        curr->next = next->next;
        next->next = curr;
        curr->prev = next;
        if (prev == NULL) {//this check is just updating the head pointer address so we have the address of first node after swaping
            head = next;
            head->prev=NULL;
        }
        else {
            prev->next = next;
            next->prev = prev;
        }
        prev = curr;
        curr = curr->next;
    }

}
//printlist function is used to print the whole doubly linked list
void printList(){
    node* temp=new node();
    temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"-> ";
        temp=temp->next;
    }
    cout<<endl;
    
}
int main(){
    head=NULL;
    int n, i, x;
    cout << "how many numbers you want to enter ";
    cin >> n;
    //using loop so code minimize
    for (i = 0; i < n; i++)
    {
        cout << "enter the number you want to enter = ";
        cin >> x;
        addHead(x);
    }
    printList();
    pairwiseswap();
    cout<<"swapped"<<endl;
    printList();
    return 0;
}