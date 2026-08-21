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

    int treeIsBalanced(TreeNode* node) {
        if(node == NULL) {
            return 0;
        }

        int leftHeight = treeIsBalanced(node -> left);
        if(leftHeight == -1) {
            return -1;
        }
        int rightHeight = treeIsBalanced(node -> right);
        if(rightHeight == -1) {
            return -1;
        }

        if(abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        return max(leftHeight, rightHeight) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        // If we have a tree whose left subtree's height is equal to the right subtree's height or the difference between both left subtree and right subtree's height is lesser than 1 only then can we say that the tree beneath it is balanced else it isn't.
        // What if left subtree and right subtree's heights are balanced but the heights beneath aren't what's the answer then?
        // Even if, one of the subtrees is not balanced then that means the whole tree isn't.
        // Thus, for each problem we try to solve it's subproblems if the answer for the subproblems is false then the whole tree isn't balanced tree isn't balanced thus we return false.
        // Else, we get max length of left and right subtrees if they have a difference greater then 1 then we return false else we return true.

        return (treeIsBalanced(root) >= 0) ? true : false;
    }
};