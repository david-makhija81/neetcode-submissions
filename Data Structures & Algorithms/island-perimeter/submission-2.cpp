class Solution {

    bool isBoundary(int row, int col, vector<vector<int>>& grid) {
        if((row < 0) || (col < 0) || (row == grid.size()) || (col == grid[0].size())) {
            return true;
        }

        return (grid[row][col] == 0) ? true : false;
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // Can one grid cell be connected to another grid cell only via horizontal and vertical walls, or is it by diagonally as well?
        // There's only one connected component, huh, one complete connected component of ones amidst the sea of zeros, as there is only one island in this grid.
        // It is also given that there are no leaks, that means there are no cycle formed by ones, cells that contain the value of one.
        // So we have to figure out the perimeter of the entire island.
        // in my understanding, perimeter is formed by land cells that are connected to the C land cells or cells with value, one connected with cells with value, zero.
        // and there is an edge case as well, where the cell one if a cell containing the value of one is connected to the border of the or edge of the grid, then also it counts as perimeter.
        // I suppose we have just, we just need to count the, for every land cell, we just need to count the number of sides it shares with the sea, we sum them up, and I guess we have our answer ready after that.

        int perimeter = 0;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    perimeter += ((isBoundary(i + 1, j, grid)) ? 1 : 0);
                    perimeter += ((isBoundary(i, j + 1, grid)) ? 1 : 0);
                    perimeter += ((isBoundary(i - 1, j, grid)) ? 1 : 0);
                    perimeter += ((isBoundary(i, j - 1, grid)) ? 1 : 0);
                }
            }
        }

        return perimeter;
    }
};