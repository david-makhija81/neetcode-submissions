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

    TreeNode* buildTreeFromTraversal(vector<int>& preorder, int poStart, int poEnd,
                        vector<int>& inorder, int ioStart, int ioEnd) {
        if(poStart == poEnd) {
            return NULL;
        }

        int rootVal = preorder[poStart];

        TreeNode* root = new TreeNode(rootVal);

        int leftSubtreePoStart = poStart + 1;
        int leftSubtreePoEnd = poStart + 1;
        int leftSubtreeIoStart = ioStart;
        int leftSubtreeIoEnd = ioStart;

        while(inorder[leftSubtreeIoEnd] != rootVal) {
            leftSubtreeIoEnd++;
            leftSubtreePoEnd++;
        }

        root -> left = buildTreeFromTraversal(preorder, leftSubtreePoStart, leftSubtreePoEnd, inorder, leftSubtreeIoStart, leftSubtreeIoEnd);

        int rightSubtreePoStart = poEnd;
        int rightSubtreePoEnd = poEnd;
        int rightSubtreeIoStart = ioEnd;
        int rightSubtreeIoEnd = ioEnd;

        while(inorder[rightSubtreeIoStart - 1] != rootVal) {
            rightSubtreeIoStart--;
            rightSubtreePoStart--;
        }

        root -> right = buildTreeFromTraversal(preorder, rightSubtreePoStart, rightSubtreePoEnd, inorder, rightSubtreeIoStart, rightSubtreeIoEnd);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Are all the node values unique?

        // If I knew only one traversal out of preorder and inorder it would have been difficult for me to reconstruct a binary tree out of it.
        // But having both the traversal helps me spot exactly where the left and right subtree start and end in the traversal and where the root is exactly.
        // The root node comes before both the left and right subTrees thus the first value in preorder traversal is the root node.
        // And this root node can further help us figure out where the left subtree ends - the left sub tree ends just before the root in the in-order traversal.
        // And the right subtree starts just after the root in the in-order traversal.

        return buildTreeFromTraversal(preorder, 0, preorder.size()/* bounds of the traversal*/, inorder, 0, inorder.size());
    }
};