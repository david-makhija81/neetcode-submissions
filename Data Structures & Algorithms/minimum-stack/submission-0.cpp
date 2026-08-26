// Add 5 minutes to whatever the timer tells you.

// We need to design a min-stack from where we can retrieve the last element pushed as well as the min element pushed so far.
// The first part is the general functioning of a stack, so we do not need anything fancy for that.
// But, if I talk about tracking the minimum element this has issues as in a general sense we usually track the minimum by storing it in a placeholder but this poses a problem in our case as if the minimum element so far is popped/eliminated from the stack then how do we update the minimum element?
// Thus, it makes sense to keep 2 stacks one that stores the minimum element so far and one that stores the actual in order in which they were pushed earlier.

class MinStack {
    stack<int> standardStack;
    stack<int> miniStack;

public:
    MinStack() {
        
    }
    
    void push(int value) {
        standardStack.push(value);

        if((miniStack.empty()) || (miniStack.top() >= value)) {
            miniStack.push(value);
        }
    }
    
    void pop() {
        if(miniStack.top() == standardStack.top()) {
            miniStack.pop();
        }

        standardStack.pop();
    }
    
    int top() {
        return standardStack.top();
    }
    
    int getMin() {
        return miniStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */