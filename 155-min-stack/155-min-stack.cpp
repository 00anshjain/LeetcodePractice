class MinStack {
public:
    stack<int> ss;
    stack<int> s;
    MinStack() {
        // ss = new stack<int>;
        // s = new stack<int>;
    }
    
    void push(int a) {
        s.push(a);
            if(ss.empty())
        ss.push(a);
            else if(ss.top() >= a)
        ss.push(a);
    }
    
    void pop() {
        if(s.empty())
            return;
        int t = s.top();
        s.pop();
        if(t == ss.top())
            ss.pop();
        // return t;
    }
    
    int top() {
        if(s.empty())
            return -1;
        return s.top();
    }
    
    int getMin() {
        if(ss.empty())
	        return -1;
	    return ss.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */