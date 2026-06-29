class Solution {

    bool isOpeningBracket(char c) {
        return ((c == '\(') || (c == '\{') || (c == '\['));
    }

    char correspondingOpeningBracket(char c) {
        if(c == '\)') {
            return '\(';
        }
        if(c == '\]') {
            return '\[';
        }
        return '\{';
    }

public:
    bool isValid(string s) {
        stack<char> brackets;

        for(char bracket: s) {
            if(isOpeningBracket(bracket)) {
                brackets.push(bracket);
            } else if((!brackets.empty()) && (correspondingOpeningBracket(bracket) == brackets.top())) {
                brackets.pop();
            } else {
                return false;
            }
        }

        return brackets.empty();
    }
};
