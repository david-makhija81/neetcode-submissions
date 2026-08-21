// So, there is a key and in that key, multiple values are stored each value has it's timestamp.
// As it must be obvious when a value timestamp pair is inserted in a key the timestamp associated with this value is greater than the timestamp of last values.
// Thus, if we just keep pushing the value, timestamp pairs as they in the order that they come to us - then each array of value, timestamp pairs stored against a key would appear sorted in an increasing fashion with respect to the timestamp.
// Thus, we can take advantage of this while searching for a value associated with a timestamp against a key.
// We can implement a binary search function that searches for a timestamp against a key.

class TimeMap {
    unordered_map<string, vector<pair<int, string>>> timeBasedKeyValue;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if(timeBasedKeyValue.find(key) == timeBasedKeyValue.end()) {
            vector<pair<int, string>> timeValuePairs;
            timeBasedKeyValue.insert({key, timeValuePairs});
        }

        timeBasedKeyValue[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(timeBasedKeyValue.find(key) == timeBasedKeyValue.end()) {
            return "";
        }

        int left = 0, right = timeBasedKeyValue[key].size() - 1;
        string ans = "";

        while(left <= right) {
            int mid = ((right - left) / 2) + left;

            if(timeBasedKeyValue[key][mid].first <= timestamp) {
                ans = timeBasedKeyValue[key][mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */