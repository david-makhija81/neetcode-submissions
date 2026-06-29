class Trie{
    Trie* branch[26];
    bool isLeaf;
public:
    Trie() {
        for(int i = 0; i < 26; i++) {
            branch[i] = NULL;
        }

        isLeaf = false;
    }

    ~Trie() {
        for(int i = 0; i < 26; i++) {
            if(branch[i]) {
                delete branch[i];
            }
            branch[i] = NULL;
        }
    }

    void addWord(string word) {
        if(word.size() == 0) {
            isLeaf = true;
            return;
        }

        if(branch[word[0] - 'a'] == NULL) {
            branch[word[0] - 'a'] = new Trie();
        }

        branch[word[0] - 'a'] -> addWord(word.substr(1, word.size() - 1));
    }

    bool search(string word) {
        if(word.size() == 0) {
            return isLeaf;
        }

        if(word[0] == '.') {
            for(int i = 0; i < 26; i++) {
                if((branch[i] != NULL) && (branch[i] -> search(word.substr(1, word.size() - 1)))) {
                    return true;
                }
            }

            return false;
        }

        if(branch[word[0] - 'a'] == NULL) {
            return false;
        }

        return branch[word[0] - 'a'] -> search(word.substr(1, word.size() - 1));
    }
};

class WordDictionary {
    Trie* root;
public:
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        root -> addWord(word);
    }
    
    bool search(string word) {
        return (root -> search(word));
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */