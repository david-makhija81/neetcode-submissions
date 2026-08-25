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

struct custComp {
    bool operator()(ListNode* a, ListNode* b) {
        return ((b -> val) < (a -> val));
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // I am given an array of linked lists and I have to merge them?
        // And are these linked lists sorted individually like the nodes in them follow a non-descending order in each one of them?
        // The flow of merging sorted lists should look something like:
        // Out of the given lists you choose which element should be the next node of the result linked list.
        // And the result Linked List should be sorted as well.
        // In my opinion the head or the foremost node of any list is best to make comparisons on behalf of the rest of the list as the foremost node at any time would represent the least value in the list.
        // As the result list needs to be sorted in a non-descending order, thus it makes sense to keep choosing the minimum element out of all the nodes at a point and append it to the back of the result list so far.
        // And to choose the minimum out of all the elements we just need to compare the foremost of those lists as we discussed earlier that the foremost nodes of elements give a clear picture in terms of size of a list.

        priority_queue<ListNode*, vector<ListNode*>, custComp> sortedLists;

        for(ListNode* list: lists) {
            if(list != NULL) {
                sortedLists.push(list);
            }
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(!sortedLists.empty()) {
            ListNode* currNode = sortedLists.top();
            sortedLists.pop();

            if((currNode -> next) != NULL) {
                sortedLists.push(currNode -> next);
                currNode -> next = NULL;
            }

            if(tail == NULL) {
                head = currNode;
            } else {
                tail -> next = currNode;
            }

            tail = currNode;
        }

        return head;
    }
};