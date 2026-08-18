/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // So, I just have to figure out whether there exists a cycle in the given list?
        // I do not need to return the node from where the cycle starts?

        // If a list does not have a cycle and we have two pointers travelling through the list one that travels only one step at a time and the other one that moves 2 steps at a time starting from the head - then there's no way that these 2 will ever meet each other if there is no cycle in the list.
        // If the list does have some sort of a cycle then they would travel up till such extent that would have to meet at some point.
        // Thus, if the 2 pointers meet there is a cycle in the list otherwise if we encounter a NULL pointer then we have most certainly found a NULL pointer.

        ListNode* slowPtr = head;
        ListNode* fastPtr = head;

        while((slowPtr != NULL) && (fastPtr != NULL) && ((fastPtr -> next) != NULL)) {
            // If the list does have a cycle this loop will never terminate until the 2 pointers meet somewhere.

            slowPtr = slowPtr -> next;
            fastPtr = fastPtr -> next -> next;
            if(slowPtr == fastPtr) {
                return true; // We have encountered a cycle.
            }
        }

        return false; // If the while loop terminated without returning anything then there's no loop.
    }
};