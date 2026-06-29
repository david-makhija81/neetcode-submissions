class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap;

        for(string str: strs) {
            string key = str;
            sort(key.begin(), key.end());

            if(hashmap.find(key) == hashmap.end()) {
                hashmap.insert({key, {str}});
            } else {
                hashmap[key].push_back(str);
            }
        }

        vector<vector<string>> result;

        for(auto itr = hashmap.begin(); itr != hashmap.end(); itr++) {
            result.push_back(itr -> second);
        }

        return result;
    }
};
