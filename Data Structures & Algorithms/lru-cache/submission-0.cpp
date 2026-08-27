// So, we need to design a data structure that stores key value pairs. 
// We must be able to retrieve the value against a key and we must also update the recency of key usage.
// The key value pairing and retrieval of a value against a key is easy we can use hashing for that.
// But keeping track of what was the least used item is a bit tricky, I mean we can easily keep track of the most recently used item with a placeholder whenever an item is called for just update the placeholder.
// For least recently used we can maybe maintain an order among the keys used till now. 
// Whenever a key is get or put we push the key in front of the order this way the most recently used key is at the front of the order and because an element was used least recently it automatically gets pushed to tha back
// For example if I have a list of recently used elements like [1, 2, 3, 4] - now if I use key 4 the order becomes [4, 1, 2, 3] then after that if I use 3 the order becomes [3, 4, 1, 2] then I use 2 the order becomes [2, 3, 4, 1] and after that if I use 1 the order becomes [1, 2, 3, 4] as you can see altough 4 was put at the first position of the array later as other keys were used it got pushed to the end because it was the first to be used that is it was least recently used among all of them.
// As, we need to maintain a custom order of elements that is we want to govern where each element is placed.
// We can maybe use an array for that, but we need to do insertion and deletion operations as well, but insertion and deletion operations take linear time which might be expensive for us.
// Another structure that lets us govern the order is a linked list, in a linked list insertion at head that is in front of the order is O(1).
// But deletion still takes O(N) - I guess we can solve this problem but using doubly linked list.
// But even if we use doubly linked list it still takes linear time for lookup,
// To counter this we use a map that maps keys against Nodes and each node stores a value.

class LRUNode {
public:
    int val;
    int key;
    LRUNode* prev;
    LRUNode* next;

    LRUNode(int key_, int value) {
        val = value;
        key = key_;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
    unordered_map<int, LRUNode*> nodeMap;
    LRUNode* head;
    LRUNode* tail;
    int size;
    int length;

public:
    LRUCache(int capacity) {
        size = capacity;
        length = 0;
        head = NULL;
        tail = NULL;
    }
    
    int get(int key) {
        if(nodeMap.find(key) == nodeMap.end()) {
            return -1;
        }

        cout << nodeMap[key] -> val << endl;

        LRUNode* currNode = nodeMap[key];

        if(currNode == head) {
            return (head -> val);
        }

        if(currNode == tail) {
            tail -> prev -> next = NULL;
            tail = tail -> prev;
            currNode -> prev = NULL;
        } else {
            LRUNode* prv = currNode -> prev;
            LRUNode* nxt = currNode -> next;

            prv -> next = nxt;
            nxt -> prev = prv;

            currNode -> prev = NULL;
            currNode -> next = NULL;
        }

        currNode -> next = head;
        head -> prev = currNode;
        head = currNode;

        return (head -> val);
    }
    
    void put(int key, int value) {
        if(nodeMap.find(key) == nodeMap.end()) {
            length++;

            LRUNode* currNode = new LRUNode(key, value);

            if(head == NULL) {
                head = currNode;
                tail = currNode;
            } else {
                currNode -> next = head;
                head -> prev = currNode;
                head = currNode;
            }

            nodeMap.insert({key, currNode});

            if(length > size) {
                LRUNode* prvTail = tail;
                tail = tail -> prev;
                prvTail -> prev = NULL;

                nodeMap.erase(prvTail -> key);

                delete prvTail;

                length--;
            }

            return;
        }

        LRUNode* currNode = nodeMap[key];

        currNode -> val = value;

        if(currNode == head) {
            return;
        }

        if(currNode == tail) {
            tail -> prev -> next = NULL;
            tail = tail -> prev;
            currNode -> prev = NULL;
        } else {
            LRUNode* prv = currNode -> prev;
            LRUNode* nxt = currNode -> next;

            prv -> next = nxt;
            nxt -> prev = prv;

            currNode -> prev = NULL;
            currNode -> next = NULL;
        }

        currNode -> next = head;
        head -> prev = currNode;
        head = currNode;

        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */