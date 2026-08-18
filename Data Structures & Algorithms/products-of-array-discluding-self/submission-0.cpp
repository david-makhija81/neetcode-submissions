class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // If I have an array that looks like [1, 2, 3] - the answer would probably look like [6, 3, 2]
        // If we could use the division operation I would have kept the product of the entire array in some placeholder.
        // And, to get the product of the array except self I would have divided the whole product with the current and put it in the answer array at the exact position that this element occupies.
        // But, we cannot use the division operation thus we can maintain something known as the suffix product and prefix product.
        // prefix product for an element is the product of all the elements starting from the 0th element up till this element excluding this element. And suffix product is something similar but rather than the product starting from the 0th element we start the product from the next element only up till the last element including the last element.
        // With the help of these arrays I can figure out the product of array except self by multiplying the prefix product and suffix product for that element

        vector<int> prefixProduct(nums.size(), 1);
        vector<int> suffixProduct(nums.size(), 1);

        for(int i = 1; i < nums.size(); i++) {
            prefixProduct[i] = prefixProduct[i - 1] * nums[i - 1];
            suffixProduct[nums.size() - i - 1] = suffixProduct[nums.size() - i] * nums[nums.size() - i];
            // cout << i << endl;
        }

        vector<int> ans(nums.size());

        for(int i = 0; i < nums.size(); i++) {
            ans[i] = prefixProduct[i] * suffixProduct[i];
        }

        return ans;
    }
};