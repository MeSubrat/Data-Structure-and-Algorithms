#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left,*right;
    Node(int x)
    {
        data=x;
        left=right=NULL;
    }
};

class BinaryTree{
    public:
    Node *root;
    BinaryTree(){
        root=NULL;
    }
    void insert(int val)
    {
        Node *node=new Node(val);
        Node *current=root;
        if(root==NULL){
            root=node;
        }
        else{
            while(current)
            {
                if(val>current->data){
                    if(current->right==NULL){
                        current->right=node;
                        return;
                    }
                    current=current->right;
                }else{
                    if(current->left==NULL){
                        current->left=node;
                        return;
                    }
                    current=current->left;
                }
            }
        }
    }
    bool search(int val){
        Node *temp=root;
        while(temp!=NULL){
            if(val==temp->data)return true;
            temp=val<(temp->data) ? temp->left : temp->right;
        }
        return false;
    }
};

int main()
{
    BinaryTree bst;
    bst.insert(15);
    bst.insert(11);
    bst.insert(10);
    bst.insert(20);
    bst.insert(13);

    cout<<bst.search(16);
}