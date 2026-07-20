class MyQueue {
public:
    stack<int> st1, st2; 
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(!st2.empty())
        {
            int val = st2.top();
            st2.pop();
            return val;
        }
        int n = st1.size();
        for(int i = 0; i < n; i++)
        {
            int val = st1.top();
            st1.pop();
            st2.push(val);
        }
        int val = st2.top();
        st2.pop();
        return val;
    }
    
    int peek() {
        if(!st2.empty())
        {
            return st2.top();
        }
        int n = st1.size();
        for(int i = 0; i < n; i++)
        {
            int val = st1.top();
            st1.pop();
            st2.push(val);
        }
        return st2.top();
    }
    
    bool empty() {
        return (st1.empty() && st2.empty());
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