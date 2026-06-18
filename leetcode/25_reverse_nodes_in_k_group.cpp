/*
25. Reverse Nodes in k-Group
Solved in 41'42''
Hard

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
 

Follow-up: Can you solve the problem in O(1) extra memory space?
*/

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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* cluster = &dummy;

        while (true) {
            ListNode* prev = cluster;
            for (int i = 0; i < k; i++) {
                prev = prev->next;

                if (prev == nullptr)
                    return dummy.next;
            }
            ListNode* old = cluster->next;

            for (int pass = k - 1; pass > 0; --pass) {
                ListNode* prev = cluster;
                for (int step = 0; step < pass; ++step) {
                    SwapTwo(prev);
                }
            }

            cluster = old;
        }

        return dummy.next;
    }

    void SwapTwo(ListNode* &prev) {
        if (!prev || !prev->next || !prev->next->next)
            return;
        ListNode* first = prev->next;
        ListNode* second = first->next;

        first->next = second->next;
        second->next = first;
        prev->next = second;

        prev = second;
    }
};

// AI's cleaner answer:
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* groupPrev = &dummy; // The node right before our current k-group

        while (true) {
            // 1. Check if we have k nodes left to reverse
            ListNode* kth = getKth(groupPrev, k);
            if (!kth) {
                break; // Not enough nodes, leave them as is
            }
            
            ListNode* groupNext = kth->next; // The node right after our current k-group
            
            // 2. Reverse the k group
            ListNode* prev = groupNext; // Start prev at groupNext to connect the tail automatically
            ListNode* curr = groupPrev->next;
            
            while (curr != groupNext) {
                ListNode* nextTemp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextTemp;
            }
            
            // 3. Connect the reversed group back to the previous part of the list
            ListNode* tmp = groupPrev->next; // tmp is the old head of the group (now the tail)
            groupPrev->next = kth;           // Connect the previous section to the new head
            groupPrev = tmp;                 // Move groupPrev forward for the next iteration
        }

        return dummy.next;
    }

private:
    // Helper function to find the k-th node
    ListNode* getKth(ListNode* curr, int k) {
        while (curr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }
};