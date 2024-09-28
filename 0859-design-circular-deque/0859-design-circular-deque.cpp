class MyCircularDeque {
public:
    int maxer;
    deque<int> d;

    MyCircularDeque(int k) {
        maxer = k;
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;
        d.push_front(value);
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        d.push_back(value);
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        d.pop_front();
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        d.pop_back();
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return d.front();
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return d.back();
    }
    
    bool isEmpty() {
        return d.empty();
    }
    
    bool isFull() {
        return d.size() == maxer;
    }
};
