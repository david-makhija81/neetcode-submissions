class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> numsAlreadyOccured;

        for(int num: nums) {
            if(numsAlreadyOccured.contains(num)) {
                return true;
            }

            numsAlreadyOccured.insert(num);
        }

        return false;
    }
};