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
public:
    int maxDepth(TreeNode* root) {
        // Is it some kind of a self-balancing tree or is it just another binary tree?
        // More importantly, can it be the case that the tree is skewed on one side?

        // Suppose we have a root whose left subtree has a height of 5 and the right subtree has a depth of 7 in that case the height associated with this root seems to be equal to 8.
        // Thus it seems fair to divide this problem into small subproblems i.e. figure out the height left subtree, figure out the height of right subtree - take maximum value out of both of them add one for the root and voila we got the height of this tree.

        if(root == NULL) {
            return 0; // There are nodes, thus the height is 0, it's base case,
        }

        int leftSubtreeHeight = maxDepth(root -> left);
        int rightSubtreeHeight = maxDepth(root -> right);

        return (max(leftSubtreeHeight, rightSubtreeHeight) + 1); // Adding one for the root itself
    }
};