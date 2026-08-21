class Solution {
public:
    int trap(vector<int>& height) {
        // Suppose, if we have a height array like (3, 2, 1) if rain water falls on this elevation it will just flow down from 3 to 2 to 1 right?
        // In the example that we took the rain water flowed from 3 because there was no tower blocking rain water coming from tower 3 because there is no tower taller than 3.
        // Similarly, the rain water that falls on tower with height 2 is in fact stopped by the tower with height 3 but finds it's way down the slope to the right of tower with height 2 because the tower to it's right is smaller than this one thus it can not stop the rain water coming from tower with height 2.
        // Rather, if we looked at an example like [3, 1, 2] the water falling on the tower with height 1 would be entrapped from both the sides because the towers on both the sides are greater than this but the volume of water trapped is limited by the least of both the towers surrounding it. Because as the water tries to fill above the level 2 over 1 it will fall down through the tower 2.
        // Thus, the approach is simple we find the maximum height to the right of this tower and maximum height to the left - if both of them are greater than this tower then water gets trapped over this tower and volume of trapped water is limited by the minimum of the surrounding towers.

        vector<int> maxHeightToTheLeft(height.size());
        vector<int> maxHeightToTheRight(height.size());

        maxHeightToTheLeft[0] = height[0];
        maxHeightToTheRight[height.size() - 1] = height[height.size() - 1];

        for(int i = 1; i < height.size(); i++) {
            maxHeightToTheLeft[i] = max(maxHeightToTheLeft[i - 1], height[i]);
            maxHeightToTheRight[height.size() - i - 1] = max(
                maxHeightToTheRight[height.size() - i], 
                height[height.size() - i - 1]
            );
        }

        int trappedWater = 0;

        for(int i = 0; i < height.size(); i++) {
            int waterOverThisTower = max(min(
                maxHeightToTheLeft[i],
                maxHeightToTheRight[i]
            ) - height[i], 0);

            trappedWater += waterOverThisTower;
            // cout << "max height to the right of " << i << " is " << maxHeightToTheRight[i] << endl;
            // cout << "max height to the left of " << i << " is " << maxHeightToTheLeft[i] << endl;
            // cout << "Water trapped over " << i << " is " << waterOverThisTower << endl;
        }

        return trappedWater;
    }
};