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
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> nodes;

        nodes.push(NULL);

        while(head != NULL) {
            nodes.push(head);

            head = head -> next;
        }

        head = nodes.top();

        while(!nodes.empty()) {
            ListNode* currNode = nodes.top();

            nodes.pop();
            if(currNode == NULL) {
                continue;
            }

            currNode -> next = nodes.top();
        }

        return head;
    }
};
