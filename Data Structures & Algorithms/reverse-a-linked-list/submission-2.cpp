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
        // Do I need to do this in place without making any new Nodes or can I make new nodes?

        // So if the linked list looks like this [1] -> [2] -> [3] then the new trnsformed linked list looks like this [3] -> [2] -> [1] right?
        // As one can see in the example the tail became the head and every node now points to a different node that was earlier point this node only.
        // So in the case of the linked list which earlier looked like [a] -> [b] -> [c] it now looks like [c] -> [b] -> [a] that is [b] now points to [a] which was pointing to [b] earlier.
        // Thus, every node now points to the previous node in the sequence.
        // We maintain 2 pointers - one that points to previous node to the current one and one that points to the current node.

        ListNode* curr = head;
        ListNode* prev = NULL; // The Node previous to head is obviously NULL.

        while(curr != NULL) { // While we do not reach the end of the list.
            ListNode* nxt = curr -> next; // We need the reference to the next of the current node in order to progress along with the List, but the reference to it will be lost as we make current point to the previous one so we store it for later.

            curr -> next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev; // Prev contains the tail of the linked list and curr contains NULL at the end.
    }
};