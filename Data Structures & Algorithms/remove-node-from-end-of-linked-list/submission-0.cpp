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
        stack<ListNode*> nodes;

        nodes.push(head);

        while((nodes.top() -> next) != NULL) {
            nodes.push(nodes.top() -> next);
        }

        for(int i = 0; i < n; i++) {
            nodes.pop();
        }
        
        if(nodes.empty()) {
            ListNode* nextHead = head -> next;
            head -> next = NULL;
            delete head;
            return nextHead;
        }

        ListNode* toBeDeleted = nodes.top() -> next;
        nodes.top() -> next = toBeDeleted -> next;
        toBeDeleted -> next = NULL;

        delete toBeDeleted;

        return head;
    }
};