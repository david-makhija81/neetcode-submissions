class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // A cell is connected with an island only if a cell in the up, down, left or right direction is "1" else the connection with diagonal cells does not count right?
        // There are only 2 kinds of cells "1" & "0", right?

        // The approach that comes to my mind here is to keep a counter of islands discovered and whenever I discover a new island I would increase that counter by one.
        // Discovering a land cell would indicate discovering an island altogether.
        // But what if I discover 2 land cells connected to the same island - here I might risk counting an island twice.
        // Thus whenever I discover a land cell I will first mark it visited and then discover all the land cells connected to it and mark them visited as well, This way I do not risk counting an island more than once.

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int islandCounter = 0;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if((grid[i][j] == '1') && (!visited[i][j])) {
                    islandCounter++;

                    queue<pair<int, int>> neighbours;
                    neighbours.push({i, j});
                    visited[i][j] = true;

                    while(!neighbours.empty()) {
                        int currRow = neighbours.front().first;
                        int currCol = neighbours.front().second;

                        neighbours.pop();

                        if(
                            (currRow > 0) && 
                            (grid[currRow - 1][currCol] == '1') && 
                            (!visited[currRow - 1][currCol])
                        ) {
                            neighbours.push({currRow - 1, currCol});
                            visited[currRow - 1][currCol] = true;
                        }
                        if(
                            (currCol > 0) && 
                            (grid[currRow][currCol - 1] == '1') && 
                            (!visited[currRow][currCol - 1])
                        ) {
                            neighbours.push({currRow, currCol - 1});
                            visited[currRow][currCol - 1] = true;
                        }
                        if(
                            (currRow < (grid.size() - 1)) && 
                            (grid[currRow + 1][currCol] == '1') && 
                            (!visited[currRow + 1][currCol])
                        ) {
                            neighbours.push({currRow + 1, currCol});
                            visited[currRow + 1][currCol] = true;
                        }
                        if(
                            (currCol < (grid[0].size() - 1)) && 
                            (grid[currRow][currCol + 1] == '1') && 
                            (!visited[currRow][currCol + 1])
                        ) {
                            neighbours.push({currRow, currCol + 1});
                            visited[currRow][currCol + 1] = true;
                        }
                    }
                }
            }
        }

        return islandCounter;
    }
};