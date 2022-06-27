class MyStack {
public:
    queue<int> q;
    int sz;
    MyStack() {
        sz = 0;
    }
    
    void push(int x) {
        queue<int> temp;
        for(int i = 0; i < sz; i++)
        {
            temp.push(q.front());
            q.pop();
        }
        q.push(x);
        while(!temp.empty())
        {
            q.push(temp.front());
            temp.pop();
        }
        sz++;
    }
    
    int pop() {
        if(sz == 0)
            return -1;
        int ans = q.front();
        q.pop();
        sz--;
        return ans;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
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