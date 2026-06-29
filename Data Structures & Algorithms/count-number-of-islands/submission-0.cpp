class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> newGrid(grid.size(), vector<int>(grid[0].size(), 0));

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    newGrid[i][j] = 1;
                }
            }
        }

        int result = 0;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(newGrid[i][j] != 1) {
                    continue;
                }

                result++;

                queue<pair<int, int>> neighbours;
                neighbours.push({i, j});

                while(!neighbours.empty()) {
                    int rowIdx = neighbours.front().first;
                    int colIdx = neighbours.front().second;

                    neighbours.pop();

                    newGrid[rowIdx][colIdx] = 2;

                    if((rowIdx < (grid.size() - 1)) && (newGrid[rowIdx + 1][colIdx] == 1)) {
                        neighbours.push({rowIdx + 1, colIdx});
                    }
                    if((rowIdx > 0) && (newGrid[rowIdx - 1][colIdx] == 1)) {
                        neighbours.push({rowIdx - 1, colIdx});
                    }
                    if((colIdx < (grid[0].size() - 1)) && (newGrid[rowIdx][colIdx + 1] == 1)) {
                        neighbours.push({rowIdx, colIdx + 1});
                    }
                    if((colIdx > 0) && (newGrid[rowIdx][colIdx - 1] == 1)) {
                        neighbours.push({rowIdx, colIdx - 1});
                    }
                }
            }
        }

        return result;
    }
};