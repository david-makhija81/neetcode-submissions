class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // So, we have to look for the longest increasing subsequence.
        // A subsequence that only increases and is a part of the actual elements need not be continguous but they have to be in the exact same order.
        // The straightforward solution would obviously be to try out all the increasing subsequences and return the length of the longest of all of them.
        // But, this would require a lot of operations.
        // Another approach we can try is to solve this problem in steps - we can maybe solve the problem first for the array of length 1 then after that we can store the length of longest increasing subsequence ending at this element.
        // And after that when we try to solve it for successive elements we can look for an element lesser than this one with whom this element can make a subsequence and store the result in this position.

        vector<int> maxLength(nums.size(), 1);
        int ans = 1;

        for(int i = 0; i < nums.size(); i++) {
            for(int j = (i - 1); j >= 0; j--) {
                if(nums[j] < nums[i]) {
                    maxLength[i] = max(maxLength[i], maxLength[j] + 1);
                }
            }
            
            ans = max(ans, maxLength[i]);
        }

        return ans;
    }
};