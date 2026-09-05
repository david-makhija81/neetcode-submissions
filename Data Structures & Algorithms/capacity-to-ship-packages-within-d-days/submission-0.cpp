class Solution {

    bool canShip(vector<int>& weights, int capacity, int days) {
        int currLoad = 0;
        int day = 1;

        for(int package: weights) {
            if(currLoad + package > capacity) {
                day++;
                if(day > days) {
                    return false;
                }
                currLoad = package;
            } else {
                currLoad += package;
            }
        }

        return true;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        // so, we must, as soon as a wait arrives, it must be shipped, like straight on, we cannot hold it in captivity, and send the next wait out before this one, is it so?
        // so we must ship the boxes in intervals as they come. 1st interval can be 5 boxes that came one after another, then next interval could be 2 boxes, they also came after these 5 boxes, and both of those came after one after another. came like one after another, and the 3rd interval could be 3 boxes, which came one after another, and All the 3 of them came after the 1st 2 intervals that we shipped, right?
        // so we have to make these contiguous windows of shipments.
        // and the maximum weight of any of these windows would decide the maximum capacity that the ship can carry on a given day.
        // And the number of windows must be equal to the number of days.
        // Thus, we have to minimise the maximum window weight out of all the windows partitions possible.
        // to minimise this maximum window weight among all the possible window partitions for given a number of windows, we must 1st be aware of the possible values this this maximum weight can take.
        // this maximum weight depends upon the number of days we have to ship the packages.
        // as if we have like only 2 days to ship the packages, we must make a lengthier, we must make lengthier, what do you call it? lengthier windows, so that all the packages are shipped in two days.
        // but if say, we have a lenient delivery time, we have a lenient time to get things delivered, we have, let's say we have five items and we have five days to deliver them, then we can just, uh, deliver each package uh, on a day.
        // So window length would be only one in that, in that case and we would only have to ship minimal weight package windows in that case.
        // so if we have end packages and we have any number of days to deliver it, then maximum capacity needed for the ship is equal to the maximum element in that is equal to the maximum weight of one package in that ship.
        // and if on the other extreme, we have only one day to deliver any number of items, then ship needs to have the capacity equivalent to the sum of all the weights, all the packages that we have.
        // so this maximum sum of a window, or this maximum sum of package interval, is the sum of entire array, and the minimum is, the maximum element out of the array, so the range between, uh, in between which this lies is, uh, the maximum element of uh, ranging from the maximum element in the array to the sum of the entire array.
        // And within this range, we have to find The ideal, the minimum maximum weight. This we can find via binary research.

        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        int capacity = right;

        while(right >= left) {
            int currCapacity = ((right - left) / 2) + left;

            if(canShip(weights, currCapacity, days)) {
                capacity = min(capacity, currCapacity);
                right = currCapacity - 1;
            } else {
                left = currCapacity + 1;
            }
        }

        return capacity;
    }
};