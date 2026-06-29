class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0, leftEnd = 0, rightEnd = height.size() - 1;

        while(leftEnd < rightEnd) {
            result = max(result, (rightEnd - leftEnd)*min(height[leftEnd], height[rightEnd]));

            if(height[leftEnd] < height[rightEnd]) {
                leftEnd++;
            } else {
                rightEnd--;
            }
        }

        return result;
    }
};