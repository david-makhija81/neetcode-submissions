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

    int determineDiameterOfBinaryTree(TreeNode* root, int& maxPath) {
        if(root == NULL) {
            return 0;
        }

        int leftHeight = determineDiameterOfBinaryTree(root -> left, maxPath);
        int rightHeight = determineDiameterOfBinaryTree(root -> right, maxPath);

        int maxPathThroughThisNode = leftHeight + rightHeight + 1;

        maxPath = max(maxPath, maxPathThroughThisNode);

        return (max(leftHeight, rightHeight) + 1);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        // Let's say we have a root p which comes beneath the actual root node but has it's own subtree beneath it.
        // The maximum path starting from node p which is inside p's own subtree must only be the path from p all the way up to a leaf node in the p subtree.
        // Thus, if a maximum path exists in p subtree and it passes through p then it is obvious it must start from and end at a leafnode as well.
        // So, the intuition is simple - we just get the max height from left subtree and right subtree their sum increased by 1 denotes the length of maximum path that goes through this node, we calculate it and update the max path length.

        int maxPath = 0;

        determineDiameterOfBinaryTree(root, maxPath);

        return maxPath - 1;
    }
};