class Solution {
public:
    vector<int> countBits(int n) {
        // How many bits does n have?

        // The simplest way of coming up with an answer for this would be to conventionally count the number of of bits each of these integers and fill up the answer.

        vector<int> ans(n + 1, 0);

        for(int i = 0; i <= n; i++) {

            int currN = i;

            while(currN > 0) {
                if(currN & 1) {
                    ans[i]++;
                }

                currN = currN >> 1;
            }
        }

        return ans;
    }
};