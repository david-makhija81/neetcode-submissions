class PrefixTree {
    PrefixTree* characterBranch[26];
    bool isLeaf;

public:
    PrefixTree() {
        for(int i = 0; i < 26; i++) {
            characterBranch[i] = NULL;
        }

        isLeaf = false;
    }
    
    void insert(string word) {
        if(word.size() == 0) {
            isLeaf = true;

            return;
        }

        if(characterBranch[word[0] - 'a'] == NULL) {
            characterBranch[word[0] - 'a'] = new PrefixTree();
        }

        characterBranch[word[0] - 'a'] -> insert(word.substr(1, word.size() - 1));
    }
    
    bool search(string word) {
        if(word.size() == 0) {
            return isLeaf;
        }

        if(characterBranch[word[0] - 'a'] == NULL) {
            return false;
        }

        return characterBranch[word[0] - 'a'] -> search(word.substr(1, word.size() - 1));
    }
    
    bool startsWith(string prefix) {
        if(prefix.size() == 0) {
            return true;
        }

        if(characterBranch[prefix[0] - 'a'] == NULL) {
            return false;
        }

        return characterBranch[prefix[0] - 'a'] -> startsWith(prefix.substr(1, prefix.size() - 1));
    }
};
