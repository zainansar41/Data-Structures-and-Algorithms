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
void print(node *root)
{ // using inorder traversal
    if (root != NULL)
    {
        print(root->left);
        cout << root->data << "-> ";
        print(root->right);
    }
}
void levelOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    while (!(q.empty()))
    {
        node *current = q.front();
        cout << current->data << "  ";
        if (current->left != NULL)
        {
            q.push(current->left);
        }
        if (current->right != NULL)
        {
            q.push(current->right);
        }
        q.pop();
    }
}
int main()
{
    node *root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 21);
    root = insert(root, 23);
    root = insert(root, 25);
    root = insert(root, 8);
    root = insert(root, 12);
    print(root);
    cout << endl;
    levelOrder(root);
    return 0;
}