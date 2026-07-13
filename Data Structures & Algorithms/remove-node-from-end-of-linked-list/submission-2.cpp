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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = new ListNode(0, head);
        ListNode* end = start;

        for(int i = 0; i < n; ++i) {
            end = end->next;
        }

        while(end->next) {
            end = end->next;
            start = start->next;
        }

        if(start->next == head) {
            if(!start->next->next) {
                delete head;
                return nullptr;
            }
            start->next = head->next;
            delete head;
            return start->next;
        }
        ListNode* temp = start->next;
        start->next = start->next->next;
        delete temp;

        return head;
    }
};
