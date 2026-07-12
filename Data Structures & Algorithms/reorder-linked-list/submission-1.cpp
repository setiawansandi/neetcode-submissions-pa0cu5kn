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
    void reorderList(ListNode* head) {
        // get midpoint
        ListNode *slow = head, *fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse 2nd half
        ListNode *curr = slow->next;
        slow->next = nullptr;

        ListNode *prev = nullptr;
        while(curr) {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        ListNode* list1 = head;
        ListNode* list2 = prev;
        // combine
        while(list2) {
            ListNode *temp1 = list1->next;
            ListNode *temp2 = list2->next;
            list1->next = list2;
            list2->next = temp1;
            list2 = temp2;
            list1 = temp1;
        }        

    }
};
