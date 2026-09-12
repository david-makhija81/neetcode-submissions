class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // This is a... Problem that requires us to go from the top lift, uh, corner sill, to the bottom right corner, right? and uh, it requires us to keep adding up the cells that come in our path. I mean, it requires us to add up the values of the, um, that are there in the cells, uh, of the path that we traverse from the top left corner to the bottom right corner.
        // Standing at a cell, um, What neighbouring cells can I visit? Can I visit like neighbouring sales that are diagonally to me? Can I visit service to the left of me? Can I visit sales to the top of me? Can I?

        // So standing at a cell, we can only go either down or right.
        // A straightforward solution that comes from a mind is to start from the top left corner. At first take the right turn, then take the right turn again, keep doing it until you cannot take right turn, or you have reached the bottom left cell.

        // Sorry, bottom right cell, and if you cannot take any more right turns and you have not reached your location, then start taking downturns, and you reach there, you have your sum. After that, uh, after that you have your sum, with you, you keep it somewhere so that you can replace it, if you find a path.

        // So you find a path from the top left corner to the bottom right corner, but we are not sure, obviously, we're not sure that this is the path with the minimum sum. So we have it placed somewhere in a placeholder and so we have the paths up for this path.

        // And uh, as we came from uh, the top left corner to this right corner by making some decisions either to go right or to go down. We backtrack to the cells from where we have reached here, and for each cell, we try changing our decisions, if we can.

        // Like, if we took a downturn there, uh, we try to take a right turn, from that cell, and see where it leads us, um, if it leads us to the, If it leads us to the bottom right corner, and, when we reach the bottom right corner, we check if this sum is lesser than the one lesser than the ones that we encountered earlier.

        // So this way we can explore all the paths, and this way we can explore all the paths, and And find the minimum sum.

        vector<vector<int>> minPath(grid.size(), vector<int>(grid[0].size()));

        minPath[0][0] = grid[0][0];

        for(int i = 1; i < grid[0].size(); i++) {
            minPath[0][i] = minPath[0][i - 1] + grid[0][i];
        }
        for(int i = 1; i < grid.size(); i++) {
            minPath[i][0] = minPath[i - 1][0] + grid[i][0];
        }

        for(int i = 1; i < grid.size(); i++) {
            for(int j = 1; j < grid[0].size(); j++) {
                minPath[i][j] = min(minPath[i - 1][j], minPath[i][j - 1]) + grid[i][j];
            }
        }

        return minPath.back().back();
    }
};