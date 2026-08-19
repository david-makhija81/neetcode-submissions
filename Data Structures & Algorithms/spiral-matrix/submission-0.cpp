class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // To traverse the matrix spirally we can basically start from the first element
        // Keep going until we hit a wall or an element that we have already visited
        // If we hit any of the things mentioned above, we take a right turn
        // If we take a right while going in a specific direction the next direction we'll head after this direction is fixed for every direction:
        // right --becomes--> down
        // down --becomes--> left
        // left --becomes--> up
        // up --becomes--> right
        // We'll a hard logic to take care of the direction and then I guess we are good to go.

        int currRow = 0, currCol = 0;
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
        int numberOfVisited = 0;
        int totalNumberOfCells = (matrix.size() * matrix[0].size());
        int direction = 0;
        vector<int> traversal;

        while(numberOfVisited < totalNumberOfCells) {
            if(!visited[currRow][currCol]) {
                traversal.push_back(matrix[currRow][currCol]);
                visited[currRow][currCol] = true;

                numberOfVisited++;
            }

            if(direction == 0) { // To the right
                if((currCol == (matrix[0].size() - 1)) || (visited[currRow][currCol + 1])) {
                    direction = ((direction + 1) % 4);
                    continue;
                }
                currCol++;
            } else if(direction == 1) { // Downwards
                if((currRow == (matrix.size() - 1)) || (visited[currRow + 1][currCol])) {
                    direction = ((direction + 1) % 4);
                    continue;
                }
                currRow++;
            } else if(direction == 2) { // leftwards
                if((currCol == 0) || (visited[currRow][currCol - 1])) {
                    direction = ((direction + 1) % 4);
                    continue;
                }
                currCol--;
            } else if(direction == 3) { // upwards
                if((currRow == 0) || (visited[currRow - 1][currCol])) {
                    direction = ((direction + 1) % 4);
                    continue;
                }
                currRow--;
            }
        }

        return traversal;
    }
};