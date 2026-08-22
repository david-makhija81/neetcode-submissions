class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // So, we have to find the kth largest element in the array.
        // That means the element from the end of the array, if the array was sorted.
        // Or put in another way the minimum of the top k elements by value.
        // Thus, I guess it must work if I had a structure that stored the top k elements seen so far and return the minimum element out of it.
        // But how do we update these top k elements as we go through element of the array?
        // To decide if an element belongs in the top k elements, we must compare that element with the minimum element of the group if it is greater than the minimum of the top k then it belongs in the top k elements.

        priority_queue<int, vector<int>, greater<int>> topK;

        for(int i = 0; i < nums.size(); i++) {
            if(topK.size() < k) {
                topK.push(nums[i]);
                continue;
            }

            int minElement = topK.top();
            topK.pop();

            topK.push(max(minElement, nums[i]));
        }

        return topK.top();
    }
};