/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseLL(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;

        while (curr)
        {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    bool isPalindrome(ListNode *head)
    {
        // stack<int> st;
        // ListNode* temp=head;
        // if(head==NULL) return NULL;
        // while(temp)
        // {
        //     st.push(temp->val);
        //     temp=temp->next;
        // }
        // temp=head;
        // while(temp)
        // {
        //     if(temp->val!=st.top()) return false;
        //     temp=temp->next;
        //     st.pop();
        // }
        // return true;

        // OPTIMAL APPROACH
        // Find Half part
        ListNode *slow = head, *fast = head;
        while (fast->next != nullptr && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *newHead = reverseLL(slow->next);
        ListNode *temp1 = head;
        ListNode *temp2 = newHead;
        while (temp2 != nullptr)
        {
            if (temp1->val != temp2->val)
            {
                reverseLL(newHead);
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
};