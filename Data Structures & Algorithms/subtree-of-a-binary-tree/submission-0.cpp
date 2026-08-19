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

    bool treesMatch(TreeNode* node1, TreeNode* node2) {
        if((node1 == NULL) && (node2 == NULL)) {
            return true;
        }

        if((node1 == NULL) || (node2 == NULL)) {
            return false;
        }

        if((node1 -> val) != (node2 -> val)) {
            return false;
        }

        if(!treesMatch(node1 -> left, node2 -> left)) {
            return false;
        }

        if(!treesMatch(node1 -> right, node2 -> right)) {
            return false;
        }

        return true;
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // Does the principal tree have duplicate values in its nodes?
        // Do we need to match the nodes themselves or just the node values?

        // So we have a root and subRoot right? and we need to figure out if the subRoot is actually a subTree of the principal tree.
        // We can maybe keep on going through the tree and compare the current node with the subRoot itself, if they match we figure out if the left subTrees  and right subTrees match with each other or not just like this we keep on dividing it into subproblems until either we find a mismatch or we have gone through the entire subTrees and found no mismatch.

        if((root == NULL) && (subRoot == NULL)) {
            return true;
        }

        if((root == NULL) && (subRoot != NULL)) {
            return false;
        }

        if((root != NULL) && (subRoot == NULL)) {
            return true;
        }

        if((root -> val) == (subRoot -> val)) {
            if(treesMatch(root, subRoot)) {
                return true;
            }
        }

        if(isSubtree(root -> left, subRoot)) {
            return true;
        }

        if(isSubtree(root -> right, subRoot)) {
            return true;
        }

        return false;
    }
};