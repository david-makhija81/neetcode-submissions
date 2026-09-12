struct comp {
    bool operator()(vector<int>& a, vector<int>& b) {
        return (b[1] < a[1]);
    }
};

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // So I am provided with a combination lock, right?
        // So the combinations that this lock can have ranges from four consecutive zeros all the way up to four consecutive nines.
        // And with one move - One combination can transition into eight different other combinations.
        // Thus, we can maybe keep a map that maps, one combination to all the other 8 possibilities, and we do this for all the 10,000 combinations, that is from uh, 4 consecutive uh, zeros to 4 consecutive nines. For all of them, we keep this.
        // We keep this map that maps, one combination, all the way up to, sorry, that maps, one combination, uh, to the 8 combinations, uh, that can result from this combination.
        // To be honest, this map can help us a lot. Um, so what do we have, what we have to find is minimum uh, transitions, uh, so um, to reach that desired lock, that target lock? So what we do is, the state or the combination from where we start is 4 zeros and we traverse this map that we have just created that maps one combination to the 8 combinations that it can transition to.

        // And as we traverse this path of transitions, uh, we must find the minimum uh, path between this target node and the, The target node. The target combination and the source combination.

        vector<vector<int>> transitionGraph(10000);

        set<int> avoidCombinations;

        for(string comb: deadends) {
            avoidCombinations.insert(stoi(comb));
            if(comb == "0000") {
                return -1;
            }
            // cout << stoi(comb) << endl;
        }

        int targetCombination = stoi(target);

        for(int i = 0; i < 10000; i++) {
            for(int j = 1; j < 10000; j *= 10) {
                int transition1 = i + j;
                if(((i / j) % 10) == 9) {
                    transition1 = i - (9 * j);
                }
                if(avoidCombinations.find(transition1) == avoidCombinations.end()) {
                    transitionGraph[i].push_back(transition1);
                }
                int transition2 = i - j;
                if(((i / j) % 10) == 0) {
                    transition2 = i + (9 * j);
                }
                if(avoidCombinations.find(transition2) == avoidCombinations.end()) {
                    transitionGraph[i].push_back(transition2);
                }
            }
        }

        vector<int> minTransitions(10000, INT_MAX);

        minTransitions[0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, comp> updatedCombinations;

        updatedCombinations.push({0, 0});

        while(!updatedCombinations.empty()) {
            int comb = updatedCombinations.top()[0];
            updatedCombinations.pop();

            for(int nextComb: transitionGraph[comb]) {
                if(minTransitions[nextComb] > (minTransitions[comb] + 1)) {
                    minTransitions[nextComb] = minTransitions[comb] + 1;
                    updatedCombinations.push({nextComb, minTransitions[nextComb]});
                    // cout << nextComb << endl;
                }
            }
        }

        // for(int i = 0; i < 10000; i++) {
        //     cout << "Combination: " << i << ", ";
        //     cout << "Transitions: " << minTransitions[i] << endl;
        // }

        return (
            (minTransitions[targetCombination] != INT_MAX) ? 
            minTransitions[targetCombination] : 
            -1
        );
    }
};