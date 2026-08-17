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
        // Are we given the number of nodes in the list?
        // n is not greater than the number of nodes in the list, right?
        
        // We can count the number of nodes in the list let's say the number of nodes is m.
        // That means we have to remove the (m - n + 1)th node from the head of the list.

        ListNode* currNode = head;
        int nodeCount = 0;

        while(currNode != NULL) { // Until we reach the end of the list.
            currNode = currNode -> next;
            nodeCount++;
        }

        int removeNodePos = nodeCount - n + 1;

        ListNode* nodePrevFromDeleteNode = NULL; // Placeholder find out the node that points to the node that we have to delete.

        ListNode* nodeToBeRemoved = head;

        for(int i = 0; i < (removeNodePos - 1); i++) {
            nodePrevFromDeleteNode = nodeToBeRemoved;
            nodeToBeRemoved = nodeToBeRemoved -> next;
        }

        if(nodePrevFromDeleteNode == NULL) { // It means it's the first node that needs to be deleted.
            head = nodeToBeRemoved -> next;
        } else {
            nodePrevFromDeleteNode -> next = nodeToBeRemoved -> next;
        }

        nodeToBeRemoved -> next = NULL;
        delete nodeToBeRemoved;

        return head;
    }
};