class Solution {

    void exploreCombinations(
        int currIdx, string& digits, string& combination,
        vector<string>& combinations, vector<vector<char>>& keyCharMap
    ) {
        if(currIdx == digits.size()) {
            combinations.push_back(combination);
            return;
        }

        int digit = (digits[currIdx] - '0');

        for(char c: keyCharMap[digit]) {
            combination.push_back(c);
            exploreCombinations(currIdx + 1, digits, combination, combinations, keyCharMap);
            combination.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        // so the scenario is like this that a person has typed in digits, and we have to map it to the letters.
        // So the scenario is something like that, um, in the old ages, we had these, uh, phones, right, where we had to long press a specific digit to change the letter we had to type in. So, uh, for example, uh, if we have to type in, A, we would just type uh, 2 for slightly longer. We would get A, if we had to type B, we would have to hold on to the digit 2 key for even longer than the time we had to press it for A, and this way we would get the combination of letters we wanted.
        // And now there has been some, uh, miss happening. So if you long press a digit. It is not. Pressing any, it is not resulting into any other letters, rather it is only printing the digit, so as we get this string, we have to figure out, we have to figure out what the typer could have thought of typing into the, into the keyboard.
        // What we can do here is, um, we can map these uh, these letters to each digit and uh, as we go along the, the string, we try one letter and then we uh, move on to the next digit, guess a letter for that.
        // When we have made a combination in order to In order to figure out other combinations, we backtrack to the previous digits, we change our choices there. Changing a choice to a previous digit would completely change the uh, the, the combination that follows. So this way we would be able to come up with all the possible combinations.

        vector<vector<char>> keyCharMap = {
            {}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'},
            {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}
        };

        vector<string> combinations;
        if(digits.size() == 0) {
            return combinations;
        }
        string combination = "";

        exploreCombinations(0, digits, combination, combinations, keyCharMap);

        return combinations;
    }
};