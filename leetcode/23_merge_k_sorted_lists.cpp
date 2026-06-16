/*
23. Merge k Sorted Lists
Solved in 28'36''
Hard

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        bool flag = true;
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (flag) {
            ListNode* min = new ListNode(10000, nullptr);
            flag = false;
            int idx = 0;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] == nullptr) continue;
                if (lists[i] != nullptr && lists[i]->val < min->val) {
                    flag = true;
                    min->val = lists[i]->val;
                    idx = i;
                }
            }
            if (!flag) break;
            if (lists[idx]->next != nullptr) {
                lists[idx] = lists[idx]->next;
            } else {
                lists[idx] = nullptr;
            }
            tail->next = min;
            tail = tail->next;
        }

        return dummy.next;
    }
};

// AI's cleaner answer:
class Solution {
public:
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for (auto node : lists) {
            if (node) pq.push(node);
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* cur = pq.top();
            pq.pop();

            tail->next = cur;
            tail = tail->next;

            if (cur->next) {
                pq.push(cur->next);
            }
        }

        return dummy.next;
    }
};