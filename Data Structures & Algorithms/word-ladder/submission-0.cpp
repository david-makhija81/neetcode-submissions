class Solution {

    bool canTransform(string& word1, string& word2) {
        if(word1.size() != word2.size()) {
            return false;
        }

        int differences = 0;

        for(int i = 0; i < word1.size(); i++) {
            if(word1[i] != word2[i]) {
                differences++;
            }

            if(differences > 1) {
                return false;
            }
        }

        return (differences == 1) ? true : false;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // So, I am given a list of words and there is a rule that if I want to change a word then that word can only replace one of it's characters and even if it changes only one character the new must exist in the word list only then would we be able to make that change, And we have to figure out minimum number of changes we need to make in the beginWord so that it becomes the endWord.
        // It must guaranteed that beginWord and end word are there in the word list.
        // Does the word list contain any duplicates?
        // What we can do here is to map all the words to the list of words which this word can transform into by changing just one character
        // This way we get a graph of words where each edge denotes that the strings at the 2 ends of this edge can transform into each other just with one character change.
        // In this graph each path between 2 nodes represents if one string out of the 2 can transform into the other one and the number of edges in path represent the number of transformations needed.
        // Thus, we just need to find the minimum path between beginWord and endWord.

        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return false;
        }

        if(find(wordList.begin(), wordList.end(), beginWord) == wordList.end()) {
            wordList.push_back(beginWord);
        }

        vector<vector<int>> canTransformInto(wordList.size());
        int dest = -1;
        int src = -1;

        for(int i = 0; i < wordList.size(); i++) {
            for(int j = i + 1; j < wordList.size(); j++) {
                if(canTransform(wordList[i], wordList[j])) {
                    canTransformInto[i].push_back(j);
                    canTransformInto[j].push_back(i);
                }
            }

            if(wordList[i] == beginWord) {
                src = i;
            }
            if(wordList[i] == endWord) {
                dest = i;
            }
        }

        vector<int> minPath(wordList.size(), INT_MAX);
        queue<int> words;

        words.push(src);
        minPath[src] = 0;

        while(!words.empty()) {
            int currWord = words.front();
            words.pop();

            for(int nextWord: canTransformInto[currWord]) {
                cout << "Curr word is: " << wordList[currWord] << endl;
                cout << "Next word is: " << wordList[nextWord] << endl << endl;
                if(minPath[nextWord] > (minPath[currWord] + 1)) {
                    minPath[nextWord] = (minPath[currWord] + 1);
                    words.push(nextWord);
                }
            }
        }

        return (minPath[dest] == INT_MAX) ? 0 : (minPath[dest] + 1);
    }
};