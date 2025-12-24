// Solution : 1

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp=head;
        while(temp!=NULL){
            ListNode* nextNode=temp->next;
            while(nextNode!=NULL && temp->val==nextNode->val)
            {
                ListNode* duplicate=nextNode;
                nextNode=nextNode->next;
                delete duplicate;
            }
            temp->next=nextNode;
            temp=temp->next;
        }
        return head;
    }
};

//Solution-2:
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;

        ListNode* curr = head;
        while (curr->next != NULL) {
            if (curr->val == curr->next->val) {
                ListNode* duplicate = curr->next;
                curr->next = curr->next->next;
                delete duplicate;  // free memory
            } else {
                curr = curr->next;
            }
        }
        return head;
    }
};
