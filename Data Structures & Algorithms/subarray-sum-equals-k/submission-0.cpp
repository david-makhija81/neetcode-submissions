class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // A subarray is a part of the array that has contiguous elements from the array, thus, in my opinion, I can treat a subarray as a window of the array.
        // I can do a whole lot of operations with this window in in an array. I can expand it towards the right, or shrink it from the left, and see if the some of the elements in the window sum up two sums up to K, and I can just increment the number of windows, I can just count the number of windows, that that that that sum up to, K.
        // so the naive approach is this only, that I explore all such windows, and if any of them sums up to K, then I just increment the count, else I just leave it there and there.
        // but it does not make any sense to explore all the subberies. For example, if starting from the index two, I go up to the index five, I get the sum from 2 to 5, the window from 2 to 5 to be greater than or equal to K, then there is no sense of putting another element.
        // Let's say of index 6 to the to the window as it will only increase the sum and this way we cannot achieve a sum of elements equal to K, as it will only surpass K, so we should, we should leave some starting index.
        // As soon as we should leave some starting index, as soon as we get a sum of the window starting at that element, we get a sum greater than, greater than are equal to K, we should then start shrinking the window from the left and consider.
        // Consider further indices to be the starting point of the window.
        // because there are negative elements in the array as well, I would have to change my approach.
        // on another note, for every index, if we have the prefix sum, it makes it a lot easier to just to find out the sum of a subbury in least possible time.

        vector<int> prefixSum;

        int currSum = 0;

        int cnt = 0;

        for(int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            prefixSum.push_back(currSum);
        }

        // if I need to know how many subways, other that end data that start from a particular index, and at any index, that is greater than this index, and has the sum K, what would I do? I would search for an index that has a prefix sum equal to K plus this prefixSum

        multiset<int> prefixes;

        for(int i = 0; i < nums.size(); i++) {
            prefixes.insert(prefixSum[i]);
        }

        for(int i = 0; i < nums.size(); i++) {
            cnt += (prefixes.count(k - nums[i] + prefixSum[i]));
            prefixes.erase(prefixes.find(prefixSum[i]));
        }

        return cnt;
    }
};