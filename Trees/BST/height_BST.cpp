#include <iostream>
#include<algorithm>
using namespace std;
int leftHeight=0;//so we don't have to declare again 
int rightHeight=0;
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
int Height(node* root){
    if (root==NULL)
    {
        return -1;//height of leaf node is "0"
    }
    leftHeight=Height(root->left);
    rightHeight=Height(root->right);
    return max(leftHeight,rightHeight)+1;
    
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
    cout<<endl;   
    cout<<"height is : "<<Height(root)<<endl;
    return 0;
}