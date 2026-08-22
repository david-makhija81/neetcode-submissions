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
    vector<int> rightSideView(TreeNode* root) {
        // So, we have a binary tree and we have to figure out What nodes are visible if we look at this binary tree from the right side.
        // At first, one might think that for the right side view one might keep making a list of right nodes recursively until we encounter a NULL element and this must serve as our answer - this works in some cases but it fails in other cases.
        // Like if the left subtree of a root node is taller then the right subtree then after a certain height the left subtree is also visible from the right side - thus the above approach fails altogether.
        // Thus, we must see this problem from a different angle - let's say we have a binary tree and we divide it into levels of nodes.
        // In each level the last node has no node to the right of it, thus there is no node blocking it's view from the right and so, this is the node visible from right side.
        // Thus, we will traverse the tree one level after another and we store the node of every level to our ans that is visible from the right side.

        queue<TreeNode*> levels;
        vector<int> ans;

        if(root == NULL) {
            return ans;
        }

        levels.push(root);
        levels.push(NULL);

        while(!levels.empty()) {
            if(levels.front() == NULL) {
                levels.pop();

                if(levels.empty()) {
                    break;
                }

                levels.push(NULL);
            }

            TreeNode* currNode = levels.front();
            levels.pop();

            if(levels.front() == NULL) {
                ans.push_back(currNode -> val);
            }

            if((currNode -> left) != NULL) {
                levels.push(currNode -> left);
            }
            if((currNode -> right) != NULL) {
                levels.push(currNode -> right);
            }
        }

        return ans;
    }
};