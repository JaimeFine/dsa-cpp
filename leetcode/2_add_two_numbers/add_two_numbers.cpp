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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode();
        ListNode* head = l3;
        bool flag = 0;
        while (l1 || l2 || flag) {
            int sum = 0;
            if (flag) {
                sum += 1;
                flag = 0;
            }
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            if (sum >= 10) {
                sum -= 10;
                flag = 1;
            }
            head->next = new ListNode(sum);
            head = head->next;
        }

        return l3->next;
    }
};
