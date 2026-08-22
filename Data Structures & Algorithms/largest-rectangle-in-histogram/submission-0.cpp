class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // We have to find the largest rectangle by area in a histogram.
        // That means, I need to draw a rectangle over the bars of a histogram and I have to return the area of the biggest rectangle I can draw this way.
        // If we have a histogram let's say in this form [1, 2, 3].
        // In this histogram the area of biggest rectangle that involves the 3rd bar is 3 because it spans that bar only.
        // Similarly, the area of biggest rectangle that includes the 2nd bar is 4 because it is limited by this bar's height and spans 2 bars in total.
        // Similarly, the area biggest triangle including the 1st bar is 3 as it is limited by height 1 but spans the 3 bars.
        // Thus, the maximum area of a rectangle that involves the entirity of a particular bar is limited by the bars lesser than this one.
        // Thus, we must start from right side and as we go to the left side we keep a record of the position to the right where we will find a bar lesser than this one, because that is the bar that will limit current rectangle's area. This way we keep calculating the area of max possible rectangle to the right of each bar and return the maximum out of all of them.
        // But the above approach fails in the case [2, 1, 2] because the max area for bar 0's rectangle to the right would be 2, the max area for bar 1's rectangle to the right would be 2 and the max area for bar 2's rectangle to the right would be 2 as well.
        // But it is clearly visible that a recatangle of area 3 is possible if we include the rectangle to the left of bar 1 as well as to the right of bar 1.
        // Thus, we must slightly change the algorithm so that it calculates max area to both the sides of each bar and look for the maximum from the sum of these 2 areas for each bar in the histogram.

        stack<int> minHeightToTheRight;

        vector<int> maxAreaToTheRight(heights.size());

        for(int i = heights.size() - 1; i >= 0; i--) {
            while(
                (!minHeightToTheRight.empty()) && 
                (heights[i] <= heights[minHeightToTheRight.top()])
            ) {
                minHeightToTheRight.pop();
            }

            if(!minHeightToTheRight.empty()) {
                maxAreaToTheRight[i] = (
                    (minHeightToTheRight.top() - i) *
                    heights[i]
                );
            } else {
                maxAreaToTheRight[i] = (
                    (heights.size() - i) *
                    heights[i]
                );
            }

            minHeightToTheRight.push(i);
        }


        stack<int> minHeightToTheLeft;

        vector<int> maxAreaToTheLeft(heights.size());

        for(int i = 0; i < heights.size(); i++) {
            while(
                (!minHeightToTheLeft.empty()) && 
                (heights[i] <= heights[minHeightToTheLeft.top()])
            ) {
                minHeightToTheLeft.pop();
            }

            if(!minHeightToTheLeft.empty()) {
                maxAreaToTheLeft[i] = (
                    (i - minHeightToTheLeft.top()) *
                    heights[i]
                );
            } else {
                maxAreaToTheLeft[i] = (
                    (i + 1) *
                    heights[i]
                );
            }

            minHeightToTheLeft.push(i);
        }

        int ans = 0;

        for(int i = 0; i < heights.size(); i++) {
            ans = max(
                maxAreaToTheRight[i] + maxAreaToTheLeft[i] - heights[i],
                ans
            );

            // cout << maxAreaToTheRight[i] << ", " << maxAreaToTheLeft[i] << ", " << maxAreaToTheRight[i] + maxAreaToTheLeft[i] - heights[i] << endl;
        }

        return ans;
    }
};