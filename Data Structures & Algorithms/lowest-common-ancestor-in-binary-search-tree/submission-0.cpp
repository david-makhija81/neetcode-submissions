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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) {
            return NULL;
        }

        if((root == p) || (root == q)) {
            return root;
        }

        TreeNode* leftResult = lowestCommonAncestor(root -> left, p, q);
        TreeNode* rightResult = lowestCommonAncestor(root -> right, p, q);

        if((leftResult == NULL) && (rightResult == NULL)) {
            return NULL;
        }

        if(leftResult == NULL) {
            return rightResult;
        }

        if(rightResult == NULL) {
            return leftResult;
        }

        return root;
    }
};
