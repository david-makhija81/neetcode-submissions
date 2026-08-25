class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // So, we are given an m x n grid and if there is some rotting orange in any cell and it has other healthy oranges next to it then the other healthy oranges get rotten as well and these newly rotten oranges spread this to other oranges as well.
        // And the time taken for getting an adjacent orange rotten is 1 minute. We have to figure out the minimum time required to get every orange rotten.
        // What we can do is that we can go through the grid and explore the oranges connected to it, make them rotten and then make the other oranges connected to the other rotten oranges rotten and repeat this process until all connected oranges are rotten.
        // But, this approach would only verify if all the oranges can get rotten or not, rather it can not predict the minimum time it takes to rot these oranges. As, even if we counted the time to rot all the oranges in this manner it might signal wrong values for some cases. For Example [[2, 1, 1, 2]] - as in this 4 x 1 grid as we traverse from the first element in the grid and make our way up to the last element we make the 3rd orange rotten in 2 minutes but when we want to consider the rotten orange and rot the oranges connected to it there are no healthy oranges around it anymore, thus we return 2 minutes rather it would have only taken 1 minute for the 4th orange to rot the 3rd one.
        // The minimum time an orange takes to get rotten is dependant upon the nearest rotten orange connected directly or indirectly to it.
        // Thus, we must store for each orange the minimum time it takes to get this orange rotten and keep updating it as we go along.

        vector<vector<int>> timeTakenToRot(grid.size(), vector<int>(grid[0].size()));

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 0) {
                    timeTakenToRot[i][j] = -1;
                } else if(grid[i][j] == 1) {
                    timeTakenToRot[i][j] = INT_MAX;
                } else {
                    timeTakenToRot[i][j] = 0;
                }
            }
        }

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(timeTakenToRot[i][j] == 0) {
                    queue<vector<int>> cells;

                    cells.push({i, j});

                    while(!cells.empty()) {
                        vector<int> currCell = cells.front();
                        cells.pop();

                        int currRow = currCell[0];
                        int currCol = currCell[1];

                        if(
                            (currRow > 0) && 
                            (
                                timeTakenToRot[currRow - 1][currCol] > 
                                (timeTakenToRot[currRow][currCol] + 1)
                            )
                        ) {
                            timeTakenToRot[currRow - 1][currCol] = 
                            (timeTakenToRot[currRow][currCol] + 1);
                            cells.push({currRow - 1, currCol});
                        }
                        if(
                            (currCol > 0) && 
                            (
                                timeTakenToRot[currRow][currCol - 1] > 
                                (timeTakenToRot[currRow][currCol] + 1)
                            )
                        ) {
                            timeTakenToRot[currRow][currCol - 1] = 
                            (timeTakenToRot[currRow][currCol] + 1);
                            cells.push({currRow, currCol - 1});
                        }
                        if(
                            (currRow < (grid.size() - 1)) && 
                            (
                                timeTakenToRot[currRow + 1][currCol] > 
                                (timeTakenToRot[currRow][currCol] + 1)
                            )
                        ) {
                            timeTakenToRot[currRow + 1][currCol] = 
                            (timeTakenToRot[currRow][currCol] + 1);
                            cells.push({currRow + 1, currCol});
                        }
                        if(
                            (currCol < (grid[0].size() - 1)) && 
                            (
                                timeTakenToRot[currRow][currCol + 1] > 
                                (timeTakenToRot[currRow][currCol] + 1)
                            )
                        ) {
                            timeTakenToRot[currRow][currCol + 1] = 
                            (timeTakenToRot[currRow][currCol] + 1);
                            cells.push({currRow, currCol + 1});
                        }
                    }
                }
            }
        }

        int maxTime = 0;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(timeTakenToRot[i][j] == INT_MAX) {
                    return -1;
                }

                maxTime = max(maxTime, timeTakenToRot[i][j]);
            }
        }

        return maxTime;
    }
};