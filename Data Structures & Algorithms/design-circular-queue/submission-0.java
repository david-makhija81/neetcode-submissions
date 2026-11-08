class MyCircularQueue {
    private int capacity;
    private int size;
    private int[] queue;
    private int front;
    private int rear;

    public MyCircularQueue(int k) {
        capacity = k;
        queue = new int[k];
        size = 0;
        front = 0;
        rear = k - 1;
    }
    
    public boolean enQueue(int value) {
        if (size == capacity) {
            return false;
        }

        queue[(rear + 1) % capacity] = value;
        rear = (rear + 1) % capacity;
        size++;

        return true;
    }
    
    public boolean deQueue() {
        if (size == 0) {
            return false;
        }

        front = (front + 1) % capacity;
        size--;

        return true;
    }
    
    public int Front() {
        if (size == 0) {
            return -1;
        }

        return queue[front];
    }
    
    public int Rear() {
        if (size == 0) {
            return -1;
        }

        return queue[rear];
    }
    
    public boolean isEmpty() {
        return (size == 0);
    }
    
    public boolean isFull() {
        return (size == capacity);
    }
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * boolean param_1 = obj.enQueue(value);
 * boolean param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * boolean param_5 = obj.isEmpty();
 * boolean param_6 = obj.isFull();
 */