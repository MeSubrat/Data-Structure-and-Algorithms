#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int x)
    {
        val=x;
        left=right=NULL;
    }
};
class BST{
    public:
    
    BST(){
        root=NULL;
    }

    void insert(int val)
    {
        Node* currNode;
        Node* newNode=new Node(val);
        if(root==NULL) {
            root=newNode;
        }
        currNode=root;
        while(true)
        {
            if(val<currNode->val)
            {
                if(!currNode->left){
                    currNode->left=newNode;
                    return;
                }
                currNode=currNode->left;
            }
            else{
                if(!currNode->right){
                    currNode->right=newNode;
                    return;
                }
                currNode=currNode->right;
            }
        }
    }
    void preTraversal()
    {
        preTraversal(root);
        cout<<endl;
    }
    private:
    Node* root;
    void preTraversal(Node* node)
    {
        if(node==NULL) return;
        cout<<root->val;
        preTraversal(node->left);
        preTraversal(node->right);
    }
};

int main()
{
    BST tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.preTraversal();
}