class Solution {

    bool isOperand(string& op) {
        return (
            (op == "+") ||
            (op == "-") ||
            (op == "*") ||
            (op == "/")
        );
    }

    int calculateOperation(int value1, int value2, string& op) {
        int ans;

        if(op == "+") {
            ans = value1 + value2;
        }
        if(op == "-") {
            ans = value1 - value2;
        }
        if(op == "*") {
            ans = value1 * value2;
        }
        if(op == "/") {
            ans = value1 / value2;
        }

        return ans;
    }

public:
    int evalRPN(vector<string>& tokens) {
        // We have to evaluate a post fix expression.
        // In a postfix expression, we have to store any integers that we encounter somewhere, or even the integers we calculate in the process.
        // And whenever we encounter an operand we have to get the last 2 integers encountered / calculated, remove those 2 and push the integer calculated by the mutual operation related to that operand between these 2 integers.
        
        stack<int> numbers;

        for(string token: tokens) {
            if(isOperand(token)) {
                int value2 = numbers.top();
                numbers.pop();
                int value1 = numbers.top();
                numbers.pop();

                numbers.push(calculateOperation(value1, value2, token));
            } else {
                numbers.push(stoi(token));
            }
        }

        return numbers.top();
    }
};