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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // So, we have a linked list that goes from head to tail and we have to reverse it.
        // But not in the traditional sense - as we do not have to reverse the entire linked list rather, we have to keep separating k groups out of it one by one reverse that group of nodes, and then fit that group exactly where we extracted the previous group.
        // So, how do we proceed with this? we can keep extracting k length groups first we reverse it and after reversing it the tail of that sublist has become the head of the sublist to be inserted back into the actual list, and the head of the previous sublist becomes the new tail so we point the previous group's tail to the new head of this group and point the tail of this group to the head of next group.

        ListNode* prevTail = NULL;
        ListNode* currNode = head;

        while(currNode != NULL) {
            int length = 1;
            ListNode* currTail = currNode;

            while((length < k) && ((currTail -> next) != NULL)) {
                currTail = currTail -> next;
                length++;
            }

            if(length < k) {
                break;
            }

            ListNode* nextHead = currTail -> next;

            ListNode* prev = NULL;
            ListNode* node = currNode;

            while(node != nextHead) {
                ListNode* nxt = node -> next;
                node -> next = prev;
                prev = node;
                node = nxt;
            }

            if(prevTail == NULL) {
                head = currTail;
            } else {
                prevTail -> next = currTail;
            }
            currNode -> next = nextHead;

            prevTail = currNode;
            currNode = nextHead;
        }

        return head;
    }
};