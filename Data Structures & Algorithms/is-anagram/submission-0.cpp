class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> sCharFrequency;
        unordered_map<char, int> tCharFrequency;

        for(int i = 0; i < s.size(); i++) {
            sCharFrequency[s[i]]++;

            tCharFrequency[t[i]]++;
        }

        for(auto itr = sCharFrequency.begin(); itr != sCharFrequency.end(); itr++) {
            if((itr -> second) != (tCharFrequency[itr -> first])) {
                return false;
            }
        }

        return true;
    }
};