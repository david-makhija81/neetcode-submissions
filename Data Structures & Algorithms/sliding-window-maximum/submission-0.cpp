class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // So, we have a sliding window of fixed size and each time it moves it adds an element into and removes the other one.
        // This way the elements inside keep changing and so do the minimum and maximum values among them.
        // I have to return the maximum element for each window.
        // If we go about solving this problem with a straightforward approach, we would have to manually look for the maximum element in the array every time an element is popped from the array and a new element is pushed.
        // Thus, if we had a data structure which optimized this look up we would actually benefit greatly from that in cpp we can maybe use the multiset for this kind of thing and choose the last element in the set as it would be the maximum.

        int left = 0, right = 0;
        vector<int> ans;
        multiset<int> window;

        while(right < nums.size()) {
            if(right < k) {
                window.insert(nums[right]);
                right++;
                if(right == k) {
                    ans.push_back(*(prev(window.end())));
                }
                continue;
            }

            window.insert(nums[right]);
            right++;

            window.erase(window.find(nums[left]));
            left++;

            ans.push_back(*(prev(window.end())));
        }

        return ans;
    }
};