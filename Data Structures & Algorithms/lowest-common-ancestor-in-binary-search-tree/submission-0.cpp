/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Is it a Binary Tree?

// There are only 3 kinds of cases I can imagine with respect to these 2 nodes p & q.
// First one is [root] -- ... -- [p] -- ... -- [q] ||| p is the Lowest Common Ancestor in this case.
// 2nd one is [root] -- ... -- [q] -- ... -- [p] ||| q is the Lowest Common Ancestor in this case.
// 3rd one is [root] -- ... -- [node] -- ... -- [q] ||| node is the LCA in this case.
//                                |
//                               ...
//                                |
//                               [p]
// Seeing this, one strategy comes to my mind and that is to first check if the current node is equal to p or q if it is then we return this node as it is because if it is 1st or 2nd case then this is the LCA only, and if it is the 3rd case then it will only help in finding the LCA further only.
// Else we search for the LCA in both left subtree and right subtree if we get p from one subtree and q from another then this node is the LCA it is the 3rd case.
// Else if it gets a non-null from either of the subtrees then it could be any of the 3 cases thus we just return the one non-null node ignoring the other null node, because it will only help find the LCA further up in the tree.
// Else if we get NULL from both the subtrees then we return NULL itself because apparently this node does not fall in the path of LCA.
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) {
            return NULL;
        }

        if((root == p) || (root == q)) {
            return root;
        }

        TreeNode* leftSubTreeResult = lowestCommonAncestor(root -> left, p, q);
        TreeNode* rightSubTreeResult = lowestCommonAncestor(root -> right, p, q);

        if(
            (leftSubTreeResult != NULL) &&
            (rightSubTreeResult != NULL)
        ) {
            return root; // It points to the 3rd case thus current node is the LCA
        } else if(
            (leftSubTreeResult != NULL) ||
            (rightSubTreeResult != NULL)
        ) {
            return (leftSubTreeResult == NULL) ? 
                    rightSubTreeResult :
                    leftSubTreeResult;
        }

        return NULL; // This node does not fall in the path from root to LCA
    }
};