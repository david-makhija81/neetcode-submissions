class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // So, we need to rotate the array k times.
        // Rotating the array by one means that we shift each element by one to the right and if the last element goes out of bounds then we push it to the beginning of the array.
        // Rotating it by k means that we transfer each element after k places.
        // Thus, we keep replacing the current element with the kth element counted from here until we cyclically reach the same element from where we started.

        int n = nums.size();
        k = (k % n);
        queue<int> kElements;

        for(int i = 0; i < n; i++) {
            if(kElements.size() < k) {
                kElements.push(nums[i]);
            } else {
                kElements.push(nums[i]);

                int replacement = kElements.front();
                kElements.pop();

                nums[i] = replacement;
            }
        }

        int i = 0;

        while(!kElements.empty()) {
            nums[i] = kElements.front();
            kElements.pop();

            i++;
        }
    }
};