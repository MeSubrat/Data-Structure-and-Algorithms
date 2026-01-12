// BRUTE FORCE
// TC - O(N) SC - O(N)

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        unordered_map<ListNode *, int> mpp;
        ListNode *temp = head;
        while (temp)
        {
            // Check the node is present or not
            if (mpp.find(temp) != mpp.end())
                return temp;
            // If not present push the node into map
            mpp[temp] = 1;
            // Move temp
            temp = temp->next;
        }
        return nullptr;
    }
};

// Optmial Solution
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            ;

            // Detect Loop
            if (slow == fast)
            {
                // Find Starting point
                slow = head;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // Or return fast;
            }
        }
        return nullptr;
    }
};