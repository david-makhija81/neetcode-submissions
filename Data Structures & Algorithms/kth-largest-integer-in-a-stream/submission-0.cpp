// We have to keep track of k highest scores in the stream.
// Just to clarify, can the scores repeat?
// Any score submitted can not be deleted, right?
// Can the initially passed array's length be lesser than k?

// When we see a score in front of us we must know if this score can be among the top k scores if it can be then add it to our list of top k scores 
// So, now our list becomes k + 1 elements long, thus we must delete one element out of it and that has to be the smallest of them, because it does not belong in top k for obvious reasons.
class KthLargest {
    priority_queue<int, vector<int>, greater<int>> topScores;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        for(int i = 0; (i < k) && (i < nums.size()); i++) {
            topScores.push(nums[i]);
        }

        for(int i = k; i < nums.size(); i++) {
            int topKthScore = topScores.top();
            topScores.pop();

            topScores.push(max(topKthScore, nums[i]));
        }

        this -> k = k;
    }
    
    int add(int val) {
        if(topScores.size() == k) {
            int topKthScore = topScores.top();
            topScores.pop();

            topScores.push(max(topKthScore, val));
        } else {
            topScores.push(val);
        }

        return topScores.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */