class Solution {
public:
    int calPoints(vector<string>& operations) {
        // can I encounter 'C' if there there are no previous scores and if there were previous scores, then they were removed because of the 'C' operation.
        // is there a guarantee that I will? Encounter the plus operation only when there are a minimum of two scores in the in the structure that I am? maintaining?
        // as in all the operations, I have to keep track of the last items that were pushed into the structure, the last items by by the order they were pushed into the structure.
        // as we need a last and 1st out kind of a structure, stack would surface here, I suppose.

        stack<int> scores;
        int ans = 0;

        for(auto operation: operations) {
            if(operation == "C") {
                ans -= scores.top();
                // cout << scores.top() << endl;
                scores.pop();
            } else if(operation == "D") {
                int lastScore = scores.top();
                scores.push(2 * lastScore);
                ans += scores.top();
                // cout << scores.top() << endl;
            } else if(operation == "+") {
                int score2 = scores.top();
                scores.pop();
                int score1 = scores.top();
                scores.pop();
                int score3 = score1 + score2;
                scores.push(score1);
                scores.push(score2);
                scores.push(score3);
                ans += scores.top();
                // cout << scores.top() << endl;
            } else {
                int score = stoi(operation);
                scores.push(score);
                ans += scores.top();
                // cout << scores.top() << endl;
            }
        }

        return ans;
    }
};