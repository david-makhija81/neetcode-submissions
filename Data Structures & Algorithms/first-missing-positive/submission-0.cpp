class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // So I have to write an algorithm that finds a solution to this problem in O(n) time that means I cannot sort the array
        // and we cannot use any extra space as well, that means hash maps are out of scope here as well.
        // first approach that comes to my mind is, maybe we can find the minimum element of positive element that exists in the array and if that element is greater than one? Then we are sure that the element less than that element. The element that comes just before that element is our answer.
        // else if the minimum positive element is one, then in that case, we must find a number, we must find the maximum number N for which all the elements from 1 all the way up to N exist, but the N + 1 th element does not exist in that case N + 1 th element is our answer.
        // so the minimum value of minimum positive missing element can be one as we discussed earlier, but what can be the maximum value of such element? What is the maximum number of positive elements that we can fit into this array? It is N, the number of total elements in the array, and if the elements in the array are incremental from one to all the way up to N, all are like consecutive integers, then our answer would be N + 1.
        // Thus the answer range in in this problem is from one all the way up to N + 1 where N is the length of the array.
        // as the range of the answer goes from one all the way up to N +1, thus we can use indices in this case, as the indices range in any array go goes from zero all the way up to N -1, we can just add a new element and we are good too.
        // So we can track, if an element is present in the array, via changing the index, the value on an index of the array.

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0) {
                nums[i] = 0;
            }
        }

        for(int i = 0; i < nums.size(); i++) {
            int currCandidate = abs(nums[i]);

            if((currCandidate > 0) && (currCandidate <= nums.size())) {
                nums[currCandidate - 1] = (-1) * (abs(nums[currCandidate - 1]));
                if(nums[currCandidate - 1] == 0) {
                    nums[currCandidate - 1] = (-1) * (nums.size() + 1);
                }
            }
        }

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= 0) {
                return (i + 1);
            }
        }

        return (nums.size() + 1);
    }
};