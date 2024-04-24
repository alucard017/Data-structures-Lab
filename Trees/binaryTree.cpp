#include <iostream>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *newNode(int data)
{
    node *new_node = new node;
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void InOrder(node *root)
{
    if (root != NULL)
    {
        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);
    }
}

void PreOrder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
void PostOrder(node *root)
{
    if (root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->data << " ";
    }
}
int countLeaf(node *node)
{
    if (node == NULL)
        return 0;
    if (node->left == NULL && node->right == NULL)
        return 1;
    else
        return countLeaf(node->left) + countLeaf(node->right);
}
int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    cout << "In Order traversal of tree is " << endl;
    InOrder(root);
    cout << endl;
    cout << "Pre Order traversal of tree is " << endl;
    PreOrder(root);
    cout << endl;
    cout << "Post Order traversal of tree is : " << endl;
    PostOrder(root);
    cout << endl;
    cout << "The number of Leaf Nodes in the tree is: " << countLeaf(root) << endl;
    return 0;
}