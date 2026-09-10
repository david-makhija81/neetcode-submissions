class Solution {

    int score(int st, int en, int pile) {
        if(((en - st) % 2) == 1) {
            return pile;
        }

        return ((-1) * pile);
    }
    
public:
    bool stoneGame(vector<int>& piles) {
        // We have to, so Alice goes first, and Alice has to strategically pick a pile from either side of the stones, so that at the end of the competition, she gets away with the most number of stones.
        // At each point, Alice has to decide which pile to pick from both the ends, so that at the end, she goes away with the biggest, most number of stones.
        // Let's say at each turn, at each turn, when Alice has to choose one of the piles, Alice goes greedy, and Bob also goes greedy, in that scenario, will Alice be able to go away with the most number of stones, let's pick an example.
        // [1, 2, 3, 1]

        vector<vector<int>> gameState(piles.size(), vector<int>(piles.size(), 0));

        for(int i = 0; i < piles.size(); i++) {
            gameState[i][i] = (-1) * (piles[i]);
        }

        for(int i = 1; i < piles.size(); i++) {
            for(int st = 0; st < (piles.size() - i); st++) {
                int en = st + i;
                gameState[st][en] = max(
                    (gameState[st + 1][en] + score(st, en, piles[st])), 
                    ((gameState[st][en - 1] + score(st, en, piles[en])))
                );
            }
        }

        return (gameState[0][piles.size() - 1] > 0);
    }
};