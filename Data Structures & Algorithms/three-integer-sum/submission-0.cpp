class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int, int> sortedUniqueNumsFreq;

        for(int num: nums) {
            sortedUniqueNumsFreq[num]++;
        }

        vector<vector<int>> result;

        vector<int> sortedUniqueNums;

        if((sortedUniqueNumsFreq.find(0) != sortedUniqueNumsFreq.end()) && (sortedUniqueNumsFreq[0] > 2)) {
            result.push_back({0, 0, 0});
        }

        for(auto itr = sortedUniqueNumsFreq.begin(); itr != sortedUniqueNumsFreq.end(); itr++) {
            sortedUniqueNums.push_back(itr -> first);

            if((itr -> first) == 0) {
                continue;
            }

            if(((itr -> second) > 1) && ((sortedUniqueNumsFreq.find(0 - (2 * (itr -> first)))) != sortedUniqueNumsFreq.end())) {
                result.push_back({itr -> first, itr -> first, 0 - (2 * (itr -> first))});
            }
        }


        for(int i = 0; i < sortedUniqueNums.size(); i++) {
            int left = i + 1, right = sortedUniqueNums.size() - 1;

            while(left < right) {
                int sum = sortedUniqueNums[i] + sortedUniqueNums[left] + sortedUniqueNums[right];
                if(sum == 0) {
                    result.push_back({sortedUniqueNums[i], sortedUniqueNums[left], sortedUniqueNums[right]});
                    left++;
                    right--;
                } else if(sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return result;
    }
};
