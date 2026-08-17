class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // What kind of characters does a string in this vector contain?

        // So, two strings are anagrams of each other if they contain the same unique elements and even the count of those unique elements is same in both the strings.
        // If we ever sort 2 anagrams both of them result in the same sequence of characters.
        // Thus, maybe for each string we can calculate it's sorted version and call that sorted version a key.
        // If 2 strings have the same key, then they are anagrams of each other.
        // We can maintain a hash_map which maps a key to an array of strings that resulted in that key after sorting.
        // This way we can easily group anagrams.

        unordered_map<string, vector<string>> anagramGroup;

        for(string str: strs) {
            string key = str;
            sort(key.begin(), key.end());

            if(anagramGroup.find(key) == anagramGroup.end()) {
                vector<string> group;
                anagramGroup.insert({key, group});
            }

            anagramGroup[key].push_back(str);
        }

        vector<vector<string>> ans;

        for(auto itr = anagramGroup.begin(); itr != anagramGroup.end(); itr++) {
            ans.push_back(itr -> second);
        }

        return ans;
    }
};