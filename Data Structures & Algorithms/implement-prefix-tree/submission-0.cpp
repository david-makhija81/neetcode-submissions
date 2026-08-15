// Does the structure need to store only alphabet characters or anything other than that as well?
// Does it store only lowercase alphabets or does it store uppercase ones as well?

// I think making a tree kind of data structure where each node represents a character would space efficient here.
// In this tree a path from root to leaf would indicate a specific word.
// In this solution, if I have to insert a word and a word already exists in the data structure whose prefix to a certain length matches with the word to be inserted then it does not create new nodes for that prefix rather it uses the already existing ones.
// Thus it is space efficient, And the Time Complexity for finding a string would also be only linear.

class PrefixTree {
    PrefixTree* branches[26]; // ith branch represents if any word exists in this structure that has the (i + 1)th alphabet next to the current alphabet.
    bool isLeaf;

public:
    PrefixTree() {
        for(int i = 0; i < 26; i++) {
            branches[i] = NULL;
        }

        isLeaf = false; // default value of isLeaf is false only if a word is inserted and current node is the last character of that word then it will automatically become true in the insert function.
    }

    ~PrefixTree() {
        for(int i = 0; i < 26; i++) {
            delete branches[i];
            branches[i] = NULL;
        }
    }
    
    void insert(string word) {
        if(word == "") {
            isLeaf = true; // It means that this was the last character of the inserted word.
            return;
        }

        int charPos = word[0] - 'a';

        if(branches[charPos] == NULL) {
            PrefixTree* newChar = new PrefixTree();

            branches[charPos] = newChar;
        }

        branches[charPos] -> insert(word.substr(1, word.size() - 1));
    }
    
    bool search(string word) {
        if(word == "") {
            return isLeaf; // This determines if this current found sequence of characters was full word inserted earlier in this structure or just a prefix some other word
        }

        int charPos = word[0] - 'a';

        if(branches[charPos] == NULL) {
            return false; // Can not find the rest of the word because the character sequence only exists till here in the Structure.
        }

        return branches[charPos] -> search(word.substr(1, word.size() - 1));
    }
    
    bool startsWith(string prefix) {
        if(prefix == "") {
            return true; // All the characters have been found thus we return true.
        }

        int charPos = prefix[0] - 'a';

        if(branches[charPos] == NULL) {
            return false; // Can not find the rest of the prefix because the character sequence only exists till here in the Structure.
        }

        return branches[charPos] -> startsWith(prefix.substr(1, prefix.size() - 1));
    }
};