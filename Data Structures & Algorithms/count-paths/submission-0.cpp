class Solution {
public:
    int uniquePaths(int m, int n) {
        // Does the grid contain any obstacles?
        // What are the directions the Robot can move in?

        // If I want to figure out the number of ways a random cell in the grid can be reached in the grid - 
        // I would first figure out the neighbouring cells adjacent to that random cell from where I can reach this cell.
        // Suppose there is a cell 'b' which can be reached after just one step from cell 'a' and cell 'c' then one can say that: 
        // numberOfWaysToReach('b') = numberOfWaysToReach('a') + numberOfWaysToReach('c')
        // Because a & c are the only way to b and then any path that leads to a or c would automatically lead to b.

        vector<vector<int>> grid(m, vector<int>(n, 0)); // Initially We assume no cell can be reached.

        grid[0][0] = 1; // The robot already stands at the cell 0, 0 thus there's one way robot can reach there.

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // Robot can only move in the down or right direction, thus are only 2 directions a cell can expect the robot - A cell can expect the robot either from above or from the left direction and initially we assume there is no way to reach either from above or from the right side.
                // I am assuming down direction in the direction of increasing row number and right direction in the direction of increasing column.
                int waysFromAbove = 0, waysFromLeft = 0;

                if(i > 0) { // There does exist a cell in the upward direction.
                    waysFromAbove = grid[i - 1][j];
                }
                if(j > 0) { // There does exist a cell in the left direction.
                    waysFromLeft = grid[i][j - 1];
                }

                if((waysFromAbove + waysFromLeft) > 0) {
                    grid[i][j] = waysFromAbove + waysFromLeft;
                }
            }

        }
        
        return grid[m - 1][n - 1]; // Number of ways to reach the cell (m - 1, n - 1);
    }
};