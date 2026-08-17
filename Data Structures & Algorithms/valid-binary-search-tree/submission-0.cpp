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

    pair<bool, pair<int, int>> helper(TreeNode* root) {
        if((root -> left == NULL) && (root -> right == NULL)) {
            return {true, {root -> val, root -> val}};
        }

        if(root -> left == NULL) {
            pair<bool, pair<int, int>> rightAns = helper(root -> right);
            if(rightAns.first != true) {
                return {false, {-1, -1}};
            }

            if((root -> val) >= (rightAns.second.first)) {
                return {false, {-1, -1}};
            }

            return {true, {root -> val, rightAns.second.second}};
        }

        if(root -> right == NULL) {
            pair<bool, pair<int, int>> leftAns = helper(root -> left);
            if(leftAns.first != true) {
                return {false, {-1, -1}};
            }

            if((root -> val) <= (leftAns.second.second)) {
                return {false, {-1, -1}};
            }

            return {true, {leftAns.second.first, root -> val}};
        }

        pair<bool, pair<int, int>> rightAns = helper(root -> right);
        if(rightAns.first != true) {
            return {false, {-1, -1}};
        }

        if((root -> val) >= (rightAns.second.first)) {
            return {false, {-1, -1}};
        }

        pair<bool, pair<int, int>> leftAns = helper(root -> left);
        if(leftAns.first != true) {
            return {false, {-1, -1}};
        }

        if((root -> val) <= (leftAns.second.second)) {
            return {false, {-1, -1}};
        }

        return {true, {leftAns.second.first, rightAns.second.second}};
    }

public:
    bool isValidBST(TreeNode* root) {
        // I think in order to validate a binary search tree - one just needs to compare the immediate nodes, if there is any node which is lesser than or equal to it's immediate left child or is greater than or equal to it's immediate right child then it is not a valid BST.
        // But how does a comparison with root node of left subtree guarantee that every node in that left subtree is lesser than the current node.
        // It doesn't.. That's why to guarantee this we will take the maximum element from the left subtree compare it with the root if it isn't lesser than root than we return false and for the right node we take the minimum out of it and compare with root.

        if(root == NULL) {
            return true;
        }

        return helper(root).first;
    }
};
