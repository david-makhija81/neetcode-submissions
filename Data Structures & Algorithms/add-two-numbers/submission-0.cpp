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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // We can apply the general addition algorithm that is to add 2 digits on the same place, put one's place digit from that digit sum at the place in the result sum, and carry forward the 10's place digit from digit sum and add it in the next digit sum.
        // So, the only change we'll witness here is that the digits are replaced by nodes and the head node signifies the one's place digit and the successive next nodes represent successive place digits.
        // The algorithm I am thinking of goes something like start from the head node of both the linked lists traverse until either one of them reaches a null value.
        // For each node calculate the digit sum along with carry store that numbers one's place digit into a new node and add that node to the result linked list and put the ten's place digit in that sum into carry and move to the next node.
        // If, one list finishes out of values and the other one still has nodes left then keep adding carry to those nodes until carry becomes 0 at that add the rest of the nodes as it is to the result list and if all the nodes have finished and there is a carry left then make a new node store carry in it and add that node to the result linked list.

        ListNode* head = NULL;
        ListNode* tail = NULL;
        int carry = 0;

        while((l1 != NULL) && (l2 != NULL)) {
            int digitSum = (l1 -> val) + (l2 -> val) + carry;

            int digit = (digitSum % 10);
            carry = (digitSum / 10);

            ListNode* currNode = new ListNode(digit);

            if(tail == NULL) {
                head = currNode;
                tail = currNode;
            } else {
                tail -> next = currNode;
                tail = currNode;
            }

            l1 = l1 -> next;
            l2 = l2 -> next;
        }

        if(l1 == NULL) {
            while(l2 != NULL) {
                int digitSum = (l2 -> val) + carry;

                int digit = (digitSum % 10);
                carry = (digitSum / 10);

                ListNode* currNode = new ListNode(digit);

                if(tail == NULL) {
                    head = currNode;
                    tail = currNode;
                } else {
                    tail -> next = currNode;
                    tail = currNode;
                }

                l2 = l2 -> next;
            }
        } else if(l2 == NULL) {
            while(l1 != NULL) {
                int digitSum = (l1 -> val) + carry;

                int digit = (digitSum % 10);
                carry = (digitSum / 10);

                ListNode* currNode = new ListNode(digit);

                if(tail == NULL) {
                    head = currNode;
                    tail = currNode;
                } else {
                    tail -> next = currNode;
                    tail = currNode;
                }

                l1 = l1 -> next;
            }
        }

        if(carry > 0) {
            int digit = carry;

            ListNode* currNode = new ListNode(digit);

            if(tail == NULL) {
                head = currNode;
                tail = currNode;
            } else {
                tail -> next = currNode;
                tail = currNode;
            }
        }

        return head;
    }
};