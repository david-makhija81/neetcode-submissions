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
        vector<ListNode*> nodesInSequence;

        while(head != NULL) {
            nodesInSequence.push_back(head);

            head = head -> next;
        }

        ListNode* tail = NULL;

        int left = 0, right = nodesInSequence.size() - 1;

        while(left <= right) {
            if(tail != NULL) {
                tail -> next = nodesInSequence[left];
            }

            tail = nodesInSequence[left];
            left++;

            if(left > right) {
                break;
            }

            tail -> next = nodesInSequence[right];

            tail = nodesInSequence[right];
            right--;
        }

        tail -> next = NULL;
    }
};
