class MyHashMap {

    int arr[1000001];

public:
    // so I have to design a hash map without any built-in libraries, right?
    // in a hash map, a key maps to a value, right?
    // and the key maps to the value in such a way that the look up on the key level only results in O(1) Time Complexity, right?
    // one strategy for O(1) time, look up, could be to have an array, we just store values, and what value to store at a position, we figure it out by Hashing the corresponding key so that each hash value is unique.
    // what do we return if the if the get method is called for for a specific key and there is no value against that key, what do we return then?

    MyHashMap() {
        for(int i = 0; i <= 1000000; i++) {
            arr[i] = -1;
        }
    }
    
    void put(int key, int value) {
        arr[key] = value;
    }
    
    int get(int key) {
        return arr[key];
    }
    
    void remove(int key) {
        arr[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */