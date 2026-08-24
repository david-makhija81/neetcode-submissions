/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    // So, the nodes only contain numbers, right?
    // Maybe, for a binary tree I can serialize it in one of the ways it is traversed - maybe inorder or post order or pre-order or whatever.
    // And to separate a number from another - I can use a delimiter like a comma.
    // And because the node values only contain numbers - thus, I can easily use a comma as a delimiter.
    // But, even if I use an inorder traversal I can not make a tree out of it right away because there's no way of recognizing where the left subtree of a node starts and ends and likewise for the right subtree.
    // Thus, keeping this in mind I'll also include a preorder traversal in the serialized string.
    // This way I can easily reconstruct the tree.
    // Encodes a tree to a single string.
    // But this approach only works for Trees that contain duplicate node values as in this approach we require identifying nodes by their values and if Values aren't unique then how do I differentiate one value from another?
    // Another approach that might work here is to put a level order traversal and as it is a binary tree we know how many elements to look for at a level thus there's no need to put a delimiter between levels as well.
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "N";
        string res;
        queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            TreeNode* node = queue.front();
            queue.pop();
            if (!node) {
                res += "N,";
            } else {
                res += to_string(node->val) + ",";
                queue.push(node->left);
                queue.push(node->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string val;
        getline(ss, val, ',');
        if (val == "N") return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> queue;
        queue.push(root);

        while (getline(ss, val, ',')) {
            TreeNode* node = queue.front();
            queue.pop();
            if (val != "N") {
                node->left = new TreeNode(stoi(val));
                queue.push(node->left);
            }
            getline(ss, val, ',');
            if (val != "N") {
                node->right = new TreeNode(stoi(val));
                queue.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));