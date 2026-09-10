class Solution {
public:
    int numSquares(int n) {
        // How do we add squares? Can we repeat the squares like so is three a valid answer? I mean, for 3 is 3 a valid answer because the least number of squares, 1, 1, 1 is needed.
        // One thing we can do is, we can. Explore all the squares, I mean, we can, you know, start with one, maybe start with zero. Uh, we figure out if we can, uh, we, if we should add one. We add one. And after that, as we add one, we explore other squares as well.
        // And sometimes in some cases, we do add like 4 in other cases, we don't. And this way, we explore the addition of all the squares, and if let's say by exploring all these possibilities, we get to the number N, while not repeating these squares, if we do get to the number N, then obviously, it is possible, and the least number is that number only. else we return -1

        vector<int> minSquares(n + 1, INT_MAX);

        minSquares[0] = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; (j * j) <= i; j++) {
                int square = (j * j);

                minSquares[i] = min(minSquares[i - square] + 1, minSquares[i]);
            }
        }

        return minSquares[n];
    }
};