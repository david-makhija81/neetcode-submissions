class Solution {
public:
    string convertToTitle(int columnNumber) {
        // The first thing we need to know is how Excel sheet columns are decided.
        // Like, uh, if I have to, you know, uh, signify the column 5, rather than just writing a plain old, uh, 5 there, they represent it with, they represent the rows with numbers and columns with and represent the columns with letters.
        // Or rather, uh, if put another way, um, the rows use a digit oriented number system and and the columns use a letter oriented number system.

        string ans = "";

        while(columnNumber > 0) {
            columnNumber--;
            
            int currCharNum = (columnNumber % 26);

            char currChar = 'A' + currCharNum;

            string temp = "";

            temp.push_back(currChar);

            ans = temp + ans;

            columnNumber /= 26;
        }

        return ans;
    }
};