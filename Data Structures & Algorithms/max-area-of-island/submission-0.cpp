class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // So, the approach is straightforward, go through the grid.
        // Look at each cell, if it is a land cell - count all the other cells connected to it, that would give us the area of the island that this land cell is a part of, and repeat this for the entire grid.
        // But, this might take a lot of time because one might count an island more than once.
        // For example, if I have a grid [[1, 0], [1, 1]], then as I go through the grid and I see the cell {0, 0} I go through all the connected cells and go through the entire island to count the land cells, after this as I progress further in the grid - I come across the cell {1, 0} I again count the number of cells that this island comprises of but we have already seen this island. Thus, in the above approach there is a risk of counting an island multiple times.
        // Thus, while implementing the above approach we must keep a visited grid that keeps track of land already visited.

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        int ans = 0;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if((!visited[i][j]) && (grid[i][j] == 1)) {
                    queue<pair<int, int>> landCells;
                    landCells.push({i, j});
                    visited[i][j] = true;
                    int area = 0;

                    while(!landCells.empty()) {
                        pair<int, int> currCell = landCells.front();
                        landCells.pop();

                        int row = currCell.first;
                        int col = currCell.second;

                        area++;

                        if((row > 0) && (grid[row - 1][col] == 1) && (!visited[row - 1][col])) {
                            landCells.push({row - 1, col});
                            visited[row - 1][col] = true;
                        }
                        if((col > 0) && (grid[row][col - 1] == 1) && (!visited[row][col - 1])) {
                            landCells.push({row, col - 1});
                            visited[row][col - 1] = true;
                        }
                        if((row < (grid.size() - 1)) && (grid[row + 1][col] == 1) && (!visited[row + 1][col])) {
                            landCells.push({row + 1, col});
                            visited[row + 1][col] = true;
                        }
                        if((col < (grid[0].size() - 1)) && (grid[row][col + 1] == 1) && (!visited[row][col + 1])) {
                            landCells.push({row, col + 1});
                            visited[row][col + 1] = true;
                        }
                    }

                    ans = max(ans, area);
                }
            }

        }
        return ans;
    }
};