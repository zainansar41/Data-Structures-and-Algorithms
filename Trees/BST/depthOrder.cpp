#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int leftHeight = 0; // so we don't have to declare again
int rightHeight = 0;
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
void inorder(node *root)
{ // using inorder traversal
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << "-> ";
        inorder(root->right);
    }
}
void preorder(node *root)
{ // using inorder traversal
    if (root != NULL)
    {
        cout << root->data << "-> ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node *root)
{ // using inorder traversal
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << "-> ";
    }
}
int main()
{
    node *root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 21);
    root = insert(root, 23);
    root = insert(root, 19);
    root = insert(root, 25);
    root = insert(root, 8);
    root = insert(root, 12);
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    return 0;
}