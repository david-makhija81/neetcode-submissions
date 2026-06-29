class Solution {

    bool frequenciesMatch(unordered_map<char, int>& bluePrint, unordered_map<char, int>& characterFreq) {
        for(auto itr = bluePrint.begin(); itr != bluePrint.end(); itr++) {
            if((itr -> second) > characterFreq[itr -> first]) {
                return false;
            }
        }

        return true;
    }

public:
    string minWindow(string s, string t) {
        int minLength = s.size() + 1;
        string result = "";
        int leftEnd = 0;

        unordered_map<char, int> bluePrint1;
        unordered_map<char, int> bluePrint2;
        bool freqMatched = false;

        // for(int i = 0; i < s.size(); i++) {
        //     cout << s[i] << " ";
        // }

        // cout << endl;

        // for(int i = 0; i < s.size(); i++) {
        //     cout << i << " ";
        // }

        // cout << endl;

        for(char c: t) {
            bluePrint1[c]++;
            bluePrint2[c]++;
        }

        for(char c: s) {
            if(bluePrint1.find(c) == bluePrint1.end()) {
                bluePrint1[c] = 0;
            }
            // cout << c << " " << bluePrint1[c] << endl;
        }

        unordered_map<char, int> characterFreq;

        for(int rightEnd = 0; rightEnd < s.size(); rightEnd++) {
            characterFreq[s[rightEnd]]++;

            while(bluePrint1[s[leftEnd]] < characterFreq[s[leftEnd]]) {
                // cout << "before: " << s[leftEnd] << " " << bluePrint1[s[leftEnd]] << " " << characterFreq[s[leftEnd]] << endl;
                characterFreq[s[leftEnd]] = characterFreq[s[leftEnd]] - 1;
                // cout << "after: " << s[leftEnd] << " " << bluePrint1[s[leftEnd]] << " " << characterFreq[s[leftEnd]] << endl;
                leftEnd += 1;
            }
            // cout << leftEnd << " " << rightEnd << endl;

            int len = rightEnd - leftEnd + 1;
            if((freqMatched || frequenciesMatch(bluePrint2, characterFreq)) && (len < minLength)) {
                result = s.substr(leftEnd, len);
                minLength = len;
                freqMatched = true;
            }
        }

        return result;
    }
};