class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        // we can only go in the downwards direction or in the left direction, right? Or in the right direction, right? And the The goal is in the bottom right most cell, right?
        // as there are obstacles in the way, can we jump over an obstacle?
        // The robot moves one cell at a time and the robot moves one cell at a time and one step at a time and what does one step count? Does it count 2 sales? Does it count one cell, how many sales?

        // so I have to figure out the number of ways I can reach from the from the top left corner to the bottom right corner of the grid.
        // standing at a cell, how do I reach this cell? That is the question, we should ask like how can one reach a particular cell, let's say we talk about the cell, one, two in the grid. How does the robot? I mean, how would have the robot if the robot is standing there?

        // How would the robot have reached there? That is the question.

        // so to reach a particular cell, there are only two ways as we can only take steps to the right or to the bottom, to the right or downwards. That's why there are only 2 ways to reach a cell. There are 2 there are only 2 immediate positions from where a cell is reachable and those 2 immediate positions are, the top cell and the left cell.
        // does the number of ways the robot can reach this cell is equal to the number of ways the robot can reach the left cell plus the number of ways the robot can reach the top cell?
        // if we, if we, if we, if we develop this intuition, develop the answer using this intuition, what we can do is we can start from the cells neighbouring the top left corner where the robot is standing, where, I mean, we know the answer for the top left corner where the robot already is.
        // The ways to reach that corner is one because it is already there, right? So we start from there, we look at the neighbouring left and top cells for every cell starting from the, starting from the neighbouring cells of the robot, starting from the neighbouring cells of the top left corner.
        // We go through all the all the grid and we make up our solution. To the bottom right corner.
        
        vector<vector<int>> numberOfWays(grid.size(), vector<int>(grid[0].size(), 0));

        numberOfWays[0][0] = (grid[0][0] == 0) ? 1 : 0;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 0) {
                    if((i > 0) && (grid[i - 1][j] == 0)) {
                        numberOfWays[i][j] += numberOfWays[i - 1][j];
                    }
                    if((j > 0) && (grid[i][j - 1] == 0)) {
                        numberOfWays[i][j] += numberOfWays[i][j - 1];
                    }
                }
            }
        }

        return numberOfWays.back().back();
    }
};