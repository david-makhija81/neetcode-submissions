class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // The straightforward approach for this problem would be to linearly look for the heaviest 2 stones destroy both of one of them and update the other's and then repeat this process again.
        // This approach would require about O(n^2) operations - if we want to optimize it we need to come with a data structure that optimizes the look up for the heaviest stone - and we do have just the right thing and that is a priority queue.
        // Thus, at each turn until only one or no stone remains we fetch out the heaviest 2 stones out of the sack, we clash them together discard the destroyed stone and put back the stone with changed weight into the sack and repeat this process.

        priority_queue<int> stoneSack;

        for(int stone: stones) {
            stoneSack.push(stone);
        }

        while(stoneSack.size() > 1) {
            int stone1 = stoneSack.top();
            stoneSack.pop();
            int stone2 = stoneSack.top();
            stoneSack.pop();

            if(stone1 != stone2) {
                stoneSack.push(abs(stone1 - stone2));
            }
        }

        return (!stoneSack.empty()) ? stoneSack.top() : 0;
    }
};