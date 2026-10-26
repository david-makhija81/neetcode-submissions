/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode partHeadPrev = null;
        ListNode partHead = null;
        ListNode partTail = null;
        ListNode partTailNext = null;

        int position = 1;

        ListNode currNode = head;
        while (currNode != null) {
            if (position == left) {
                partHead = currNode;
            }

            if (position == left - 1) {
                partHeadPrev = currNode;
            }

            if (position == right) {
                partTail = currNode;
            }

            if (position == right + 1) {
                partTailNext = currNode;
            }

            position++;
            currNode = currNode.next;
        }

        partTail.next = null;
        ListNode prev = null;
        currNode = partHead;

        while (currNode != null) {
            ListNode nextNode = currNode.next;

            currNode.next = prev;

            prev = currNode;

            currNode = nextNode;
        }

        if (partTailNext != null) {
            partHead.next = partTailNext;
        }

        if (partHeadPrev != null) {
            partHeadPrev.next = partTail;
        }

        return (head == partHead) ? partTail : head;
    }
}