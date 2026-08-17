class Solution {

    void connectWithOcean(int oceanType, int row, int col,
            vector<vector<int>>& heights, vector<vector<int>>& oceanConnection) {

        if(
            (row > 0) && 
            (heights[row - 1][col] >= heights[row][col]) &&
            (oceanConnection[row - 1][col] != oceanType) && // So that we do not go around cycles
            (oceanConnection[row - 1][col] != 3) // Same as above
        ) {
            if((oceanType == 1) && (oceanConnection[row - 1][col] == 2)) {
                oceanConnection[row - 1][col] = 3;
            } else if((oceanType == 2) && (oceanConnection[row - 1][col] == 1)) {
                oceanConnection[row - 1][col] = 3;
            } else {
                oceanConnection[row - 1][col] = oceanType;
            }

            connectWithOcean(oceanConnection[row - 1][col], row - 1, col, heights, oceanConnection);
        }
        if(
            (col > 0) && 
            (heights[row][col - 1] >= heights[row][col]) &&
            (oceanConnection[row][col - 1] != oceanType) && // So that we do not go around cycles
            (oceanConnection[row][col - 1] != 3) // Same as above
        ) {
            if((oceanType == 1) && (oceanConnection[row][col - 1] == 2)) {
                oceanConnection[row][col - 1] = 3;
            } else if((oceanType == 2) && (oceanConnection[row][col - 1] == 1)) {
                oceanConnection[row][col - 1] = 3;
            } else {
                oceanConnection[row][col - 1] = oceanType;
            }

            connectWithOcean(oceanConnection[row][col - 1], row, col - 1, heights, oceanConnection);
        }
        if(
            (row < (heights.size() - 1)) && 
            (heights[row + 1][col] >= heights[row][col]) &&
            (oceanConnection[row + 1][col] != oceanType) && // So that we do not go around cycles
            (oceanConnection[row + 1][col] != 3) // Same as above
        ) {
            if((oceanType == 1) && (oceanConnection[row + 1][col] == 2)) {
                oceanConnection[row + 1][col] = 3;
            } else if((oceanType == 2) && (oceanConnection[row + 1][col] == 1)) {
                oceanConnection[row + 1][col] = 3;
            } else {
                oceanConnection[row + 1][col] = oceanType;
            }

            connectWithOcean(oceanConnection[row + 1][col], row + 1, col, heights, oceanConnection);
        }
        if(
            (col < (heights[0].size() - 1)) && 
            (heights[row][col + 1] >= heights[row][col]) &&
            (oceanConnection[row][col + 1] != oceanType) && // So that we do not go around cycles
            (oceanConnection[row][col + 1] != 3) // Same as above
        ) {
            if((oceanType == 1) && (oceanConnection[row][col + 1] == 2)) {
                oceanConnection[row][col + 1] = 3;
            } else if((oceanType == 2) && (oceanConnection[row][col + 1] == 1)) {
                oceanConnection[row][col + 1] = 3;
            } else {
                oceanConnection[row][col + 1] = oceanType;
            }

            connectWithOcean(oceanConnection[row][col + 1], row, col + 1, heights, oceanConnection);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // Can the water flow to diagonal cells or does it flow to horizontal or vertical cells only?
        // Do we need to figure out land cells which can receive water from both the oceans because of lower level or the cells which contribute rainfall because of their higher level?
        
        // I am thinking of making another grid which stores if a cell is connected directly or indirectly to the atlantic or pacific ocean, 0 represents that the cell isn't connected to any ocean, 1 represents that it is connected to pacific ocean, 2 represents connection with atlantic ocean and 3 represents connection with both of them.
        // Now, how do we fill this grid? Starting from the border cells we can explore the cells from which this cell can receive rainfall i.e. those which are greater or equal to the cell and this way we can figure out the connection measure of each and every cell.
        // At the end we return those cells which are connected both the oceans.

        if((heights.size() == 1) || (heights[0].size() == 1)) {
            vector<vector<int>> ans;
            for(int i = 0; i < heights.size(); i++) {
                for(int j = 0; j < heights[0].size(); j++) {
                    ans.push_back({i, j});
                }
            }
            return ans;
        }

        vector<vector<int>> oceanConnection(heights.size(), vector<int>(heights[0].size(), 0));

        for(int i = 0; i < (heights.size() - 1); i++) {
            oceanConnection[i][0] = 1;
            oceanConnection[i + 1][heights[0].size() - 1] = 2;
        }
        for(int i = 0; i < (heights[0].size() - 1); i++) {
            oceanConnection[0][i] = 1;
            oceanConnection[heights.size() - 1][i + 1] = 2;
        }

        oceanConnection[heights.size() - 1][0] = 3;
        oceanConnection[0][heights[0].size() - 1] = 3;

        for(int i = 0; i < (heights.size() - 1); i++) {
            // For Pacific Ocean
            connectWithOcean(1, i, 0, heights, oceanConnection);

            // For Atlantic Ocean
            connectWithOcean(2, i + 1, heights[0].size() - 1, heights, oceanConnection);
        }
        for(int i = 0; i < (heights[0].size() - 1); i++) {
            // For Pacific Ocean
            connectWithOcean(1, 0, i, heights, oceanConnection);

            // For Atlantic Ocean
            connectWithOcean(2, heights.size() - 1, i + 1, heights, oceanConnection);
        }

        // For Both
        connectWithOcean(3, heights.size() - 1, 0, heights, oceanConnection);
        connectWithOcean(3, 0, heights[0].size() - 1, heights, oceanConnection);

        vector<vector<int>> ans;

        for(int i = 0; i < heights.size(); i++) {
            for(int j = 0; j < heights[0].size(); j++) {
                if(oceanConnection[i][j] == 3) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};