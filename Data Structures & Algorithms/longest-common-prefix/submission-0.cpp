class Solution {

    bool matches(int idx, vector<string>& strs) {
        char c = strs[0][idx];

        for(string str: strs) {
            if(c != str[idx]) {
                return false;
            }
        }

        return true;
    }

public:
    string longestCommonPrefix(vector<string>& strs) {
        // So, we have to find the longest common prefix shared between the given strings.
        // prefix of any string starts from the beginning and go up to any length lesser than the string.
        // Thus, we must start from the first character of  all the strings keep advancing to the next character while the characters in consideration are equal.

        int minLength = 201;

        for(string str: strs) {
            int len = str.size();
            minLength = min(minLength, len);
        }

        string prefix = "";

        if(strs.empty()) {
            return prefix;
        }

        for(int i = 0; i < minLength; i++) {
            // cout << strs[0][i] << endl;

            if(matches(i, strs)) {
                prefix.push_back(strs[0][i]);
            } else {
                break;
            }
        }

        return prefix;
    }
};