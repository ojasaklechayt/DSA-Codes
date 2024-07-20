class MyQueue {
private:
    deque<int> qt;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        qt.push_back(x);     
    }
    
    int pop() {
        int front = qt.front();
        qt.pop_front();
        return front;
    }
    
    int peek() {
        return qt.front();
    }
    
    bool empty() {
        return qt.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */