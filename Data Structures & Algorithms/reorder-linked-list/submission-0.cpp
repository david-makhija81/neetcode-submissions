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

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* currNode = head;

        while(currNode != NULL) {
            ListNode* nxt = currNode -> next;

            currNode -> next = prev;
            prev = currNode;
            currNode = nxt;
        }

        return prev;
    }

    void mergeLists(ListNode* list1, ListNode* list2) {
        while((list1 != NULL) && (list2 != NULL)) {
            ListNode* list1Next = list1 -> next;

            list1 -> next = list2;
            
            ListNode* list2Next = list2 -> next;

            list2 -> next = list1Next;

            list1 = list1Next;
            list2 = list2Next;
        }
    }

public:
    void reorderList(ListNode* head) {
        // Are we provided with the count of the number of nodes in the list?
        // Are the number of nodes even or it can be anything?
        // If the number of nodes are odd then does reordered list look something as follows:
        // [1] -> [2] -> [3] -> [4] -> [5]     Original List
        // [1] -> [5] -> [2] -> [4] -> [3]     Reordered List

        // So, I need to reverse the second half of the linked list and then merge the 2 halves is what you are trying to say?

        // I suppose, watching the problem through the above lens gives one solution to the problem.
        // We first count the number of nodes, then we divided the list in two halves.
        // After that we reverse the second half, and then we merge the unchanged first half with the reversed second half.
        // And voila, we got the reordered list.

        int n = 0; // Stores the count of nodes in the list.

        ListNode* currNode = head;
        while(currNode != NULL) { // This indicates if we've reached the end of the list or not.
            currNode = currNode -> next;
            n++;
        }

        int lengthOfFirstHalf = n / 2;

        if((n % 2) == 1) {
            lengthOfFirstHalf++; // If number of nodes is odd, then first half should be longer than the second half.
        }

        ListNode* headOfSecondHalf = head;
        ListNode* tailOfFirstHalf = NULL;

        for(int i = 0; i < lengthOfFirstHalf; i++) {
            tailOfFirstHalf = headOfSecondHalf;
            headOfSecondHalf = headOfSecondHalf -> next;
        }

        tailOfFirstHalf -> next = NULL;

        ListNode* headOfReversedSecondHalf = reverseList(headOfSecondHalf);

        mergeLists(head, headOfReversedSecondHalf);
    }
};