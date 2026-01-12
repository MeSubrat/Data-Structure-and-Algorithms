# 🐢🐇 Tortoise and Hare Algorithm (Floyd’s Cycle Detection)

## 📌 Overview

The Tortoise and Hare Algorithm is used to detect cycles in a linked list using constant extra space.

---

## 🧠 When to Use This Algorithm

- Detect a cycle in a linked list
- Find the starting node of a loop
- When O(1) space is required

---
## How to use it in array:
- The array must ask something about duplicacy.
- You can able to traverse thorugh the indices of the array. E.g: **Find Duplicate number in array**

## ❌ When NOT to Use

- When extra memory is allowed and simplicity is preferred
- When random access is needed

---

## 🔍 How It Works

1. Use two pointers (slow and fast)
2. Move slow by 1 step and fast by 2 steps
3. If both meet, a cycle exists
4. Reset slow to head to find cycle start

---

## 💻 Sample Code (C++) : Detect the starting point of the loop

```cpp
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};
```
