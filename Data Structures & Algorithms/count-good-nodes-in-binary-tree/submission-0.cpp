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

    void numberOfGoodNodes(TreeNode* node, int maxVal, int& num) {
        if(node == NULL) {
            return;
        }

        if((node -> val) >= maxVal) {
            num++;
            maxVal = max(maxVal, node -> val);
        }

        numberOfGoodNodes(
            node -> left,
            maxVal,
            num
        );
        
        numberOfGoodNodes(
            node -> right,
            maxVal,
            num
        );
    }

public:
    int goodNodes(TreeNode* root) {
        // The solution seems fairly simple to me, we should just travel from the root node to the nodes in the tree beneath it and carry with us the maximum value seen so far in the path.
        // If the value at the current node is greater than the maximum then this node is greater then every node in the path from root to this node, thus we mark it as a good node update the maximum and move on to explore other good nodes.

        int ans = 0;

        numberOfGoodNodes(root, (root -> val) - 1, ans);

        return ans;
    }
};