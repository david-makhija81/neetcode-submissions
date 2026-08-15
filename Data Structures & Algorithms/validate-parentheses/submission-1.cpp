class Solution {

    bool isClosingBracket(char bracket) {
        return ((bracket == ')') || (bracket == '}') || (bracket == ']'));
    }

    bool openingAndClosingMatch(char openingBracket, char closingBracket) {
        return (
                    ((openingBracket == '(') && (closingBracket == ')')) || 
                    ((openingBracket == '{') && (closingBracket == '}')) || 
                    ((openingBracket == '[') && (closingBracket == ']'))
                );
    }

public:
    bool isValid(string s) {
        // Does the expression contain anything other than the brackets themselves?
        // Are there multiple kinds of brackets in the expression?

        // If all the opening brackets find their closing alternative at the right position that means the expression is valid.
        // Thus we need to record the opening brackets encountered till now and we keep deleting them as we find their closing alternative.
        // Also as we go through the expression the most recently encountered opening bracket has to be closed has to be closed prior than the opening bracket that we encountered 5 brackets earlier - That makes common mathematical sense.
        // Thus the closing logic is kind Last opened first closed  kind of like Last in First Out.
        // So it makes sense to use a stack here to monitor the opening brackets encountered and keep popping them as we find their closing alternatives.

        stack<char> openingBrackets; // This tracks the opening brackets still open in the exact sequence as we find them.

        for(char bracket: s) {
            if(isClosingBracket(bracket)) {
                if((!openingBrackets.empty()) && openingAndClosingMatch(openingBrackets.top(), bracket)) { // We can close the still open last encountered opening bracket still in the stack.
                    openingBrackets.pop();
                } else { // This means that the expression is invalid.
                    return false;
                }
            } else {
                openingBrackets.push(bracket); // Another opening bracket encountered let's start tracking it.
            }
        }

        return (openingBrackets.empty()) ? true : false; // If all the open brackets were closed that means the expression was Valid.
    }
};