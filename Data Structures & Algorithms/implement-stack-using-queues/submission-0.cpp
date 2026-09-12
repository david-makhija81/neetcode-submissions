class MyStack {
    queue<int> q1;
    queue<int> q2;
    
public:
    //  first, my 1st thoughts are that. A stack is a last in and 1st out kind of data structure and a queue is a 1st and 1st out data structure. How, how do I implement a stack using, essentially a lasting for a 1st out data structure using to 1st in 1st out data structures?

    //  if, what I did was, that, I. stuffed the queue with  with the traffic that is coming my side, then, with the digits that are coming up to me, and then after that, when an element is asked for, I just reverse the order of the queue, and then return the front element. 
    // This way, I'll be essentially returning just the last pushed element into that data structure.
    // As the queue is a 1st and 1st out kind of data structure, but we need to push the last element in front of the queue so that whenever it is asked for, it can be faced from the front of the queue, what we can essentially do is that.

    // As an element comes to us, 1st we temporarily store the rest of the elements that were pushed earlier than this one, somewhere, and we push it into the main queue. After that, we have pushed this element into the main queue, this is the 1st element out of all the ones that we have encountered. till now.

    // This is the element that is last pushed, so it must be 1st popped out. Thus, we, uh, this is the 1st one that we uh, push into the main cue. After that, all the other elements are pushed into the queue, pushed into the main queue so that they are fetched after this one, the last element.

    // So whenever an element comes, 1st we temporarily store the previous element somewhere, uh, we 1st push this element into the queue, So that this is the 1st element that gets fetched, as compared to all the other elements, and this way the cycle goes on.
    
    MyStack() {
        
    }
    
    void push(int x) {
        if(q1.empty()) {
            q1.push(x);
            while(!q2.empty()) {
                int t = q2.front();
                q2.pop();
                q1.push(t);
            }
        } else {
            q2.push(x);
            while(!q1.empty()) {
                int t = q1.front();
                q1.pop();
                q2.push(t);
            }
        }
    }
    
    int pop() {
        int t = -1;
        if(!q1.empty()) {
            t = q1.front();
            q1.pop();
        } else {
            t = q2.front();
            q2.pop();
        }

        return t;
    }
    
    int top() {
        int t = -1;
        if(!q1.empty()) {
            t = q1.front();
        } else {
            t = q2.front();
        }

        return t;
    }
    
    bool empty() {
        return ((q1.empty()) && q2.empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */