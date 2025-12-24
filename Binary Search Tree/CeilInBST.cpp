#include <bits/stdc++.h>
using namespace std;

template <typename T>

// Binary tree Node template
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Insertion Into BST
BinaryTreeNode<int> *insertBST(BinaryTreeNode<int> *root, int data)
{
    if (root == NULL)
    {
        return new BinaryTreeNode<int>(data);
    }
    if (data < root->data)
    {
        root->left = insertBST(root->left, data);
    }
    else
    {
        root->right = insertBST(root->right, data);
    }
}
// Find Ceil in BST
int findCeil(BinaryTreeNode<int> *root, int key)
{
    int ceil = -1;
    while (root)
    {
        if (root->data == key)
        {
            ceil = root->data;
            return ceil;
        }
        if (key > root->data)
        {
            root = root->right;
        }
        else
        {
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}

/*----------------Traversals--------------*/
// Inorder
void inorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    BinaryTreeNode<int> *root = NULL;
    vector<int> values = {8, 4, 12, 2, 6, 10, 14};
    for (int val : values)
    {
        root = insertBST(root, val);
    }
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    int key = 5;
    cout << "Ceil of " << key << " is: " << findCeil(root, key) << endl;
}