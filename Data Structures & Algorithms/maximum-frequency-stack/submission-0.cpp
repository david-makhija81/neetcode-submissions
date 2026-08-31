// So, we need to keep track of the most frequent element at all times.
// Thus, we can keep a frequency map that maps an element to it's frequency.
// But, how do we query the element with most frequency at a time.
// We can store the frequency of each element in a container.
// Now, another problem pops up and that is how do we get the element with highest frequency.
// And update the frequency for each pop, we could have used a priority queue but priority queue gives the largest element lookup in O(1) time but if an element is pushed into the stack and we update the frequency of that element then the lookup for that element in the priority queue would cost us a lot operations.
// Thus, we need a structure that easily maps frequency to a value - in which the lookup for each frequency is O(1) and the frequency updation also takes lesser time.
// For this case we could have used an unordered_map of frequencies mapping to the values that have this frequencies - and multiple values can have the same frequency, thus, each frequency maps to a set of values.
// Instead of using an unordered_map let's use a vector of stacks and if a value is present in the ith stack then that value has at least this much frequency in the set values that we have.

class FreqStack {
    vector<stack<int>> freqMap;
    unordered_map<int, int> valMap;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        valMap[val]++;

        if(valMap[val] > freqMap.size()) {
            stack<int> values;

            freqMap.push_back(values);
        }

        freqMap[valMap[val] - 1].push(val);
    }
    
    int pop() {
        int ans = freqMap.back().top();
        freqMap.back().pop();

        valMap[ans]--;

        if(freqMap.back().empty()) {
            freqMap.pop_back();
        }

        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */