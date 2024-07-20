class MyStack {
private:
    vector<int> st;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        st.push_back(x);
    }
    
    int pop() {
        int back = st.back();
        st.pop_back();
        return back;
    }
    
    int top() {
        return st.back();
    }
    
    bool empty() {
        return st.size()==0;
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