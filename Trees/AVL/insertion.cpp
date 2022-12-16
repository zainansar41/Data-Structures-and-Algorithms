#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
    int height;
};
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int getHeight(node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

node *createNode(int data)
{
    node *newNode = new node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int getBalance(node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    // return n->left->height - n->right->height; to make it simple we write is as
    return getHeight(n->left) - getHeight(n->right);
}

node *rightRotate(node *y)
{
    node *x = y->left;
    node *t2 = x->right;

    x->right = y;
    y->left = t2;
    // Now we have to update heights
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    return x; // because now x will be the root
}
node *leftRotate(node *x)
{
    node *y = x->right;
    node *t2 = y->left;

    y->left = x;
    x->right = t2;
    // Now we have to update heights
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    return y; // because now y will be the root
}

node *insert(node *n, int key)
{
    if (n == NULL)
    {
        return createNode(key);
    }
    if (key < n->data)
    {
        n->left = insert(n->left, key);
    }
    else if (key > n->data)
    {
        n->right = insert(n->right, key);
    }
    n->height = 1 + max(getHeight(n->right), getHeight(n->left));
    int bf = getBalance(n);
    // if it is unbalance then we have 4 cases

    // left left bf will be greater than 1
    if (bf > 1 && key < n->left->data)
    {
        return rightRotate(n);
    }

    // right right
    if (bf < -1 && key > n->right->data)
    {
        return leftRotate(n);
    }
    // left right
    if (bf > 1 && key > n->left->data)
    {
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }
    // right left
    if (bf < -1 && key < n->right->data)
    {
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }
    return n;
}
void printTree(node *root) {
  if (root != nullptr) {
    printTree(root->left);
    cout << root->data << endl;
    printTree(root->right);
  }
}

int main()
{
    node *root = NULL;
    root = insert(root, 33);
    root = insert(root, 13);
    root = insert(root, 53);
    root = insert(root, 9);
    root = insert(root, 21);
    root = insert(root, 61);
    root = insert(root, 8);
    root = insert(root, 11);
    printTree(root);
    return 0;
}
