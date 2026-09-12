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
    TreeNode* deleteNode(TreeNode* root, int key) {
        //  so by the definition of a BST, a BST is a tree where in the left subtery of a node, are all lesser than that node.
        //  and the nodes in the right set tree of that node are all greater than that node. 
        //  and the task at our hands is to delete a node from, delete an, delete a given node from a BST so that The order of that BSD or the properties of that BSD remain intact. 
        //  so we are given an integer that we have to identify where that lies and delete that mode, right? 
        // are there multiple like are there duplicate values in this BST?
        //  any child of a given node in the BST is obviously either in the right sub part or the lift sub part, and every node in the right sub part of a node is greater than that node, not equal to, and same applies to the left node.

        // I mean, vice versa, that is every node in the left sub tree is are all lesser than this node. 

        // a normal deletion would have been really easy but the catch here is to preserve the order of the new tree that we will get after this deletion.

        if(root == NULL) {
            return NULL;
        }

        if((root -> val) < key) {
            root -> right = deleteNode(root -> right, key);
            return root;
        }

        if((root -> val) > key) {
            root -> left = deleteNode(root -> left, key);
            return root;
        }

        TreeNode* left = root -> left;
        root -> left = NULL;
        TreeNode* right = root -> right;
        root -> right = NULL;

        delete root;

        if(left == NULL) {
            return right;
        }
        if(right == NULL) {
            return left;
        }

        root = left;

        while((left -> right) != NULL) {
            left = left -> right;
        }

        left -> right = right;

        return root;
    }
};