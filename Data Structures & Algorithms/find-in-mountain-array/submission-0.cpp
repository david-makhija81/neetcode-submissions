/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // so we are given an array, and in that array, there's this peak. This peak is placed such that the elements that occur before it, like the elements starting from the index zero up till this element, all are in non-decreasing fashion or maybe ascending. Yeah, it is written ascending. So are in ascending order, and all the elements after it up till the last element are descending.
        // So we have to search for a target element in such array
        // I have one question. Can the target element exist in both the halves?
        // As there's no one to answer me for the previous question, I'll assume it can exist in both the halves.
        // So if there's a possibility that it can exist in both the halves, and in each half, the elements are sorted. In the first half in ascending order, and in the second half, in descending order, thus I can maybe use it to my advantage and first search in the first half because we have to return the minimum index. So I'll first search in the first half. If the target element exists there, that is the minimum index, I'll find for such target in the array, I return that.
        // If I do not find there, I'll search for it in the second half. If it does not exist there either, then I just return -1.
        // As we cannot make more than 100 calls to the mountain array, and we cannot do any sorting or any other transformative functions on the mountain array, I suppose we should pick the path of binary search. Because with binary search, we just do log n operations. And I suppose for the given input size, 100 calls would be enough
        // So we first search for the mountain element in this array, the element that divides the two halves, and then we just search for the target element in either of those halves.

        int leftPtr = 0, rightPtr = (mountainArr.length() - 1);

        int mountainElement = INT_MIN;
        int mountainIdx = -1;

        while(leftPtr <= rightPtr) {
            int mid = (((rightPtr - leftPtr) / 2) + leftPtr);

            int currCandidate = mountainArr.get(mid);

            if(mountainElement < currCandidate) {
                mountainElement = currCandidate;
                mountainIdx = mid;
            }

            if((mid > 0) && (mountainArr.get(mid - 1) > currCandidate)) {
                rightPtr = mid - 1;
            } else {
                leftPtr = mid + 1;
            }
        }

        leftPtr = 0, rightPtr = mountainIdx;

        while(leftPtr <= rightPtr) {
            int mid = (((rightPtr - leftPtr) / 2) + leftPtr);

            int currCandidate = mountainArr.get(mid);

            if(currCandidate == target) {
                return mid;
            } else if(currCandidate > target) {
                rightPtr = mid - 1;
            } else {
                leftPtr = mid + 1;
            }
        }

        leftPtr = mountainIdx, rightPtr = (mountainArr.length() - 1);

        while(leftPtr <= rightPtr) {
            int mid = (((rightPtr - leftPtr) / 2) + leftPtr);

            int currCandidate = mountainArr.get(mid);

            if(currCandidate == target) {
                return mid;
            } else if(currCandidate > target) {
                leftPtr = mid + 1;
            } else {
                rightPtr = mid - 1;
            }
        }

        return -1;
    }
};