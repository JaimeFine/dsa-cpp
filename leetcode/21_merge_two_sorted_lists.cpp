/*
21. Merge Two Sorted Lists
Solved in 47'05''
Easy

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        if (list1->val > list2->val) {
            swap(list1, list2);
        }
        ListNode head1 = ListNode(0, list1);
        ListNode head2 = ListNode(0, list2);
        ListNode *temp1 = head1.next, *temp2 = head2.next;
        ListNode* temp = nullptr;
        ListNode* prev1 = &head1;

        if (temp1 == nullptr && temp2 == nullptr) {
            return head1.next;
        } else if (temp1 == nullptr && temp2 != nullptr) {
            return head2.next;
        } else if (temp1 != nullptr && temp2 == nullptr) {
            return head1.next;
        }

        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val <= temp2->val) {
                if (temp1->next == nullptr) {
                    temp1->next = temp2;
                    prev1 = temp1;
                    break;
                }
                if (temp1->next->val <= temp2->val) {
                    prev1 = temp1;
                    temp1 = temp1->next;
                } else {
                    temp = temp1->next;
                    temp1->next = temp2;
                    temp2 = temp2->next;
                    temp1->next->next = temp;
                    prev1 = temp1->next;
                    temp1 = temp1->next;
                }
            } else {
                if (temp2->next != nullptr && temp2->next->val <= temp1->val) {
                    temp2 = temp2->next;
                    prev1 = temp1;
                } else {
                    prev1->next = temp2;
                    temp = temp2->next;
                    temp2->next = temp1;
                    temp2 = temp;
                    prev1 = prev1->next;
                }
            }
        }
        return head1.next;
    }
};

// AI's cleaner answer:
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        if (list1 != nullptr)
            tail->next = list1;
        else
            tail->next = list2;

        return dummy.next;
    }
};