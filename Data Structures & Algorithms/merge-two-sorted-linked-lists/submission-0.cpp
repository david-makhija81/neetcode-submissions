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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Are the two lists already sorted?

        if((list1 == NULL) && (list2 == NULL)) {
            return NULL;
        }

        if(list1 == NULL) {
            return list2;
        }

        if(list2 == NULL) {
            return list1;
        }

        // If I have two lists like as follows:
        // [1] -> [3]
        // [2] -> [4]
        // One pointer would have to track first list's current pointer and another pointer to track the second one's current pointer.
        // We keep on comparing these current pointers in order to figure out which one goes next to the other one.
        // For example: The current pointer for the first list is at [1] and the current pointer for the second list is at [2] we compare both of them and decide in order for resulting list to be sorted [2] has to be next to [1] thus we place the nodes like [1] -> [2] and move the current pointers to [2] & [3] and move on.

        ListNode* headOfNewList = NULL;

        if((list1 -> val) <= (list2 -> val)) {
            headOfNewList = list1;
            list1 = list1 -> next;
        } else {
            headOfNewList = list2;
            list2 = list2 -> next;
        }

        ListNode* tailOfNewList = headOfNewList; // At this point the list is only 1 node long.

        while((list1 != NULL) && (list2 != NULL)) {
            if((list1 -> val) <= (list2 -> val)) {
                tailOfNewList -> next = list1;
                list1 = list1 -> next;
            } else {
                tailOfNewList -> next = list2;
                list2 = list2 -> next;
            }

            tailOfNewList = tailOfNewList -> next;
        }

        if(list1 != NULL) {
            tailOfNewList -> next = list1;
        }

        if(list2 != NULL) {
            tailOfNewList -> next = list2;
        }

        return headOfNewList;
    }
};