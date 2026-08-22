/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // So, we have a linked list which works the usual way as a linked list should i.e. it has next pointers - it starts from the head node goes all the way up to the tail and then the tail's next points at NULL.
        // A nuance that this list has is that each node has a random pointer as well and the random pointer can point to any node in the list.
        // And we have to make a deep copy of this list such that the the deep copy of each node points to the same respective node as it does in the actual list.
        // First we must choose the pointers out of random and next along whom I must move in order to traverse all the list nodes, make each node's copy and do not get stuck in cycles. And we choose the next because if we go along the next pointers we surely traverse the entire list and end up at a NULL node afterwards thus avoiding any cycles.
        // While making copies we must also take care of making the random pointer of each node point to the respective node in the copied list, this is kind of tricky because the random node that we need to point to might be way ahead from the current node and it might mot have yet even been created, or it could be the case that the node has already been created but I might have to traverse the copied list again and again just to find that random node for each node.
        // To avoid these pitfalls, we can keep a map maybe to map a node's value to their respective copied node.
        // Because, the node's value remains the same but the node addresses change.
        // We first copy the entire linked list except it's random pointers. And we keep mapping that node's value to that node's copied node.
        // After constructing the entire list we go through the actual list for mimicking the random links from the actual list to the copied list with the help of the map we just created earlier.
        // The above approach works only when the node values are distinct.
        // As the node values are not distinct thus, let's implement the brute approach only.

        Node* copyHead = NULL;
        Node* copyTail = NULL;
        Node* currNode = head;

        unordered_map<Node*, Node*> copyNodes;

        while(currNode != NULL) {
            Node* copyNode = new Node(currNode -> val);

            if(copyTail == NULL) {
                copyHead = copyNode;
                copyTail = copyNode;
            } else {
                copyTail -> next = copyNode;
                copyTail = copyNode;
            }

            copyNodes.insert({currNode, copyNode});

            currNode = currNode -> next;
        }

        currNode = head;
        Node* currCopyNode = copyHead;

        while(currNode != NULL) {
            if((currNode -> random) != NULL) {
                currCopyNode -> random = copyNodes[currNode -> random];
            }

            currNode = currNode -> next;
            currCopyNode = currCopyNode -> next;
        }

        return copyHead;
    }
};