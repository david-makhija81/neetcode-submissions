class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // So, I have to look for zeroes in the matrix.
        // And wherever zeroes occur, I need to set the entire corresponding row and column to zeroes.
        // At first sight it seems easy, if we go about the approach discussed above, we'll definitely fall into some pitfalls.
        // For example, take the grid [[0, 1], [1, 1]],
        // I start looking for zeroes in the grid and I find one at position (0, 0) I make the 0th row and 0th column equal to 0.
        // Now, the matrix looks something like [[0, 0], [0, 1]] and then we look at the next position (0, 1) we find 0 there right now but earlier it was 1 despite this our algorithm will make it's row and column 0
        // And now the grid looks like this [[0, 0], [0, 0]] rather it should have looked like [[0, 0], [0, 1]]
        // This approach fails because we only need to transform the rows and columns of the cells which were zero before the transformation.
        // There must be a way to distinguish between 0s set by this function and the cells that were already 0.
        // We can maybe put a special placeholder at every cell which wasn't a 0 earlier but was set to 0
        // And after traversing the entire array and making these changes we can replace that special placeholder with 0 itself.

        set<int> zeroRows;
        set<int> zeroCols;

        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    zeroRows.insert(i);
                    zeroCols.insert(j);
                }
            }
        }

        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if((zeroRows.find(i) != zeroRows.end()) || (zeroCols.find(j) != zeroCols.end())) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};