class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // An image is nothing but a matrix of different values, thus we just need to rotate that matrix
        // When a matrix is rotated the horizontal rows become vertical columns 
        // Thus, we just need to copy columns into rows, or put another way - copy rows into columns

        // If no extra space was allowed then I would try to use an alternative approach - the approach goes as follows:
        // So we know that the top side of the matrix to be rotated becomes it's left side rotation the right becomes top, bottom becomes right and left becomes bottom.
        // So, we will try to swap these sides in this order only.

        for(int i = 0; (i + i) < matrix.size(); i++) {
            for(int j = 0; j < (matrix.size() - j - 1); j++) {
                int topFaceRow = i, topFaceColumn = j;
                int leftFaceRow = matrix.size() - j - 1, leftFaceColumn = i;
                int bottomFaceRow = matrix.size() - i - 1, bottomFaceColumn = matrix.size() - j - 1;
                int rightFaceRow = j, rightFaceColumn = matrix.size() - i - 1;

                int placeHolder = matrix[topFaceRow][topFaceColumn];

                matrix[topFaceRow][topFaceColumn] = matrix[leftFaceRow][leftFaceColumn];
                matrix[leftFaceRow][leftFaceColumn] = matrix[bottomFaceRow][bottomFaceColumn];
                matrix[bottomFaceRow][bottomFaceColumn] = matrix[rightFaceRow][rightFaceColumn];
                matrix[rightFaceRow][rightFaceColumn] = placeHolder;
            }
        }
    }
};