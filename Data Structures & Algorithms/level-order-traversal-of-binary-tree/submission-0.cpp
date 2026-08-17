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
    vector<vector<int>> levelOrder(TreeNode* root) {

        // We can do maybe a BFS because it goes through the tree level by level.

        vector<vector<int>> ans;

        if(root == NULL) {
            return ans; // The algorithm I am thinking of won't work if the root is NULL.
        }

        queue<TreeNode*> nodes; // A medium to traverse through the nodes of the tree in a level order.
        nodes.push(root);
        nodes.push(NULL); // This works like a marker that the level ends here.
        vector<int> firstLevel; // Nodes in the first level would be pushed in this vector.
        ans.push_back(firstLevel);

        while(!nodes.empty()) {
            if(nodes.front() == NULL) { // level ending marker.
                nodes.pop();
                if(nodes.empty()) { // if there are no more nodes to go through in the queue
                    break;
                }

                vector<int> nextLevel;
                ans.push_back(nextLevel);

                nodes.push(NULL); // We have stored all the nodes for this level in the queue no more nodes remaining in this level, thus the marker to indicate that.
            }

            TreeNode* currNode = nodes.front();
            nodes.pop();

            ans.back().push_back(currNode -> val);

            if((currNode -> left) != NULL) {
                nodes.push(currNode -> left);
            }
            if((currNode -> right) != NULL) {
                nodes.push(currNode -> right);
            }
        }

        return ans;
    }
};