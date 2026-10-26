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

    private void fillInorderTraversal(TreeNode node, ArrayList<Integer> inorder) {
        if (node == null) {
            return;
        }

        fillInorderTraversal(node.left, inorder);
        inorder.add(node.val);
        fillInorderTraversal(node.right, inorder);
    }

    public List<Integer> inorderTraversal(TreeNode root) {
        ArrayList<Integer> inorder = new ArrayList<>();

        fillInorderTraversal(root, inorder);

        return inorder;
    }
}