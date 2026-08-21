class Solution {

    bool checkForRepititionsInRows(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++) {
            set<char> currRowChars;
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] != '.') {
                    if(currRowChars.find(board[i][j]) != currRowChars.end()) {
                        // cout << "Repeated in " << i << " row" << endl;
                        return true;
                    }

                    currRowChars.insert(board[i][j]);
                }
            }
        }

        return false;
    }
    bool checkForRepititionsInCols(vector<vector<char>>& board) {
        for(int j = 0; j < board[0].size(); j++) {
            set<char> currColChars;
            for(int i = 0; i < board.size(); i++) {
                if(board[i][j] != '.') {
                    if(currColChars.find(board[i][j]) != currColChars.end()) {
                        // cout << "Repeated in " << j << " column" << endl;
                        return true;
                    }

                    currColChars.insert(board[i][j]);
                }
            }
        }

        return false;
    }
    bool checkForRepititionsInGrids(vector<vector<char>>& board) {
        int i = 0;
        while(i < 9) {
            int j = 0;
            while(j < 9) {
                set<char> currGridChars;
                for(int row = i; row < (i + 3); row++) {
                    for(int col = j; col < (j + 3); col++) {
                        if(board[row][col] != '.') {
                            if(currGridChars.find(board[row][col]) != currGridChars.end()) {
                                // cout << "Repeated in " << i << ", " << j << " grid" << endl;
                                return true;
                            }
                            currGridChars.insert(board[row][col]);
                        }
                    }
                }
                j += 3;
            }
            i += 3;
        }

        return false;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // So, we only have to look for repitition in Rows, Columns and 9 [3 x 3] matrices as well.
        // If repitition does exist any of these 3, then we return false because the sudoku isn't valid else we return true because the sudoku board is valid.
        
        if(checkForRepititionsInRows(board)) {
            return false;
        }

        if(checkForRepititionsInCols(board)) {
            return false;
        }

        if(checkForRepititionsInGrids(board)) {
            return false;
        }

        return true;
    }
};