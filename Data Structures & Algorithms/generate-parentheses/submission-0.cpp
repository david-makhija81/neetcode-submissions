class Solution {

    void makeBracketExpressions(
        string& expression, int openingBracketsLeft, int closingBracketsLeft,
        int bracketsLeftOpen, vector<string>& ans
    ) {
        if(closingBracketsLeft == 0) {
            ans.push_back(expression);
            return;
        }

        if(openingBracketsLeft > 0) {
            expression.push_back('(');
            makeBracketExpressions(expression, openingBracketsLeft - 1, closingBracketsLeft, bracketsLeftOpen + 1, ans);
            expression.pop_back();
        }

        if(bracketsLeftOpen > 0) {
            expression.push_back(')');
            makeBracketExpressions(expression, openingBracketsLeft, closingBracketsLeft - 1, bracketsLeftOpen - 1, ans);
            expression.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        // So, we have to generate parentheses expressions having n number of pairs of parentheses.
        // That means I have to use n opening parentheses and n closing ones and the resulting expression must be valid as well.
        // The expression is valid if and only if every closing bracket has an opening alternative in the left part of the string that has not yet been closed.
        // Thus we can place the opening bracket wherever we want but we put closing brackets only when an opening brackets on the left has been left unclosed.

        string expression = "";
        vector<string> ans;

        int openingBracketsLeft = n;
        int closingBracketsLeft = n;

        int bracketsLeftOpen = 0;

        makeBracketExpressions(expression, openingBracketsLeft, closingBracketsLeft, bracketsLeftOpen, ans);


        return ans;
    }
};