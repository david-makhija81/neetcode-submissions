// So, there is a data stream, the elements are being constantly pushed into our data structure.
// And once in a while or constantly they are querying about the median of the data that they pushed earlier.
// There can be multiple approaches to this, we can simply keep an array in which we insert the insert the element in a linear fashion and we maybe query it in a linear fashion as well.
// But can we decrease this time complexity? the answer lies in whether if we can decrease the insert and lookup time complexity.
// And the answer is yes we can - we can maybe store the data in a multiset where insertion complexity is some times even constant, but to fetch the middle element might take linear time as we might have to find the middle pointer.
// So to fix this, another approach which requires only O(1) lookup and O(log(N)) insertion is priority queues. But priority queues only serve the minimum or maximum element in them.
// But there is a workaround for this as well, we can keep 2 priority queues one that stores the minimum half elements and the other one that stores maximum half of the elements of the entire stream.
// And the two priority queues serve the maximum of the least half of the elements and the the minimum of largest half of the elements, this way we can easily fetch the median out of the stream.

class MedianFinder {
    priority_queue<int> firstHalf;
    priority_queue<int, vector<int>, greater<int>> secondHalf;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(firstHalf.empty() && secondHalf.empty()) {
            firstHalf.push(num);
            return;
        }

        if(secondHalf.empty()) {
            firstHalf.push(num);
            int top = firstHalf.top();
            firstHalf.pop();

            secondHalf.push(top);
            return;
        }

        if(firstHalf.size() == secondHalf.size()) {
            if(firstHalf.top() >= num) {
                firstHalf.push(num);
            } else {
                secondHalf.push(num);
                int median = secondHalf.top();
                secondHalf.pop();

                firstHalf.push(median);
            }
        } else {
            if(secondHalf.top() <= num) {
                secondHalf.push(num);
            } else {
                firstHalf.push(num);
                int median = firstHalf.top();
                firstHalf.pop();

                secondHalf.push(median);
            }
        }
    }
    
    double findMedian() {
        if(firstHalf.size() > secondHalf.size()) {
            return firstHalf.top();
        }

        double value1 = firstHalf.top();
        double value2 = secondHalf.top();

        return ((value1 + value2) / 2.0);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */