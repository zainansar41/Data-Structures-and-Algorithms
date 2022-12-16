#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};
node *getNewNode(int data)
{
    node *newNode = new node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node *insert(node *root, int data)
{
    if (root == NULL)
    {
        root = getNewNode(data);
        }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}
void print(node* root){//using inorder traversal
    if(root!=NULL){
        print(root->left);
        cout<<root->data<<"-> ";
        print(root->right);
    }

}
bool search(node* root, int n){
    if (root==NULL)
    {
        return false;
    }
    if (root->data==n)
    {
        return true;
    }
    else if (n<=root->data)
    {
        return search(root->left,n);
    }
    else if (n>root->data)
    {
        return search(root->right,n);
    }
    return 0;
}

int main()
{
    node *root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 8);
    root = insert(root, 12);
    print(root);
    cout<<endl;
    int n;
    cout<<"enter the number you want to search: ";
    cin>>n;
    if (search(root,n))
    {
        cout<<"found!";
    }
    else{
        cout<<"not found!";
    }
    
    return 0;
}