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
node* findMin(node *root)
{
    if (root == NULL)
    {
        cout << "error root is empty !" << endl;
        return root;
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
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

node *deletion(node *root, int data)
{
    if (root == NULL)
        return root;
    else if (data < root->data)
    {
        root->left = deletion(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deletion(root->right, data);
    }
    else
    {

        // case 1
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        // case : one child
        else if (root->left == NULL)
        {
            node *temp = root;
            root = temp->right;
            delete (temp);
        }
        else if (root->right == NULL)
        {
            node *temp = root;
            root = temp->left;
            delete (temp);
        }
        // case 3: 2 children
        else
        {
            node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deletion(root->right, root->data);
        }
    }
    return root;
}

int main()
{
    node *root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 18);
    root = insert(root, 19);
    root = insert(root, 25);
    root = insert(root, 22);
    root = insert(root, 21);
    root = insert(root, 26);
    root = insert(root, 8);
    root = insert(root, 12);
    print(root);
    cout << endl;
    deletion(root,20);
    print(root);
    cout<<endl;

    return 0;
}