#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node* left,*right;
    Node(int x)
    {
        val=x;
        left=right=NULL;
    }
};

class BinaryTree{
    public:
    BinaryTree(){
        root=NULL;
    }
    void insert(int val)
    {
        Node* newNode=new Node(val);
        Node* currentNode=root;
        if(root==NULL)root=currentNode;
        else{
            while(true)
            {
                if(val<currentNode->val)
                {
                    if(!currentNode->left)
                    {
                        currentNode->left=newNode;
                        return;
                    }
                    currentNode=currentNode->left;
                }
                else{
                    if(!currentNode->right)
                    {
                        currentNode->right=newNode;
                        return;
                    }
                    currentNode=currentNode->right;
                }
            }
        }
    }

    void inorderTraverse()
    {
        
    }
    bool lookup(int val)
    {
        if(root==NULL)return false;
        else{
            if(root==NULL)return false;
            Node* currentNode=root;
            while(currentNode)
            {
                if(val<currentNode->val)
                {
                    currentNode=currentNode->left;
                }else if(val>currentNode->val)
                {
                    currentNode=currentNode->right;
                }
                else if(currentNode->val==val)return true;
            }
        }
        return false;
    }
    void remove()
    {
        
    }
    Node* getRoot()
    {
        return root;
    }
    private:
    Node* root;
};

void print(vector<int> &arr)
{
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    BinaryTree tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    cout<<tree.lookup(1);
}