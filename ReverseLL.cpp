#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int data)
    {
        this->val = data;
        this->next = nullptr;
    }
};

Node *arrToLL(vector<int> arr)
{
    if (arr.size() == 0)
        return nullptr;
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode; // link
        temp = newNode;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
}
Node *reverseLL(Node *head)
{
    Node *prev = nullptr;
    Node *curr = head;

    while (curr)
    {
        Node *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node *head = arrToLL(arr);
    Node* newHead = reverseLL(head);
    print(newHead);
}