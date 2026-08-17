class Solution {
public:
    int maxArea(vector<int>& heights) {
        // Are the heights all positive?
        // What is the minimum length of the array?

        // So, we have to select any two towers and then start pourring water between the towers; the volume of water that can be enclosed between the two towers is limited by the least height out of both the towers.
        // And, the volume of water enclosed between two towers is not affected by the towers in between these 2 towers right?
        // If the answer to the above question is yes then the volume of water enclosed between the 2 selected towers would be given by the formula below:
        // (distance between the 2 towers)*min(tower1, tower2)
        // One can maybe find all the combinations/pairs of 2 towers and calculate the volume of water enclosed
        // Return the maximum. But looking for the maximum by exploring all the possible pairs would take a lot of operations.
        // Thus, we may use an alternative approach and start from the widest pair of all where the two towers are at the most distance from each other that is the pair of first and last tower.
        // To explore other pairs we need to shrink this window, this will obviously decrease the distance between the towers but at the same time we might get a bigger tower thus resulting in more enclosed water.
        // The direction in which the window shrinks is decided by the smallest of the two towers because this tower is the bottleneck for the volume of enclosed water, thus we shrink the window from the side of smallest tower in hopes to find a bigger tower.

        int windowLeft = 0, windowRight = heights.size() - 1;
        int maxWater = 0;

        while(windowLeft < windowRight) {
            int threshold = min(heights[windowLeft], heights[windowRight]);

            maxWater = max(maxWater, (windowRight - windowLeft)*threshold);

            if(heights[windowLeft] < heights[windowRight]) {
                windowLeft++;
            } else {
                windowRight--;
            }
        }

        return maxWater;
    }
};
