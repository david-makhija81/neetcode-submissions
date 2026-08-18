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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If we have two binary trees where both of them are the same from root to leaf.
        // For example, If we look at 2 trees where the root node in both of them has a value of one and the left Subtree is just one node with value 2 in both the trees and the right subTree in both the trees is also one node but with a value of 3 in both the trees in that case we say that these 2 binary trees are the same.
        // Similarly, if I have to compare 2 binary trees I will first compare the values of both the roots if they do not match, I will simply return false.
        // Else, if they do match then I will compare the left Subtrees of both the roots same condition applies if they do not match I return false, if they do match I move on to the right subTrees compare them and return false if they do not match and return true if they do match.
        // I am return true at this point because I have compared the 2 trees enough, there's nothing more to compare, everything seems fine between the 2 trees - thus return true here.
        
        if((p == NULL) && (q == NULL)) {
            return true; // Both the nodes are equal and there's no left or right subtree to explore, thus we return true here.
        }

        if((p == NULL) || (q == NULL)) {
            return false; // Because one is NULL the other one is not thus they are not equal.
        }

        if((p -> val) != (q -> val)) {
            return false;
        }

        if(!isSameTree(p -> left, q -> left)) {
            return false;
        }

        if(!isSameTree(p -> right, q -> right)) {
            return false;
        }

        return true;
    }
};
