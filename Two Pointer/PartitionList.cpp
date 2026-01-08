class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp = head;
        ListNode* l1 = new ListNode(0);
        ListNode* l2 = new ListNode(0);
        ListNode* l1Head = l1;
        ListNode* l2Head = l2;
        if(head == NULL || head->next == NULL) return head;

        while(temp){
            if(temp->val < x){
                l1->next = temp;
                l1 = l1->next;
                temp = temp->next;
            }
            else{
                l2->next = temp;
                l2 = l2->next;
                temp = temp->next;
            }
        }
        l1Head = l1Head->next;
        l2Head = l2Head->next;


        l1->next = l2Head;
        l2->next = NULL;
        if(l1Head == NULL){
            return l2Head;
        }else{
            return l1Head;
        }

    }
};