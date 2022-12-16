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

int findMin(node* root){
    if (root==NULL)
    {
        cout<<"error root is empty !"<<endl;
        return -1;
    }
    while (root->left!=NULL)
    {
        root=root->left;
    }
    return root->data;
}
int findMax(node* root){
    if (root==NULL)
    {
        cout<<"error root is empty !"<<endl;
        return -1;
    }
    while (root->right!=NULL)
    {
        root=root->right;
    }
    return root->data;
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
    cout<<"Max is : "<<findMax(root)<<endl;
    cout<<"Min is : "<<findMin(root)<<endl;
    
    return 0;
}