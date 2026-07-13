/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> nodePair;

        Node* dummy = new Node(0);
        Node* curr = dummy;
        Node* headBak = head;

        while(head) {
            curr->next = new Node(head->val);
            nodePair[head] = curr->next;
            curr = curr->next;
            head = head->next;
        }

        curr = dummy;
        head = headBak;
        while(head) {
            curr->next->random = nodePair[head->random];
            curr = curr->next;
            head = head->next;
        }

        return dummy->next;
    }
};
