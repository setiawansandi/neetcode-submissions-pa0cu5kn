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
        int carry = 0;
        ListNode* ans = new ListNode(0);
        ListNode* head = ans;

        while(l1 || l2) {
            int l1Val = l1 ? l1->val : 0;
            int l2Val = l2 ? l2->val : 0;
            int sum = carry + l1Val + l2Val;

            carry = sum / 10;
            ans->next = new ListNode(sum % 10);

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            ans = ans->next;
        }

        if (carry == 1) ans->next = new ListNode(1);
        return head->next;
    }
};
