class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // So, the first integer of a row is greater than the last integer of previous row.
        // Thus, this can be a strong indicator of in which part the target actually exists.
        // If the target is lesser than the first element of a row, then that means the target only exists in the upper part of the grid from that row, and if the target is greater than the last element of the row then the target only exists in the lower part of the grid.
        // This way we can first keep decreasing the search space vertically and figure out the row where this element might be present and then find element in that row with the same strategy.

        int topRow = 0, bottomRow = matrix.size() - 1;
        int targetRow = -1;

        while(topRow <= bottomRow) {
            int midRow = ((bottomRow - topRow) / 2) + topRow;

            if(target < matrix[midRow][0]) {
                bottomRow = midRow - 1;
            } else if(target > matrix[midRow][matrix[0].size() - 1]) {
                topRow = midRow + 1;
            } else {
                targetRow = midRow;
                break;
            }
        }

        if(targetRow == -1) {
            return false;
        }

        int left = 0, right = matrix[0].size() - 1;

        while(left <= right) {
            int mid = ((right - left) / 2) + left;

            if(target == matrix[targetRow][mid]) {
                return true;
            } else if(target > matrix[targetRow][mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
};