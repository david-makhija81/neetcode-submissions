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
    TreeNode* invertTree(TreeNode* root) {
        // Can the root be NULL?
        // Is it alright if I do not make another binary tree and do this inversion with the input binary tree itself?
        // So the output binary tree has to be a mirror image of the previous one.

        // An object placed in front of the mirror sees an inversion of itself.
        // And if I look into the mirror the left and right hands get swapped.
        // Thus the easiest way to invert a binary tree is to swap it's left and right Nodes.
        // But if we just do this for the root, the rest of the subtrees remain the same and we fail to invert it entirely.
        // Thus we must swap the left and right nodes for each and every node.

        if(root == NULL) {
            return NULL;
        }

        TreeNode* invertedLeftSubTree = invertTree(root -> left);
        TreeNode* invertedRightSubTree = invertTree(root -> right);

        // Swapping:
        root -> left = invertedRightSubTree;
        root -> right = invertedLeftSubTree;

        return root;
    }
};