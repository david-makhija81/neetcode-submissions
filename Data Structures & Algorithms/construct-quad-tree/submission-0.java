/*
// Definition for a QuadTree node.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;

    
    public Node() {
        this.val = false;
        this.isLeaf = false;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }
    
    public Node(boolean val, boolean isLeaf) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }
    
    public Node(boolean val, boolean isLeaf, Node topLeft, Node topRight, Node bottomLeft, Node bottomRight) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = topLeft;
        this.topRight = topRight;
        this.bottomLeft = bottomLeft;
        this.bottomRight = bottomRight;
    }
}
*/

class Solution {
    private Node constructTree(int[][] grid, int n_rows, int n_cols, int st_row, int st_col) {
        Node currNode = new Node();

        if (n_rows == 1) {
            currNode.val = (grid[st_row][st_col] == 1) ? true : false;
            currNode.isLeaf = true;
            return currNode;
        }

        Node topLeft = constructTree(grid, n_rows / 2, n_cols / 2, st_row, st_col);
        Node topRight = constructTree(grid, n_rows / 2, n_cols / 2, st_row, st_col + (n_cols / 2));
        Node bottomLeft = constructTree(grid, n_rows / 2, n_cols / 2, st_row + (n_rows / 2), st_col);
        Node bottomRight = constructTree(grid, n_rows / 2, n_cols / 2, st_row + (n_rows / 2), st_col + (n_cols / 2));

        currNode.val = (topLeft.val || topRight.val || bottomLeft.val || bottomRight.val);

        if (!(currNode.val) || ((topLeft.val && topRight.val && bottomLeft.val && bottomRight.val) && (topLeft.isLeaf && topRight.isLeaf && bottomLeft.isLeaf && bottomRight.isLeaf))) {
            currNode.isLeaf = true;
        } else {
            currNode.topLeft = topLeft;
            currNode.topRight = topRight;
            currNode.bottomLeft = bottomLeft;
            currNode.bottomRight = bottomRight;
        }

        return currNode;
    }

    public Node construct(int[][] grid) {
        return constructTree(grid, grid.length, grid[0].length, 0, 0);
    }
}