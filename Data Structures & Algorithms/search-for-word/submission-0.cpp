class Solution {

    bool findTheWord(string word, int row, int col, vector<vector<char>>& board, vector<vector<bool>>& visited) {
        if(word == "") {
            return true; // We matched each and every character in the word with a character in the grid in the exact sequence.
        }

        if((row > 0) && (board[row - 1][col] == word[0]) && (!visited[row - 1][col])) {
            visited[row - 1][col] = true;
            if(findTheWord(word.substr(1, word.size() - 1), row - 1, col, board, visited)) {
                return true;
            }
            visited[row - 1][col] = false;
        }
        if((col > 0) && (board[row][col - 1] == word[0]) && (!visited[row][col - 1])) {
            visited[row][col - 1] = true;
            if(findTheWord(word.substr(1, word.size() - 1), row, col - 1, board, visited)) {
                return true;
            }
            visited[row][col - 1] = false;
        }
        if((row < (board.size() - 1)) && (board[row + 1][col] == word[0]) && (!visited[row + 1][col])) {
            visited[row + 1][col] = true;
            if(findTheWord(word.substr(1, word.size() - 1), row + 1, col, board, visited)) {
                return true;
            }
            visited[row + 1][col] = false;
        }
        if((col < (board[0].size() - 1)) && (board[row][col + 1] == word[0]) && 
        (!visited[row][col + 1])) {
            visited[row][col + 1] = true;
            if(findTheWord(word.substr(1, word.size() - 1), row, col + 1, board, visited)) {
                return true;
            }
            visited[row][col + 1] = false;
        }

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        // Does the character sequence for the word need to go in one direction only like across (left - right) or down (top - bottom)?
        // More appropriately put, can the next character be from any direction?

        // I am thinking of a solution where I go through the grid to see if any characters match the first character of th word we have to look for.
        // If the first character of the word matches with any of the characters, then we go looking for matching consecutive characters in neighbouring cells of the grid like a robot in a maze.
        // We keep marking the cells as visited as we go looking for a word so as to avoid going in a cycles.

        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == word[0]) {
                    visited[i][j] = true;
                    // First character matched search for the rest of the word.
                    if(findTheWord(word.substr(1, word.size() - 1), i, j, board, visited)) {
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        }

        return false; // Word could not be find in the entire grid.
    }
};