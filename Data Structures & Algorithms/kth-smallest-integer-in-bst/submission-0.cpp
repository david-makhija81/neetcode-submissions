/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

    int kthElementInBST(TreeNode* root, int k, int& counter) {
        if(root == NULL) {
            return -1;
        }

        int resultFromLeft = kthElementInBST(root -> left, k, counter);

        if(resultFromLeft != -1) {
            return resultFromLeft;
        }

        counter++;
        if(counter == k) {
            return (root -> val);
        }

        int resultFromRight = kthElementInBST(root -> right, k, counter);

        return resultFromRight;
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        // Is k lesser than or equal to the number of elements in the BST?

        // Okay so, the kth smallest value is only the Kth value if all the elements in the BST were put in an array and we returned the kth value the start in that array.
        // And the start of that array would be leftMost element in this BST 
        // So, if we had to calculate the Kth element - it makes sense to just start counting from the leftMost element in the BST and the counting must go in an in order traversal kind of fashion. 
        // wherever that count becaomes equal to k just return that element itself

        int counter = 0; // This shows the position of this node from the leftMost node.

        return kthElementInBST(root, k, counter);
    }
};