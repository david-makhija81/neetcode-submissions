class Solution {

    long long calculateTime(int speed, vector<int> piles) {
        long long time = 0;

        for(int pile: piles) {
            time += (pile / speed);

            if((pile % speed) > 0) {
                time++;
            }
        }

        return time;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // So, we have to choose the minimum banana eating speed so that koko is able to eat all the bananas in given time.
        // Thus, we might have to go through all possible values of the eating speed try eating at that speed figure out if this speed gets all the bananas eaten and return the minimum such speed.
        // On another note what is the range of possible values for such speed? The minimum possible value must be 1 only because we need to finish the bananas and the maximum value for this thing must be the maximum value from piles because koko can not eat more than one pile in an hour thus, any speed greater than that would be a waste.
        // So, the banana eating speed ranges from 1 to the maximum element of piles array.
        // Do we need to try all the speeds or is there an intelligent workaround that can save us some operations?
        // Maybe we can keep dividing the search space for this speed until we narrow it down to one and then return that value.
        // Okay, so we take the median of the search space then after that we calculate the number of hours it takes koko to eat all the piles if that time is lesser than or equal to the actual time that means we can still lower on the value of speed by cutting off the right half of search space because we need to select the minimum and if the calculated time is greater than that of given time then we must increase the speed by cutting the left half of the search space.

        int left = 1, right = *max_element(piles.begin(), piles.end());
        int ans = right;

        while(left <= right) {
            int mid = ((right - left) / 2) + left;

            long long totalTime = calculateTime(mid, piles);

            if(totalTime <= h) {
                right = mid - 1;
                ans = min(ans, mid);
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};