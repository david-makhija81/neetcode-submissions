class MyHashSet {
// so the functions of a hash set are if I get let's say n numbers then I must be able to and if those n numbers are distinct I must be able to keep track of those n numbers and I must be able to keep track of those n numbers and if someone inquires if I have those numbers or not, I could I must be able to inquire that in O of 1 time.
// one can store these elements in any data structure whatsoever. Even a simple array could work. But the condition that lookup of any element must be O makes the problem kind of tricky.
// in a normal array, we can do the lookup with the index in o of 1, but if we have to find a certain element in the array, it might take o of n.
// as index can give us O of 1 lookup time complexity, thus it makes sense to make the element as the index of the structure we are using. And at each index we'll store if the index element is in the structure or not.
// in the worst case it might happen that the maximum element, the maximum index per se, is greater than the number of elements that can fit into an array and thus we might take up a lot of wasted space complexity. Thus we must introduce a hash set which converts an index into a smaller number which fits into the range of our array length.

vector<bool> numSet;

public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(key >= numSet.size()) {
            for(int i = numSet.size(); i <= key; i++) {
                numSet.push_back(false);
            }
        }

        numSet[key] = true;
    }
    
    void remove(int key) {
        if(key >= numSet.size()) {
            return;
        }

        numSet[key] = false;
    }
    
    bool contains(int key) {
        if(key >= numSet.size()) {
            return false;
        }

        return numSet[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */