class Solution {

    void fillTheBoard(
        int queensPlaced, vector<string>& currBoard, vector<bool>& colTaken, 
        vector<bool>& diag1Taken, vector<bool>& diag2Taken,
        vector<vector<string>>& validBoards, int n, int row
    ) {
        if(row == n) {
            validBoards.push_back(currBoard);
            return;
        }

        
        for(int j = 0; j < n; j++) {
            if((!colTaken[j]) && (!diag1Taken[row - j + n - 1]) && (!diag2Taken[j + row])) {
                colTaken[j] = true;
                diag1Taken[row - j + n - 1] = true;
                diag2Taken[row + j] = true;
                currBoard[row][j] = 'Q';
                fillTheBoard(queensPlaced + 1, currBoard, colTaken, diag1Taken, diag2Taken, validBoards, n, row + 1);
                colTaken[j] = false;
                diag1Taken[row - j + n - 1] = false;
                diag2Taken[row + j] = false;
                currBoard[row][j] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        // So, we have to place the queens in such a way that no queen can attack any other queen.
        // So, a queen attacks straight on both axes left to right, right to left, top to bottom, bottom to top and diagonally as well.
        // We can try placing each queen in such a way such that there's no other queen that shares a row or a column with that queen.
        // Checking, if a row or a column is taken is easy how do determine no 2 queens or facing diagonally

        vector<bool> colTaken(n, false);
        vector<bool> diag1Taken((2 * n) - 1, false);
        vector<bool> diag2Taken((2 * n) - 1, false);

        vector<string> currBoard(n, string(n, '.'));

        vector<vector<string>> validBoards;

        fillTheBoard(0, currBoard, colTaken, diag1Taken, diag2Taken, validBoards, n, 0);

        return validBoards;
    }
};