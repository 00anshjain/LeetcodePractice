class MinStack {
public:
    typedef long long ll;
    stack<long long> st;
    int mn;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty())
        {
            mn = val;
            st.push((ll)val);
        }
        else
        {
            if(val > mn)
                st.push(val);
            else// if(val <= mn)
            {
                st.push(2*(ll)val - mn);
                mn = val;
            }
        }
    }
    
    void pop() {
        if(st.empty())
            return;
        if(st.top() > mn)
        {
            st.pop();
        }
        else
        {
            int k = st.top();
            st.pop();
            mn = 2*(ll)mn - k;
        }
    }
    
    int top() {
        if(st.empty())
            return -1;
        if(st.top() < mn)
            return mn;
        return st.top();
    }
    
    int getMin() {
        if(st.empty())
            return -1;
        return mn;
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