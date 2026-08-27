class Solution {

    bool isBoundaryCell(int row, int col, vector<vector<char>>& board) {
        return (
            (row == 0) || 
            (col == 0) || 
            (row == (board.size() - 1)) ||
            (col == (board[0].size() - 1))
        );
    }

public:
    void solve(vector<vector<char>>& board) {
        // Are the cells connected diagonally?
        // So, we have to identify regions with cell values 'O' and also identify if they are surrounded by cell values 'X' or not.
        // Are cells connected diagonally or is it just vertically and horizontally.

        // Okay, so going by the definition a surrounded region is something that is completely surrounded by cell values 'X' and shares no boundary with the boundary of the grid.
        // Putting it the other way around, if a region is connected and it does not share a boundary with the grid boundary then the only thing left to bound it are X's as there are only 2 possible values in the grid and if the region does not share a boundary with grid then it is obviously surrounded by X's.
        // Thus, the only thing we need to do is to identify regions whose neither cell shares with the grid and mark them as X.

        vector<vector<bool>> markX(board.size(), vector<bool>(board[0].size(), true));

        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(isBoundaryCell(i, j, board) && (!visited[i][j]) && (board[i][j] == 'O')) {
                    queue<vector<int>> cells;

                    cells.push({i, j});
                    markX[i][j] = false;

                    visited[i][j] = true;

                    while(!cells.empty()) {
                        vector<int> currCell = cells.front();
                        cells.pop();

                        int currRow = currCell[0];
                        int currCol = currCell[1];

                        if(
                            (currRow > 0) && 
                            (!visited[currRow - 1][currCol]) &&
                            (board[currRow - 1][currCol] == 'O')
                        ) {
                            markX[currRow - 1][currCol] = false;
                            cells.push({currRow - 1, currCol});
                            visited[currRow - 1][currCol] = true;
                        }
                        if(
                            (currCol > 0) && 
                            (!visited[currRow][currCol - 1]) &&
                            (board[currRow][currCol - 1] == 'O')
                        ) {
                            markX[currRow][currCol - 1] = false;
                            cells.push({currRow, currCol - 1});
                            visited[currRow][currCol - 1] = true;
                        }
                        if(
                            (currRow < (board.size() - 1)) && 
                            (!visited[currRow + 1][currCol]) &&
                            (board[currRow + 1][currCol] == 'O')
                        ) {
                            markX[currRow + 1][currCol] = false;
                            cells.push({currRow + 1, currCol});
                            visited[currRow + 1][currCol] = true;
                        }
                        if(
                            (currCol < (board[0].size() - 1)) && 
                            (!visited[currRow][currCol + 1]) &&
                            (board[currRow][currCol + 1] == 'O')
                        ) {
                            markX[currRow][currCol + 1] = false;
                            cells.push({currRow, currCol + 1});
                            visited[currRow][currCol + 1] = true;
                        }
                    }
                }
            }
        }

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < (board[0].size()); j++) {
                if(markX[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};