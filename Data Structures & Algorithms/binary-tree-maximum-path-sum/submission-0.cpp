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

    int findMaxPathSum(TreeNode* root, int& ans) {
        if(root == NULL) {
            return 0;
        }

        int leftSum = findMaxPathSum(root -> left, ans);
        if(leftSum < 0) {
            leftSum = 0;
        }
        int rightSum = findMaxPathSum(root -> right, ans);
        if(rightSum < 0) {
            rightSum = 0;
        }

        ans = max((root -> val) + leftSum + rightSum, ans);

        return (max(leftSum, rightSum) + (root -> val));
    }

public:
    int maxPathSum(TreeNode* root) {
        // So, a path is considered starting only from the root or from any node?
        // And the node where it ends must only be the leaf node or it can be any other node?

        // Let's say  I have the binary tree as [1, 2, 3, -1, null] then what would be the maximum path sum?
        // For each node I can easily get the value of the max sum path from this node to a leaf node beneath it.
        // And using this operation maybe I can easily calculate the max sum of a path that includes this node and starts from a leaf node and ends at a leaf node as well.
        // But, there's no compulsion for the path to start from a leaf node and if we still include leaf nodes in the path we might risk deviating from the answer and never getting there. Like in the example shown above - if we do not include the leaf -1 only then can we find the max sum path.
        // Thus we can just not include the sum from the child nodes if it is negative.

        int ans = INT_MIN;

        findMaxPathSum(root, ans);

        return ans;
    }
};