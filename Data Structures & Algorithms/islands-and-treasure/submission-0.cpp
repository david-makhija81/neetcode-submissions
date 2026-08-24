class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // Can the distance of a land cell be greater than the INF value?

        // The approach is kind of simple, we must go through the grid looking for treasure chests, if we find a treasure chest - we should update the nearby cell's shortest distance from that treasure chest?
        // But do we risk visiting one land cell more than once?
        // I guess not, because if we have calculated one land cell's distance from a treasure chest let's say it is 5 but afterwards we find another chest which is just 4 land cells away then in that case it would be beneficial to visit that land cell again because for each land cell it is not just about discovering any treasure close to it whatsoever rather it is about finding the nearest one.
        // Thus, we must revisit a land cell only when we have found a treasure chest nearer from the previous one we found earlier.

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 0) {
                    queue<vector<int>> landCells;
                    landCells.push({i, j});

                    while(!landCells.empty()) {
                        vector<int> currCell = landCells.front();
                        landCells.pop();

                        int row = currCell[0], col = currCell[1];

                        if((row > 0) && (grid[row - 1][col] > (grid[row][col] + 1))) {
                            landCells.push({row - 1, col});
                            grid[row - 1][col] = grid[row][col] + 1;
                        }
                        if((col > 0) && (grid[row][col - 1] > (grid[row][col] + 1))) {
                            landCells.push({row, col - 1});
                            grid[row][col - 1] = grid[row][col] + 1;
                        }
                        if((row < (grid.size() - 1)) && (grid[row + 1][col] > (grid[row][col] + 1))) {
                            landCells.push({row + 1, col});
                            grid[row + 1][col] = grid[row][col] + 1;
                        }
                        if((col < (grid[0].size() - 1)) && (grid[row][col + 1] > (grid[row][col] + 1))) {
                            landCells.push({row, col + 1});
                            grid[row][col + 1] = grid[row][col] + 1;
                        }
                    }
                }
            }
        }
    }
};
