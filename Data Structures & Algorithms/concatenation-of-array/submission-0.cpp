class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        // So, the condition is to make an array of double the length of the array nums.
        // And, in that array the (i + n)th element must be equal to the ith element
        // That means that we must first insert the nums as it is in the ans array after that we must keep inserting the ith element to the end of the array from the 0th element up till the (n - 1)th element.

        vector<int> ans;

        for(int num: nums) {
            ans.push_back(num);
        }

        for(int i = 0; i < nums.size(); i++) {
            ans.push_back(ans[i]);
        }

        return ans;
    }
};