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
        if((list1 == NULL) || (list2 == NULL)) {
            return (list1 == NULL) ? list2 : list1;
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while((list1 != NULL) && (list2 != NULL)) {
            ListNode* nextNode = NULL;

            if((list1 -> val) <= (list2 -> val)) {
                nextNode = list1;
                list1 = list1 -> next;
            } else {
                nextNode = list2;
                list2 = list2 -> next;
            }

            if(tail == NULL) {
                head = nextNode;
                tail = nextNode;
            } else {
                tail -> next = nextNode;
                tail = tail -> next;
            }
        }

        if(list1 != NULL) {
            tail -> next = list1;
        } else {
            tail -> next = list2;
        }

        return head;
    }
};