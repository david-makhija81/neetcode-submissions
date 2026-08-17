// What kind of characters are pushed into the data structure, only lowercase alphabets or more than that?
// Do only the search queries contain . in them or is it also a part the add queries?

// I was thinking of making a tree for this data structure.
// Where each node represents a character of a word that exists in the data structure.
// This way we can save on number of operations while searching for a word or adding a word and adding a word as well.
// Because we just need that many number of operations equal to the number of characters as we only need to deal with this many number of nodes in the tree.
// Also, we save on space as well - as if we get insert queries like "dad" and "dab" then we only need four nodes to store these words whereas in traditional sense I would need six placeholders to hold these string because of the presence of six characters altogether.

class WordDictionary {
    WordDictionary* branches[26]; // This represents the the next character of the word that this character is a part of, as there could be multiple words that this character is a part of, and in each word the next character could be any of the 26 alphabets - thus we need this many branches.
    bool isLeaf; // If this character represents the last character of a word in the Dictionary.

public:
    WordDictionary() {
        for(int i = 0; i < 26; i++) {
            branches[i] = NULL;
        }

        isLeaf = false;
    }

    ~WordDictionary() {
        for(int i = 0; i < 26; i++) {
            if(branches[i] != NULL) {
                delete branches[i];
            }
            branches[i] = NULL;
        }
    }
    
    void addWord(string word) {
        if(word == "") {
            isLeaf = true; // This is the last character of the inserted word.
            return; // Nothing more to add.
        }

        if(branches[word[0] - 'a'] == NULL) {
            branches[word[0] - 'a'] = new WordDictionary();
        }

        branches[word[0] - 'a'] -> addWord(word.substr(1, word.size() - 1));
    }
    
    bool search(string word) {
        if(word == "") {
            return isLeaf; // If this character represents the last character of a word that exists in the dictionary.
        }

        if(word[0] == '.') {
            for(int i = 0; i < 26; i++) {
                if(branches[i] != NULL) {
                    if(branches[i] -> search(word.substr(1, word.size() - 1))) {
                        return true;
                        // If the character is a '.' then the next character could be anything thus we explore all the words following from here.
                    }
                }
            }

            return false;  // No words matched.
        }

        if(branches[word[0] - 'a'] != NULL) {
            return (branches[word[0] - 'a'] -> search(word.substr(1, word.size() - 1)));
        }

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */