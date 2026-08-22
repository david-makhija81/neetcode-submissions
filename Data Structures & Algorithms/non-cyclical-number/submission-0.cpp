class Solution {
public:
    bool isHappy(int n) {
        // The thing that this question suggests at it's face value is to keep calculating the sum squares of digits until either we encounter a 1 or it appears that this algorithm is resulting in a loop.
        // But, how do we decide that this approach/algorithm is resulting in a loop.
        // Maybe we keep a set of integers already witnessed going through this algorithm and if even once an integer repeats, then we end the loop signifying that we did not find 1 in the process.

        vector<int> squares;

        for(int i = 0; i < 10; i++) {
            squares.push_back(i * i);
        }

        set<int> squareSumsAlreadyVisited;

        int currSquareSum = n;

        while(true) {
            int squareSum = 0;
            while(currSquareSum > 0) {
                squareSum += squares[currSquareSum % 10];

                currSquareSum /= 10;
            }

            if(squareSum == 1) {
                return true;
            }

            if(
                squareSumsAlreadyVisited.find(squareSum) !=
                squareSumsAlreadyVisited.end()
            ) {
                break;
            }

            squareSumsAlreadyVisited.insert(squareSum);

            currSquareSum = squareSum;

            // cout << "Square Sum is: " << currSquareSum << endl;

        }

        return false;
    }
};