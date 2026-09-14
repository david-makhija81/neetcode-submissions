class Solution {
public:
    int tribonacci(int n) {
        if(n < 3) {
            if(n == 0) {
                return 0;
            }

            return 1;
        }

        
        vector<int> triNum(n + 1);

        triNum[0] = 0;
        triNum[1] = 1;
        triNum[2] = 1;

        for(int i = 3; i <= n; i++) {
            triNum[i] = triNum[i - 1] + triNum[i - 2] + triNum[i - 3];
        }

        return triNum[n];
    }
};