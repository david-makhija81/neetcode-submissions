class Solution {
public:

    // I would have simply connected all the strings to encode.
    // But that would make it difficult for me to decode the strings as I would not be able to identify where one string ends and the other one starts.
    // To counter this I will try to connect all the strings but I will keep a delimiter character between the strings to mark the ending of one string and starting of another.
    // But what if a string contains that delimiter as it is given that the strings can have any of the 256 ASCII characters.
    // For example if the delimiter is a # and we get an in put ["le#et", "code"]
    // The encoded string would look something like "le#et#code"
    // If we try to decode this string we might decode it like [le, et, code]
    // Which does not match the array of strings we encoded earlier.
    // Another approach whose execution does not result in these caveates is to store in front of encoded string the length of the string itself.
    // But to avoid that number mixing up with the string itself we place a delimiter between the number and the string
    // For example if we receive ["#leet", "4code"] then the encoded version looks something like "5##leet5#4code"
    // When we try to decode this string we see 5 followed by a delimiter thus we expect 5 characters after that and here the 4 in front code did not create any confusion beacause the delimiter separated the length value and the character itself.

    string encode(vector<string>& strs) {
        string ans = "";
        for(string str: strs) {
            string lenString = to_string(str.size());

            ans = ans + lenString + "#" + str;
        }

        return ans;
    }

    vector<string> decode(string s) {
        int idx = 0;
        vector<string> ans;

        while(idx < s.size()) {
            string lenString = "";

            while(s[idx] != '#') {
                lenString.push_back(s[idx]);

                idx++;
            }

            idx++; // Jump ahead of the delimiter

            int len = stoi(lenString);

            string str = "";

            for(int i = 0; i < len; i++) {
                str.push_back(s[idx]);
                idx++;
            }

            ans.push_back(str);
        }

        return ans;
    }
};
