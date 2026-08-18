struct comp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return a.first < b.first;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Does it contain any negative values?
        // Do I need to return the elements or their indices?

        // I think if we calculate the number of times each element occurs in the array and store it along with the element itself in a sack.
        // If the sack automatically gives the most frequent element one could pull out the most frequent element a total of k times.
        // For example for array = [1, 1, 1, 2, 2, 7] and k = 2 the sack would look something like [[3 (Count of element), 1 (Element itself)], [2, 2], [1, 7]]
        // When we grab the most frequent element, at first we get [3, 1] where the element is 1.
        // And after this pull the array looks like [[2, 2], [1, 7]].
        // Once more we pull out the most frequent element and we get [2, 2] the element it self is 2.
        // A priority can replace the sack we about in above example.

        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> mostFrequentCandidate;

        unordered_map<int, int> numFreq;

        for(int num: nums) {
            if(numFreq.find(num) == numFreq.end()) {
                numFreq.insert({num, 1});
            } else {
                numFreq[num]++;
            }
        }

        for(auto itr = numFreq.begin(); itr != numFreq.end(); itr++) {
            mostFrequentCandidate.push({itr -> second, itr -> first});
        }

        vector<int> ans;

        for(int i = 0; i < k; i++) {
            ans.push_back(mostFrequentCandidate.top().second);

            mostFrequentCandidate.pop();
        }

        return ans;
    }
};