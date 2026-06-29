class Solution {

    bool findWord(vector<vector<char>>& board, int row, int col, string word, vector<vector<bool>>& visited) {
        if(visited[row][col] || (word[0] != board[row][col])) {
            return false;
        }

        if(word.size() == 1) {
            return true;
        }

        visited[row][col] = true;

        if(row > 0) {
            if(findWord(board, row - 1, col, word.substr(1, (word.size() - 1)), visited)) {
                return true;
            }
        }
        if(col > 0) {
            if(findWord(board, row, col - 1, word.substr(1, (word.size() - 1)), visited)) {
                return true;
            }
        }
        if(row < (board.size() - 1)) {
            if(findWord(board, row + 1, col, word.substr(1, (word.size() - 1)), visited)) {
                return true;
            }
        }
        if(col < (board[0].size() - 1)) {
            if(findWord(board, row, col + 1, word.substr(1, (word.size() - 1)), visited)) {
                return true;
            }
        }

        visited[row][col] = false;

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(findWord(board, i, j, word, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
};