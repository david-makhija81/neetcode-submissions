/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

    private void fillPreorder(TreeNode root, ArrayList<Integer> preorder) {
        if (root == null) {
            return;
        }

        preorder.add(root.val);
        fillPreorder(root.left, preorder);
        fillPreorder(root.right, preorder);
    }

    public List<Integer> preorderTraversal(TreeNode root) {
        ArrayList<Integer> preorder = new ArrayList<>();

        fillPreorder(root, preorder);

        return preorder;
    }
}