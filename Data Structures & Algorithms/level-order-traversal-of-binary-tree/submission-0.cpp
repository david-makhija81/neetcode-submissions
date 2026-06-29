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

// Intuition:
// 

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) {
            return {};
        }

        queue<TreeNode*> levelNodes;

        levelNodes.push(root);
        levelNodes.push(NULL);

        vector<vector<int>> result;

        vector<int> currLevel;
        while(!levelNodes.empty()) {
            TreeNode* currNode = levelNodes.front();
            levelNodes.pop();

            if(currNode == NULL) {
                result.push_back(currLevel);
                currLevel.clear();
                if(levelNodes.empty()) {
                    break;
                }

                levelNodes.push(NULL);

                currNode = levelNodes.front();
                levelNodes.pop();
            }

            currLevel.push_back(currNode -> val);

            if(currNode -> left) {
                levelNodes.push(currNode -> left);
            }

            if(currNode -> right) {
                levelNodes.push(currNode -> right);
            }
        }

        return result;
    }
};